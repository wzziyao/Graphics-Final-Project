#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "Collision.h"

using namespace std;

GameObject* player;
GameObject* wall;

Map* map;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

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

    player = new GameObject("assets/test_png.png", 100, 100);
    wall = new GameObject("assets/dirt.png", 300, 300, 300, 20, 1);

    map = new Map();
}

void Game::handleEvents() {
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
    player->update();
    wall->update();

    if (Collision::AABB(player->collider, wall->collider)) {
        player->velocity * (-1);
        std::cout << "Wall Hit!" << std::endl;
    }

    // player->position.Add(Vector2D(5, 0));
    if (Game::event.type == SDL_KEYDOWN) {
        switch (Game::event.key.keysym.sym) {
        case SDLK_w:
            player->velocity.y = -1;
            break;
        case SDLK_a:
            player->velocity.x = -1;
            break;
        case SDLK_d:
            player->velocity.x = 1;
            break;
        case SDLK_s:
            player->velocity.y = 1;
            break;
        default:
            break;
        }
    }

    if (Game::event.type == SDL_KEYUP) {
        switch (Game::event.key.keysym.sym) {
        case SDLK_w:
            player->velocity.y = 0;
            break;
        case SDLK_a:
            player->velocity.x = 0;
            break;
        case SDLK_d:
            player->velocity.x = 0;
            break;
        case SDLK_s:
            player->velocity.y = 0;
            break;
        default:
            break;
        }
    }

    // if(player->getPosition().x > 300) {
    //     player->setTex("assets/dirt.png");
    // }
}

void Game::render() {
    SDL_RenderClear(renderer);
    // things to render
    map->DrawMap();
    player->render();
    wall->render();
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game cleaned!" << endl;
}