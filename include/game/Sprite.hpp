#pragma once

#include <string>

#include <SDL2/SDL.h>

#include "game/Vector2.hpp"

class Sprite {
    public:
        Sprite(SDL_Renderer* renderer, std::string name);
        
        void Draw(SDL_Renderer* renderer);
        void Move(Vector2* pos);
        Vector2* GetSize();
        
        ~Sprite();
    private:
        SDL_Texture* txt;
        Vector2* pos;
        int width, height;
        SDL_Rect drawRect;
};