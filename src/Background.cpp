#include "game/Background.hpp"

Background::Background() {
    this->index = 0;
    this->timer = 600;

    colors.push_back({ 222, 95, 95 });
    colors.push_back({ 222, 167, 95 });
    colors.push_back({ 209, 222, 95 });
    colors.push_back({ 144, 222, 95 });
    colors.push_back({ 95, 222, 101 });
    colors.push_back({ 95, 222, 188 });
    colors.push_back({ 95, 169, 222 });
    colors.push_back({ 103, 95, 222 });
    colors.push_back({ 175, 95, 222 });
    colors.push_back({ 222, 95, 199 });
    colors.push_back({ 222, 95, 127 });
}

void Background::Initialize(SDL_Renderer* ren, SDL_Window* win) {

}

void Background::Update(SDL_Window* win) {
    this->timer--;
    if (this->timer == 0) {
        this->timer = 600;
        this->index++;
    }

    if (this->index == this->colors.size()) {
        this->index = 0;
    }
}

void Background::HandleEvent(SDL_Event ev) {

}

void Background::Draw(SDL_Renderer* ren) {
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = 1280;
    rect.h = 720;

    SDL_SetRenderDrawColor(ren, 
        this->colors[this->index].r,
        this->colors[this->index].g,
        this->colors[this->index].b,
        255
    );
    SDL_RenderDrawRect(ren, &rect);
}

Background::~Background() {

}