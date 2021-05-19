#pragma once

// #include <string>
#include "Game.h"
#include "Vector2D.h"

class GameObject {
public:
    Vector2D position;
    Vector2D velocity;

    SDL_Rect collider;
    SDL_Rect tileRect;
    int tileID;
    std::string path;

    SDL_Rect srcRect, destRect;

    int speed = 3;
    int height = 32;
    int width = 32;
    int scale = 1;

    bool animated = false;
    int frames = 4;
    int frame_speed = 200;

    GameObject();
    GameObject(int sc);
    GameObject(const char* texturesheet, int x, int y, bool animated);
    GameObject(const char* texturesheet, int x, int y, int h, int w, int sc);
    GameObject(const char* texturesheet, int x, int y, int h, int w, int sc, int id);
    ~GameObject();

    void update();
    void render();
    int getX();
    int getY();
    Vector2D getPosition();
    void setTex(const char* path);

private:
    SDL_Texture* objTexture;
};