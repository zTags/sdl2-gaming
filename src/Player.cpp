#include <iostream>

#include <SDL2/SDL.h>

#include "game/Player.hpp"
#include "game/Constants.hpp"

Player::Player() {
    // initial code here
    this->accel = 0;
    this->x = 0;
    this->y = 0;
    this->leftkeydown = false;
    this->rightkeydown = false;
    this->jumpkeydown = false;
    this->freezephysics = false;
    this->freezephysicscounter = 0;
}

void Player::Initialize(SDL_Renderer* ren, SDL_Window* win) {
    // load in the player sprite
    this->spr = new Sprite(ren, "hello");
    int x, y = 0;
    SDL_GetWindowSize(win, &x, &y);
    this->x = (x / 2) - (25 / 2);
    this->y = -14;
}

void Player::Update(SDL_Window* win) {
    int winwidth, winheight = 0;
    SDL_GetWindowSize(win, &winwidth, &winheight);
    if (!this->freezephysics){
        this->accel += GRAVITY;
        if (this->accel > MAXACCEL) {
            this->accel = MAXACCEL;
        }
        this->y += this->accel;
    }

    if (this->leftkeydown) {
        this->x -= SPEED;
    }
    if (this->rightkeydown) {
      	this->x += SPEED;
    }

    if (this->freezephysicscounter != 0) {
        this->freezephysicscounter--;
        if (this->freezephysicscounter == 0) {
            this->freezephysics = false;
            this->jumping = false;
        }
    }

    if (this->jumping) {
        int advanceby = JUMPHEIGHT / TIMETOJUMP;
        this->y -= advanceby;
    }

    if (this->y > winheight - this->spr->GetSize()->GetY()) {
        this->y = winheight - this->spr->GetSize()->GetY();
        this->accel = 0;
    }

    if (this->x < 0) {
        this->x = 0;
    }
    if (this->x > winwidth - this->spr->GetSize()->GetX()) {
        this->x = winwidth - this->spr->GetSize()->GetX();
    }

    if (this->jumpkeydown && this->y == winheight - this->spr->GetSize()->GetY()) {
        this->Jump();
    }

    if (this->y == -14) {
        this->Jump();
    }

    GameObject::GetGameState()->playerx = this->x;
    GameObject::GetGameState()->playery = this->y;
}

void Player::HandleEvent(SDL_Event e) {
    if (e.type == SDL_KEYDOWN) {
        if (e.key.keysym.scancode == SDL_SCANCODE_LEFT) {
            this->leftkeydown = true;
        }
        if (e.key.keysym.scancode == SDL_SCANCODE_RIGHT) {
            this->rightkeydown = true;
        }
        if (
            e.key.keysym.scancode == SDL_SCANCODE_SPACE ||
            e.key.keysym.scancode == SDL_SCANCODE_UP
        ) {
            this->jumpkeydown = true;
        }
    }

    if (e.type == SDL_KEYUP) {
        if (e.key.keysym.scancode == SDL_SCANCODE_LEFT) {
            this->leftkeydown = false;
        }
        if (e.key.keysym.scancode == SDL_SCANCODE_RIGHT) {
            this->rightkeydown = false;
        }        
        if (
            e.key.keysym.scancode == SDL_SCANCODE_SPACE ||
            e.key.keysym.scancode == SDL_SCANCODE_UP
        ) {
            this->jumpkeydown = false;
        }
    }
}

void Player::Draw(SDL_Renderer* ren) {
    this->spr->Move(new Vector2(this->x, this->y));
    this->spr->Draw(ren);
}

void Player::Jump() {
    this->freezephysics = true;
    this->freezephysicscounter = TIMETOJUMP;
    this->jumping = true;
}

Player::~Player() {
    delete this->spr;
}