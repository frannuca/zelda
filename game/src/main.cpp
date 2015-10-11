//Include SDL functions and datatypes

#include "SDLInitializer.h"
#include <SDL2/SDL_timer.h>
#include <character_link.h>
#include "character.h"


static Uint32 next_time;
#define TICK_INTERVAL    60
Uint32 time_left(void)
{
    Uint32 now;

    now = SDL_GetTicks();
    if(next_time <= now)
        return 0;
    else
        return next_time - now;
}

const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

int main( int argc, char* args[] ) {

    SDLInitializer sdlinit("Zelda",1480,850);
    //A sleepy rendering loop, wait for 3 seconds and render and present the screen each time
    bool quit=false;
    SDL_Event event;
    const Uint8* keys = SDL_GetKeyboardState(NULL);

    character_link link(sdlinit);

    while( !quit){
        //The frames per second timer

        SDL_PollEvent(&event);
        //First clear the renderer
        SDL_RenderClear(sdlinit.getRenderer());
        link.draw(keys);
        //Update the screen
        SDL_RenderPresent(sdlinit.getRenderer());

        SDL_Delay(time_left());
        next_time += TICK_INTERVAL;

        if(keys[SDL_SCANCODE_ESCAPE])
            return 0;

    }



}