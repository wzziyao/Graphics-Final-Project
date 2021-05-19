#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject() {
    position.Zero();
}

GameObject::GameObject(int sc) {
    position.Zero();
    scale = sc;
}

GameObject::GameObject(const char* texturesheet, int x, int y) {
    objTexture = TextureManager::LoadTexture(texturesheet);
    position.x = x;
    position.y = y;
    velocity.Zero();
}

GameObject::GameObject(const char* texturesheet, int x, int y, int h, int w, int sc) {
    objTexture = TextureManager::LoadTexture(texturesheet);
    position.x = x;
    position.y = y;
    velocity.Zero();
    height = h;
    width = w;
    scale = sc;
}

void GameObject::update() {
    position.x += velocity.x * speed;
    position.y += velocity.y * speed;

    srcRect.w = width;
    srcRect.h = height;
    srcRect.x = srcRect.y = 0;

    destRect.x = static_cast<int>(position.x);
    destRect.y = static_cast<int>(position.y);

    destRect.w = width * scale;
    destRect.h = height * scale; 

    collider.x = position.x;
    collider.y = position.y;
    collider.w = width * scale;
    collider.h = height * scale;
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