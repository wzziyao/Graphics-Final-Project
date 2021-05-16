#pragma once

#include <SDL2/SDL_image.h>

class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char* texture, SDL_Renderer* ren);
};