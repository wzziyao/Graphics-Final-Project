#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "Collision.h"

using namespace std;

GameObject* player;
// GameObject* wall;
GameObject* tile0;
GameObject* tile1;
GameObject* tile2;


Map* tilemap;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

std::vector<GameObject> Game::tiles;

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

    player = new GameObject("assets/player_anim.png", 200, 160, true, true);
    // wall = new GameObject("assets/dirt.png", 300, 300, 300, 20, 1);
    tile0 = new GameObject("assets/dirt.png", 200, 200, 32, 32, 1, 0);
    tiles.push_back(*tile0);
    tile1 = new GameObject("assets/water.png", 250, 250, 32, 32, 1, 1);
    tiles.push_back(*tile1);
    // tile2 = new GameObject("assets/grass.png", 150, 150, 32, 32, 1, 2);
    // tiles.push_back(*tile2);

    tilemap = new Map();
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
    // wall->update();
    tiles[0].update();
    tiles[1].update();
    // tiles[2].update();

    Vector2D pVel = player->velocity;
    int pSpeed = player->speed;

    // for (int t = 0; t < tiles.size(); t++) {
    //     tiles[t].destRect.x += -(pVel.x * pSpeed);
    //     tiles[t].destRect.y += -(pVel.y * pSpeed);
    // }
    tilemap->dest.x += -(pVel.x * pSpeed);
    tilemap->dest.y += -(pVel.y * pSpeed);

    for (int i = 0; i < tiles.size(); i++) {
        if (Collision::AABB(player->collider, tiles[i].collider)) {
            if (tiles[i].tileID == 0 || tiles[i].tileID == 2) {
                player->velocity * (-1);
                // std::cout << "Wall Hit!" << std::endl;
            }
        }
    }

    // player->position.Add(Vector2D(5, 0));
    if (Game::event.type == SDL_KEYDOWN) {
        switch (Game::event.key.keysym.sym) {
        case SDLK_w:
            player->velocity.y = -1;
            break;
        case SDLK_a:
            player->velocity.x = -1;
            player->spriteFlip = SDL_FLIP_HORIZONTAL;
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
        player->animIndex = player->animations["Walk"].index;
        player->frames = player->animations["Walk"].frames;
        player->frame_speed = player->animations["Walk"].speed;
    }

    if (Game::event.type == SDL_KEYUP) {
        switch (Game::event.key.keysym.sym) {
        case SDLK_w:
            player->velocity.y = 0;
            break;
        case SDLK_a:
            player->velocity.x = 0;
            player->spriteFlip = SDL_FLIP_NONE;
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
        player->animIndex = player->animations["Idle"].index;
        player->frames = player->animations["Idle"].frames;
        player->frame_speed = player->animations["Idle"].speed;
    }

    // if(player->getPosition().x > 300) {
    //     player->setTex("assets/dirt.png");
    // }
}

void Game::render() {
    SDL_RenderClear(renderer);
    tilemap->DrawMap();
    player->render();
    // wall->render();
    tiles[0].render();
    tiles[1].render();
    // tiles[2].render();
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game cleaned!" << endl;
}