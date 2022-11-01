#include <stdlib.h>
#include <iostream>

#include <SDL2/SDL.h>

#include "game/Game.hpp"
#include "game/Player.hpp"
#include "game/MainMenu.hpp"
#include "game/Dropper.hpp"
#include "game/Background.hpp"

Game::Game() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    if (TTF_Init() < 0) {
        std::cerr << "Failed to initialize SDL_ttf: " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    this->win = SDL_CreateWindow("Game",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1280, 720,
        0
    );

    if (this->win == nullptr) {
        std::cerr << "Failed to create a window: " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    this->running = false;
    this->objects.push_back(new Background());
    this->objects.push_back(new Player());
    this->objects.push_back(new MainMenu());
    this->objects.push_back(new Dropper());
}

void Game::Run() {
    std::cout << "Entering main loop..." << std::endl;
    this->running = true;

    for (GameObject* objPtr : this->objects) {
        objPtr->Initialize(this->ren, this->win);
    }

    while (this->running) {
        Uint64 start = SDL_GetPerformanceCounter();
        for (GameObject* objPtr : this->objects) {
            objPtr->Update(this->win);
        }
        SDL_Event ev;
        while (SDL_PollEvent(&ev)) {
            switch (ev.type) {
                case SDL_QUIT:
                    this->running = false;
                    break;
            }
            for (GameObject* objPtr : this->objects) {
                objPtr->HandleEvent(ev);
            }
        }

        SDL_RenderClear(this->ren);
        for (GameObject* objPtr : this->objects) {
            objPtr->Draw(this->ren);
        }
        SDL_RenderPresent(this->ren);
        Uint64 end = SDL_GetPerformanceCounter();
        float elapsed = (end - start) / (float)SDL_GetPerformanceCounter() * 1000.0f;
        // cap to 60 fps so that my wonky physics system doesnt fucking die
        SDL_Delay(floor(16.666f - elapsed));
    }
}

Game::~Game() {
    for (GameObject* objPtr : this->objects) {
        delete objPtr;
    }
    this->objects.clear();

    SDL_DestroyRenderer(this->ren);
    SDL_DestroyWindow(this->win);
    TTF_Quit();
    SDL_Quit();
}