//
// Created by fran on 09.10.15.
//

#include "SDLInitializer.h"
#include "sdlcleanup.h"


SDLInitializer::SDLInitializer():name("no name"),heigth(640),width(480),win(nullptr),ren(nullptr) {
    initall();
}

SDLInitializer::SDLInitializer(const std::string &windowname, size_t w, size_t h):name(windowname),heigth(h),width(w)  {
    initall();
}

SDLInitializer::~SDLInitializer() {
    if(win != nullptr)
        cleanup(win);
    if(ren != nullptr)
        cleanup(ren);

    SDL_Quit();
}

int SDLInitializer::initall() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }
//
    win = SDL_CreateWindow("Hello World!", 100, 100, width, heigth, SDL_WINDOW_SHOWN );
    if (win == nullptr){
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == nullptr){
        SDL_DestroyWindow(win);
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }


}
