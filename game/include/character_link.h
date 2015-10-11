//
// Created by fran on 11.10.15.
//

#ifndef ANALYTICS_CHARACTER_LINK_H
#define ANALYTICS_CHARACTER_LINK_H

#include "character.h"
class character_link: public character {

public:
    character_link(SDLInitializer& sdlInitializer);
    virtual void draw(const Uint8 *keys) override;

private:
    SDL_Texture *tex_link_down;
    SDL_Texture *tex_link_up;
    SDL_Texture *tex_link_left;
    SDL_Texture *tex_link_right;
    SDL_Texture *tex_link_dying;
    static int speed;

};


#endif //ANALYTICS_CHARACTER_LINK_H
