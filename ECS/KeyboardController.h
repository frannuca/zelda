//
// Created by frannuca on 02.01.19.
//

#ifndef ATTACKOVERTIME_KEYBOARDCONTROLLER_H
#define ATTACKOVERTIME_KEYBOARDCONTROLLER_H
#include "../Game.h"
#include "ECS.h"
#include "Components.h"

class KeyboardController:public Component{
public:
    enum DIRECTION {NONE,RIGHT,LEFT,UP,DOWN};
    DIRECTION  lastdirection;
    int spriteSlide=0;
    TransformComponent *transform;


    void init() override{
        transform = &entity->getComponent<TransformComponent>();
    }

    void update() override{
        DIRECTION d=NONE;
        if(Game::event.type== SDL_KEYDOWN){

            switch(Game::event.key.keysym.sym){
                case SDLK_w:
                    d = UP;
                    transform->velocity.y = -1;
                    break;
                case SDLK_s:
                    d = DOWN;
                    transform->velocity.y = 1;
                    break;
                case SDLK_a:
                    d = LEFT;
                    transform->velocity.x = -1;
                    break;
                case SDLK_d:
                    d = RIGHT;
                    transform->velocity.x = 1;
                    break;
                default:
                    break;
            }

        }

        if(Game::event.type== SDL_KEYUP){
            switch(Game::event.key.keysym.sym){
                case SDLK_w:
                    transform->velocity.y = 0;
                    break;
                case SDLK_s:
                    transform->velocity.y = 0;
                    break;
                case SDLK_a:
                    transform->velocity.x = 0;
                    break;
                case SDLK_d:
                    transform->velocity.x = 0;
                    break;
                default:
                    break;
            }
        }

        if(d!=NONE){
            if(lastdirection != d){
                lastdirection = d;
                spriteSlide=0;
            }
            else{
                spriteSlide = (spriteSlide+1)%8;
            }
        }
    }
};
#endif //ATTACKOVERTIME_KEYBOARDCONTROLLER_H
