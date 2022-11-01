#include <string>
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "game/Sprite.hpp"
#include "game/Vector2.hpp"

Sprite::Sprite(SDL_Renderer* ren, std::string name) {
    std::string fullPath = "assets/" + name + ".png";
    this->txt = IMG_LoadTexture(ren, fullPath.c_str());
    this->pos = new Vector2(0, 0);
    int w, h = 0;
    SDL_QueryTexture(this->txt, nullptr, nullptr, &w, &h);
    this->width = w;
    this->height = h;
    this->drawRect.x = pos->GetX();
    this->drawRect.y = pos->GetY();
    this->drawRect.w = w;
    this->drawRect.h = h;
}

void Sprite::Draw(SDL_Renderer* ren) {
    SDL_RenderCopy(ren, this->txt, nullptr, &this->drawRect);
}

void Sprite::Move(Vector2* vec) {
    this->pos = vec;
    int w, h = 0;
    SDL_QueryTexture(this->txt, nullptr, nullptr, &w, &h);
    this->width = w;
    this->height = h;
    this->drawRect.x = pos->GetX();
    this->drawRect.y = pos->GetY();
    this->drawRect.w = w;
    this->drawRect.h = h;
}

Vector2* Sprite::GetSize() {
    return new Vector2(this->drawRect.w, this->drawRect.h);
}

Sprite::~Sprite() {
    SDL_DestroyTexture(this->txt);
    delete this->pos;
}