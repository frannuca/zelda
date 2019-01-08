#include <SDL2/SDL.h>
#include <stdio.h>
#include "Game.h"


// Screen (rendering/display surface) dimensions
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int FPS = 60;
const int FRAMEDELAY = 1000/FPS;



int main (int argc, char* args[]) {

    Uint32  framestart;
    Uint32 frametime;
    Game* game = new Game();
    game->init("Attack Over Time",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,25*32,20*32,false);
    while(game->running()){
        framestart = SDL_GetTicks();
        game->handleEvents();
        game->update();
        game->render();
        frametime = SDL_GetTicks() - framestart;
        if(frametime< FRAMEDELAY){
            SDL_Delay(FRAMEDELAY-frametime);
        }
    }

    game->clean();
    return 0;
}
