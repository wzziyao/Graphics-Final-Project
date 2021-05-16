#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

using namespace std;

// SDL_Texture* playerTex;
// SDL_Rect srcR, destR;

GameObject* player;

Game::Game() {}

Game::~Game() {}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        cout << "Subsystems initialized!" << endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window) {
            cout << "Window created!" << endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            cout << "Renderer created!" << endl;
        }
        isRunning = true;
    } else {
        isRunning = false;
    }

    // SDL_Surface* tmpSurface = IMG_Load("assets/test_png.png");
    // playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    // SDL_FreeSurface(tmpSurface);

    // playerTex = TextureManager::LoadTexture("assets/test_png.png", renderer);

    player = new GameObject("assets/test_png.png", renderer, 0, 0);
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update() {
    // count++;
    // destR.h = 64;
    // destR.w = 64;
    // destR.x = count;
    // cout << count << endl;
    player->update();
}

void Game::render() {
    SDL_RenderClear(renderer);
    // things to render
    // SDL_RenderCopy(renderer, playerTex, NULL, &destR);
    player->render();
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game cleaned!" << endl;
}