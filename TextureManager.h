#pragma once

#include <SDL2/SDL_image.h>
#include "Game.h"

class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char* texture);
    static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};