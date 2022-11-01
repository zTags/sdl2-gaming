#pragma once

#include <vector>
#include <random>

#include "game/GameObject.hpp"
#include "game/Sprite.hpp"
#include "game/Drop.hpp"
#include "game/Font.hpp"

class Dropper : public GameObject {
    public:
        Dropper();
        void Initialize(SDL_Renderer* ren, SDL_Window* win);
        void Update(SDL_Window* win);
        void HandleEvent(SDL_Event ev);
        void Draw(SDL_Renderer* ren);
        ~Dropper();
    private:
        Sprite* drop;
        std::vector<Drop> drops;
        int frequency;
        int speed;
        int timer;
        int winheight;
        int points;
        std::default_random_engine rng;
        Font* scoreDisplayFont;
};