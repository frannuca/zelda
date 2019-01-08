//
// Created by frannuca on 01.01.19.
//

#ifndef ATTACKOVERTIME_MAP_H
#define ATTACKOVERTIME_MAP_H
#include "Game.h"
#include <SDL.h>
const int MAPROWS = 20;
const int MAPCOLUMNS = 25;

class Map {
public:


    Map(SDL_Renderer * renderer);
    ~Map();

    void LoadMap();
    void DrawMap();

protected:

    SDL_Renderer * renderer = nullptr;
    SDL_Rect src_rect, dest_rect;
    SDL_Texture *dirt;
    SDL_Texture *grass;
    SDL_Texture *water;

    int tilesmap[20][25];

};


#endif //ATTACKOVERTIME_MAP_H
