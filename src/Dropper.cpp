#include "game/Dropper.hpp"

#include <iostream>
#include <format>
#include <SDL2/SDL.h>

Dropper::Dropper() {
    this->frequency = 60;
    this->speed = 5;
    this->timer = this->frequency;
    this->points = 1;
}

void Dropper::Initialize(SDL_Renderer* ren, SDL_Window* win) {
    this->drop = new Sprite(ren, "drop");
    int w, h;
    SDL_GetWindowSize(win, &w, &h);
    this->winheight = h;
    this->scoreDisplayFont = new Font("PressStart2P");
}

void Dropper::Update(SDL_Window* win) {
    if (GameObject::GetGameState()->gamestate == 3) {
        this->points = 1;
        GameObject::GetGameState()->gamestate = 1;
    }

    if (GameObject::GetGameState()->gamestate == 1) {
        this->timer--;
        if (this->timer == 0) {
            this->timer = this->frequency;
            std::uniform_int_distribution<int> range(0, this->winheight);
            int x = range(this->rng);
            Drop d;
            d.x = x;
            d.y = 0; 
            this->drops.push_back(d);
        }
    }
    for (int i = 0; i < this->drops.size(); i++) {
        SDL_Rect r;
        r.x = this->drops[i].x;
        r.y = this->drops[i].y;
        r.w = 50;
        r.h = 50;

        SDL_Rect plr;
        plr.x = GameObject::GetGameState()->playerx;
        plr.y = GameObject::GetGameState()->playery;
        plr.w = 50;
        plr.h = 50;

        if (SDL_HasIntersection(&plr, &r)) {
            this->drops.erase(this->drops.begin() + i);
            this->points++;
        }
        
        this->drops[i].y += this->speed;

        if (this->drops[i].y >= this->winheight) {
            this->drops.erase(this->drops.begin() + i);
            this->points--;
        }
    }

    if (this->points == 0) {
        GameObject::GetGameState()->gamestate = 2;
        this->drops.clear();
    }
}

void Dropper::HandleEvent(SDL_Event ev) {

}

void Dropper::Draw(SDL_Renderer* ren) {
    for (Drop d : this->drops) {
        Vector2* pos = new Vector2(d.x, d.y);
        this->drop->Move(pos);
        this->drop->Draw(ren);
    }
    if (GameObject::GetGameState()->gamestate == 1) {
        SDL_Color col = { 255, 255, 255 };
        Vector2* pos = new Vector2(25, 25);
        std::string s = std::format("Score: {}", this->points);
        this->scoreDisplayFont->Draw(s, col, pos, ren);
    }
}

Dropper::~Dropper() {
    delete this->drop;
}