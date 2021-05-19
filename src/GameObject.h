#pragma once

// #include <string>
#include "Game.h"
#include "Vector2D.h"
#include "Animation.h"
#include <map>

class GameObject {
public:
    Vector2D position;
    Vector2D velocity;

    SDL_Rect collider;
    SDL_Rect tileRect;
    int tileID;
    std::string path;

    SDL_Rect srcRect, destRect;

    // basic parameters
    int speed = 3;
    int height = 32;
    int width = 32;
    int scale = 1;

    // sprite animation
    bool animated = false;
    int frames = 3;
    int frame_speed = 200;

    // multiple animations
    bool multipleAnim = false;
    int animIndex = 0;
    std::map<const char*, Animation> animations;
    SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

    GameObject();
    GameObject(int sc);
    GameObject(const char* texturesheet, int x, int y, bool animated, bool multipleAnim);
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