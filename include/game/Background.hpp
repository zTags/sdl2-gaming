#pragma once

#include <vector>

#include "game/GameObject.hpp"
#include "game/Font.hpp"

class Background : public GameObject {
    public:
        Background();
        void Initialize(SDL_Renderer* ren, SDL_Window* win);
        void Update(SDL_Window* win);
        void HandleEvent(SDL_Event ev);
        void Draw(SDL_Renderer* ren);
        ~Background();
    private:
        int index;
        int timer;
        int y;
        std::vector<SDL_Color> colors;
};