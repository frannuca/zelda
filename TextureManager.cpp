//
// Created by frannuca on 01.01.19.
//

#include "TextureManager.h"
#include <SDL_image.h>
SDL_Texture *TextureManager::LoadTexture(const char *filename, SDL_Renderer *renderer) {
    SDL_Surface * aux = IMG_Load(filename);
    auto tex = SDL_CreateTextureFromSurface(renderer,aux);
    SDL_FreeSurface(aux);
    return tex;
}

void TextureManager::Draw(SDL_Renderer *renderer,SDL_Texture *tex, SDL_Rect src, SDL_Rect dest) {
    SDL_RenderCopy(renderer,tex,&src,&dest);
}
