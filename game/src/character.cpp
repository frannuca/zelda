//
// Created by fran on 10.10.15.
//

#include "character.h"

character::character(SDLInitializer &sdlinit, const int &width, const int &heigth) :
        sdlinit_(sdlinit),last_move_(SDL_KEYDOWN),width_(width),height_(heigth){
    position_in_sprite.x=0;
    position_in_sprite.y=0;
    position_in_sprite.w= heigth;
    position_in_sprite.h = heigth;


    position_in_window.x=0;
    position_in_window.y=0;
    position_in_window.h=heigth;
    position_in_window.w=heigth;

    selected_texture= nullptr;


    number_of_positions_in_sprite=width_/height_;
}
SDL_Texture* character::createtexture(std::string imagePath,bool withTransparency) {


    auto link = SDL_LoadBMP(imagePath.c_str());
    if (link == nullptr ){
        throw "Invalid bmp "+ imagePath;
    }
    if(withTransparency)
    {
        Uint32 colorkey = SDL_MapRGB(link->format,0xFF,0x00,0xFF);
        SDL_SetColorKey(link,SDL_TRUE,colorkey);


    }

    SDL_Texture *tex_link = SDL_CreateTextureFromSurface(sdlinit_.getRenderer(), link);
    SDL_FreeSurface(link);
    if (tex_link == nullptr){
        throw "Invalid texture "+ imagePath;
    }

    return tex_link;
}