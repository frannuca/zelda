//
// Created by fran on 09.10.15.
//

#ifndef ANALYTICS_SDLINITIALIZER_H
#define ANALYTICS_SDLINITIALIZER_H

#include <string>
#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_log.h>

class SDLInitializer {
public:
    SDLInitializer();
    SDLInitializer(const std::string& windowname, size_t w, size_t h);
    SDL_Window* getWindow(){ return win;}
    SDL_Renderer* getRenderer(){return ren;};
    ~SDLInitializer();
private:
    int initall();
    std::string name;
    size_t heigth;
    size_t width;
    SDL_Window *win;
    SDL_Renderer *ren;
};


#endif //ANALYTICS_SDLINITIALIZER_H
