#pragma once

#include <string>
#include <map>

#include <SDL2/SDL_ttf.h>

#include "game/Vector2.hpp"
#include "game/DrawableTextInformation.hpp"

class Font {
    public:
        Font(std::string name);
        void Draw(std::string text, SDL_Color color, Vector2* pos, SDL_Renderer* ren);
        int QueryTextLength(std::string text);
        ~Font();
    private:
        TTF_Font* font;
        std::map<std::string, DrawableTextInformation> cachedText;
};