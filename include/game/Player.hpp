#pragma once

#include "game/GameObject.hpp"
#include "game/Sprite.hpp"

class Player : public GameObject {
    public:
        Player();
        void Initialize(SDL_Renderer* ren, SDL_Window* win);
        void Update(SDL_Window* win);
        void HandleEvent(SDL_Event ev);
        void Draw(SDL_Renderer* ren);
        void Jump();
        ~Player();
    private:
        Sprite* spr;
        int accel;
        int x;
        int y;
        bool leftkeydown;
        bool rightkeydown;
        bool jumpkeydown;
        bool freezephysics;
        bool jumping;
        int freezephysicscounter;
};