//
// Created by frannuca on 31.12.18.
//

#ifndef ATTACKOVERTIME_GAME_H
#define ATTACKOVERTIME_GAME_H

#include <SDL.h>
#include "Observer.h"

class Game {
public:
    Game();
    ~Game();

    static SDL_Event event;
    static Subject&  subject();

    void init(const char* title,int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();

    bool running();
    static SDL_Renderer *renderer;
    static SDL_Renderer * GetRenderer();
private:
    int count=0;
    bool isRunning;
    SDL_Window   *window;

};


#endif //ATTACKOVERTIME_GAME_H
