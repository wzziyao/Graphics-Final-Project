#include <iostream>
#include <SDL2/SDL.h>

#include "Game.hpp"

using namespace std;

Game *game = nullptr;

int main(int argc, const char * argv[]) {
    game = new Game();

    game->init("MyGameEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    while (game->running()) {
        game->handleEvents();
        game->update();
        game->render();
    }
    game->clean();

    // SDL_Init(SDL_INIT_VIDEO);
    
    // SDL_Window *window = SDL_CreateWindow("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

    // SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    // SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    // SDL_RenderClear(renderer);

    // SDL_RenderPresent(renderer);

    // bool is_running = true;
    // SDL_Event event;
    // while (is_running) {
    //     while (SDL_PollEvent(&event)) {
    //         if (event.type == SDL_QUIT) {
    //             is_running = false;
    //         }
    //     }
    //     SDL_Delay(16);
    // }
    return 0;
}