#include <SDL2/SDL.h>

#include "game/MainMenu.hpp"
#include "game/Vector2.hpp"
#include "game/Font.hpp"

#define WELCOME_TEXT "Welcome to my epic game!"
#define START_TEXT "Press space to start"
#define GAMEOVER_TEXT "GAME OVER!"
#define GAMEOVER_SUB_TEXT "Press space to retry"

MainMenu::MainMenu() {

}

void MainMenu::Initialize(SDL_Renderer* ren, SDL_Window* win) {
    this->font = new Font("PressStart2P");
    this->welcomeTextWidth = this->font->QueryTextLength(WELCOME_TEXT);
    this->startTextWidth = this->font->QueryTextLength(START_TEXT);
    this->gameoverTextWidth = this->font->QueryTextLength(GAMEOVER_TEXT);
    this->gameoverSubTextWidth = this->font->QueryTextLength(GAMEOVER_SUB_TEXT);
    int w, h;
    SDL_GetWindowSize(win, &w, &h);
    this->winheight = h;
    this->winwidth = w;
}

void MainMenu::Update(SDL_Window* win) {

}

void MainMenu::HandleEvent(SDL_Event ev) {
    if (ev.type == SDL_KEYUP) {
        if (ev.key.keysym.scancode == SDL_SCANCODE_SPACE) {
            if (GameObject::GetGameState()->gamestate == 0) {
                GameObject::GetGameState()->gamestate = 1;
            }
            if (GameObject::GetGameState()->gamestate == 2) {
                GameObject::GetGameState()->gamestate = 3;
            }
        }
    }
}

void MainMenu::Draw(SDL_Renderer* ren) {
    if (GameObject::GetGameState()->gamestate == 0) {
        SDL_Color col = { 255, 255, 255 };
        Vector2* pos = new Vector2( this->winwidth / 2 - this->welcomeTextWidth / 2, 50);
        Vector2* pos2 = new Vector2( this->winwidth / 2 - this->startTextWidth / 2, 150);
        this->font->Draw(WELCOME_TEXT, col, pos, ren);
        this->font->Draw(START_TEXT, col, pos2, ren);
        delete pos;
        delete pos2;
    }

    if (GameObject::GetGameState()->gamestate == 2) {
        SDL_Color col = { 255, 255, 255 };
        Vector2* pos = new Vector2( this->winwidth / 2 - this->gameoverTextWidth / 2, 50);
        Vector2* pos2 = new Vector2( this->winwidth / 2 - this->gameoverSubTextWidth / 2, 150);
        this->font->Draw(GAMEOVER_TEXT, col, pos, ren);
        this->font->Draw(GAMEOVER_SUB_TEXT, col, pos2, ren);
        delete pos;
        delete pos2;
    }
}

MainMenu::~MainMenu() {
    delete this->font;
}