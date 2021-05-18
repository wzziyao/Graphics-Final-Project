#pragma once

#include "Game.h"
#include "Vector2D.h"

class GameObject {
public:
    Vector2D position;

    GameObject(const char* texturesheet, int x, int y);
    ~GameObject();

    void update();
    void render();
    int getX();
    int getY();
    Vector2D getPosition();
    void setTex(const char* path);

private:
    // int xpos;
    // int ypos;

    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
};