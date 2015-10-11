//
// Created by fran on 10.10.15.
//

#ifndef ANALYTICS_DRAWCHARACTERS_H
#define ANALYTICS_DRAWCHARACTERS_H

#include <SDL2/SDL.h>
#include "SDLInitializer.h"
#include <string>


class character {
public:
    character(SDLInitializer &sdlinit, const int &width, const int &heigth);
    virtual void draw(const Uint8 *keys) =0;

protected:
    SDL_Texture* createtexture(std::string imagePath,bool withTransparency=true);
    int w_;
    int h_;
    SDL_Texture* texture;
    SDLInitializer& sdlinit_;
    int last_move_;
    SDL_Rect position_in_window;
    SDL_Rect position_in_sprite;
    SDL_Texture* selected_texture;
    int number_of_positions_in_sprite;
    const int height_;
    const int width_;

};


#endif //ANALYTICS_DRAWCHARACTERS_H
