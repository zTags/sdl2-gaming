#include "game/GameObject.hpp"

GameObject::GameObject() { }
void GameObject::Initialize(SDL_Renderer* ren, SDL_Window* win) { }
void GameObject::Update(SDL_Window* win) { }
void GameObject::HandleEvent(SDL_Event ev) { }
void GameObject::Draw(SDL_Renderer* ren) { }
GameObject::~GameObject() { }

GameState* GameObject::GetGameState() {
    return &GameObject::gs;
}