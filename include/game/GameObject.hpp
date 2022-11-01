#pragma once

#include <SDL2/SDL.h>

#include "game/GameState.hpp"

class GameObject {
    public:
        GameObject();
        virtual void Initialize(SDL_Renderer* ren, SDL_Window* win);
        virtual void Update(SDL_Window* win);
        virtual void HandleEvent(SDL_Event ev);
        virtual void Draw(SDL_Renderer* ren);
        static GameState* GetGameState();
        ~GameObject();
    private:
        static inline GameState gs = DefaultGameState();

};