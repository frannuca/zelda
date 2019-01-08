//
// Created by frannuca on 01.01.19.
//
#ifndef ATTACKOVERTIME_TEXTUREMANAGER_H
#define ATTACKOVERTIME_TEXTUREMANAGER_H

#include <SDL.h>

class TextureManager {
public:
    static SDL_Texture *LoadTexture(const char* filename,SDL_Renderer *renderer);
    static void Draw(SDL_Renderer *renderer,SDL_Texture *tex,SDL_Rect src, SDL_Rect dest);
};


#endif //ATTACKOVERTIME_TEXTUREMANAGER_H
