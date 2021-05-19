#pragma once

#include "Game.h"
#include "Vector2D.h"

class GameObject {
public:
    Vector2D position;
    Vector2D velocity;

    SDL_Rect collider;

    int speed = 3;
    int height = 32;
    int width = 32;
    int scale = 1;

    GameObject();
    GameObject(int sc);
    GameObject(const char* texturesheet, int x, int y);
    GameObject(const char* texturesheet, int x, int y, int h, int w, int sc);
    ~GameObject();

    void update();
    void render();
    int getX();
    int getY();
    Vector2D getPosition();
    void setTex(const char* path);

private:
    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
};