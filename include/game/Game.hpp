#pragma once

#include <SDL2/SDL.h>
#include <vector>

#include "game/Sprite.hpp"
#include "game/GameObject.hpp"

class Game {
    public:
        Game();

        void Run();

        ~Game();
    private:
        bool running;
        SDL_Renderer* ren;
        SDL_Window* win;
        std::vector<GameObject*> objects;
};