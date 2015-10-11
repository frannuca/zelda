//
// Created by fran on 11.10.15.
//

#include "character_link.h"

int character_link::speed = 5;

void character_link::draw(const Uint8 *keys) {

    if(keys[SDL_SCANCODE_DOWN]) {

        selected_texture = tex_link_down;
        auto p = (last_move_ == SDL_SCANCODE_DOWN)? position_in_sprite.x/height_:0;
        last_move_ = SDL_SCANCODE_DOWN;
        position_in_sprite.x = (++p%number_of_positions_in_sprite)*height_;
        position_in_window.y+=character_link::speed;
    }
    if(keys[SDL_SCANCODE_UP]){
        selected_texture = tex_link_up;
        auto p = (last_move_ == SDL_SCANCODE_UP)? position_in_sprite.x/height_:0;
        last_move_ = SDL_SCANCODE_UP;
        position_in_sprite.x = (++p%number_of_positions_in_sprite)*height_;
        position_in_window.y-=character_link::speed;
    }
    if(keys[SDL_SCANCODE_LEFT]){
        selected_texture = tex_link_left;
        auto p = (last_move_ == SDL_SCANCODE_LEFT)? position_in_sprite.x/height_:0;
        last_move_ = SDL_SCANCODE_LEFT;
        position_in_sprite.x = (++p%number_of_positions_in_sprite)*height_;
        position_in_window.x-=character_link::speed;
    }
    if(keys[SDL_SCANCODE_RIGHT]){
        selected_texture = tex_link_right;
        auto p = (last_move_ == SDL_SCANCODE_RIGHT)? position_in_sprite.x/height_:0;
        last_move_ = SDL_SCANCODE_RIGHT;
        position_in_sprite.x = (++p%number_of_positions_in_sprite)*height_;
        position_in_window.x+=character_link::speed;
    }
//    if(!keys[SDL_SCANCODE_UP] && !keys[SDL_SCANCODE_DOWN]&& !keys[SDL_SCANCODE_LEFT] && ! keys[SDL_SCANCODE_RIGHT])
//    {
//        position_in_sprite.x = 0;
//    }

    if(selected_texture == nullptr)
        selected_texture = tex_link_down;
    SDL_RenderCopy(sdlinit_.getRenderer(), selected_texture,&position_in_sprite,&position_in_window);
}

character_link::character_link(SDLInitializer &sdlInitializer): character(sdlInitializer, 1664,128) {

    tex_link_down  = createtexture( "/home/fran/code/github/zelda/resources/link_down_1664x128.bmp",true);
    tex_link_up  = createtexture( "/home/fran/code/github/zelda/resources/link_up_1664x128.bmp",true);
    tex_link_left  = createtexture( "/home/fran/code/github/zelda/resources/link_left_1664x128.bmp",true);
    tex_link_right = createtexture( "/home/fran/code/github/zelda/resources/link_right_1664x128.bmp",true);


}

character_link::~character_link() {
    SDL_DestroyTexture(tex_link_down);
    SDL_DestroyTexture(tex_link_up);
    SDL_DestroyTexture(tex_link_left);
    SDL_DestroyTexture(tex_link_right);
}
