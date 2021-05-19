#ifndef Game_hpp
#define Game_hpp

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

class GameObject;

class Game {
public:
    Game();
    ~Game();
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running() {return isRunning;};

    static SDL_Renderer *renderer;
    static SDL_Event event;
    static std::vector<GameObject> tiles;

private:
    bool isRunning;
    SDL_Window *window;
    int count = 0;
};

#endif /* Game_hpp */