#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, int x, int y) {
    objTexture = TextureManager::LoadTexture(texturesheet);
    position.x = x;
    position.y = y;
}

void GameObject::update() {
    // position.x++;
    // position.y++;

    srcRect.w = 32;
    srcRect.h = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = (int)position.x;
    destRect.y = (int)position.y;

    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2; 
}

int GameObject::getX() {
    return position.x;
}

int GameObject::getY() {
    return position.y;
}

Vector2D GameObject::getPosition() {
    return position;
}

void GameObject::setTex(const char* newpath) {
    objTexture = TextureManager::LoadTexture(newpath);
}

void GameObject::render() {
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}