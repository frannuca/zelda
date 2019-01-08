//
// Created by frannuca on 01.01.19.
//

#include "Map.h"
#include "TextureManager.h"


int lvl1[MAPROWS][MAPCOLUMNS]={
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

Map::Map(SDL_Renderer * rendererx): renderer(rendererx) {

    dirt = TextureManager::LoadTexture("/home/frannuca/code/zelda/assets/dirt.png", renderer);
    water = TextureManager::LoadTexture("/home/frannuca/code/zelda/assets/water.png", renderer);
    grass = TextureManager::LoadTexture("/home/frannuca/code/zelda/assets/grass.png", renderer);


}

Map::~Map() {
    SDL_DestroyTexture(grass);
    SDL_DestroyTexture(water);
    SDL_DestroyTexture(dirt);
}

void Map::LoadMap() {
    src_rect.x = src_rect.y = dest_rect.x = dest_rect.y =0;
    src_rect.w = src_rect.h = dest_rect.w = dest_rect.h = 32;

    for(int i=0;i<MAPROWS;++i){
        for(int j=0;j<MAPCOLUMNS;++j){
            tilesmap[i][j]=lvl1[i][j];
        }

    }
}

void Map::DrawMap() {

    int type=0;
    for(int i=0;i<MAPROWS;++i){
        dest_rect.y = i*dest_rect.h;
        for(int j=0;j<MAPCOLUMNS;++j){
            type = tilesmap[i][j];
            dest_rect.x = j*dest_rect.w;

            switch (type){
                case(0):
                    TextureManager::Draw(renderer,grass,src_rect,dest_rect);
                    break;
                case(1):
                    TextureManager::Draw(renderer,dirt,src_rect,dest_rect);
                    break;
                case(2):
                    TextureManager::Draw(renderer,water,src_rect,dest_rect);
                    break;
            }
        }
    }
}
