#include "game/Font.hpp"
#include "game/Vector2.hpp"

Font::Font(std::string name) {
    std::string path = "assets/" + name + ".ttf";
    this->font = TTF_OpenFont(path.c_str(), 32);
}

void Font::Draw(std::string text, SDL_Color col, Vector2* pos, SDL_Renderer* ren) {
    if (this->cachedText.count(text)) {
        SDL_RenderCopy(ren, this->cachedText[text].text, nullptr, &this->cachedText[text].rect);
        return;
    }

    SDL_Surface* textSurface = TTF_RenderText_Solid(this->font, text.c_str(), col);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(ren, textSurface);
    int width = textSurface->w;
    int height = textSurface->h;
    SDL_FreeSurface(textSurface);
    SDL_Rect r;
    r.x = pos->GetX();
    r.y = pos->GetY();
    r.w = width;
    r.h = height;

    DrawableTextInformation dti;
    dti.rect = r;
    dti.text = textTexture;
    this->cachedText[text] = dti;

    SDL_RenderCopy(ren, textTexture, NULL, &r);

    // make sure we dont create a stupid amount of textures
    if (this->cachedText.size() > 10) {
        this->cachedText.erase(this->cachedText.begin());
    }
}

int Font::QueryTextLength(std::string str) {
    SDL_Color col = { 255, 255, 255 };
    SDL_Surface* surf = TTF_RenderText_Solid(this->font, str.c_str(), col);
    return surf->w;
}

Font::~Font() {
    TTF_CloseFont(this->font);
}