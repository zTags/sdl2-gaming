#pragma once

#include "game/GameObject.hpp"
#include "game/Font.hpp"

class MainMenu : public GameObject {
    public:
        MainMenu();
        void Initialize(SDL_Renderer* ren, SDL_Window* win);
        void Update(SDL_Window* win);
        void HandleEvent(SDL_Event ev);
        void Draw(SDL_Renderer* ren);
        ~MainMenu();
    private:
        Font* font;
        int winwidth;
        int winheight;
        int welcomeTextWidth;
        int startTextWidth;  
        int gameoverTextWidth;
        int gameoverSubTextWidth;    
};