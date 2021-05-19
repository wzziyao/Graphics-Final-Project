#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject() {
    position.Zero();
}

GameObject::GameObject(int sc) {
    position.Zero();
    scale = sc;
}

GameObject::GameObject(const char* texturesheet, int x, int y, bool is_player) {
    animated = is_player;
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

GameObject::GameObject(const char* texturesheet, int x, int y, int h, int w, int sc, int id) {
    objTexture = TextureManager::LoadTexture(texturesheet);
    position.x = x;
    position.y = y;
    velocity.Zero();
    height = h;
    width = w;
    scale = sc;
    tileID = id;

    switch (tileID) {
    case 0:
        path = "assets/water.png";
        break;
    case 1:
        path = "assets/dirt.png";
        break;
    case 2:
        path = "assets/grass.png";
        break;
    default:
        break;
    }
}

void GameObject::update() {
    position.x += velocity.x * speed;
    position.y += velocity.y * speed;

    srcRect.w = width;
    srcRect.h = height;
    // srcRect.x = srcRect.y = 0;
    srcRect.y = 0;

    if (animated) {
        srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / 100) % frames);
    }

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

GameObject::~GameObject() {}