#pragma once

#include "Game.h"

class Map {
public: 
    Map();
    ~Map();
    SDL_Rect src, dest;

    void LoadMap(int arr[20][25]);
    void DrawMap();
private:
    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;

    int map[20][25];
};