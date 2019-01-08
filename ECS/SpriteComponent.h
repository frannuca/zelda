//
// Created by frannuca on 01.01.19.
//

#ifndef ATTACKOVERTIME_SPRITECOMPONENT_H
#define ATTACKOVERTIME_SPRITECOMPONENT_H
#include "Components.h"
#include <SDL.h>
#include "../TextureManager.h"
#include "KeyboardController.h"

class SpriteComponent: public Component {
private:
    TransformComponent *transform;
    KeyboardController *keycontroller;

    SDL_Texture *texture;



public:
    struct SpriteStructure{
        int upslice;
        int downslice;
        int leftslice;
        int rightslice;
        int sizex;
        int sizey;
    };


    std::unique_ptr<SpriteStructure> spriteStructure;
    SDL_Rect srcRect,destRect;
    SpriteComponent() = delete;
    SpriteComponent(const char* texturepath,const SpriteStructure& spriteStructure_)
    {
        setTexture(texturepath);
        spriteStructure.reset(new SpriteStructure(spriteStructure_));
        Game::subject().attach(*this,Subject::GROUPTYPE::COLLISIONS);
    }

    ~SpriteComponent(){
        SDL_DestroyTexture(texture);
    }
    void init() override{

        transform = &(entity->getComponent<TransformComponent>());
        keycontroller= &(entity->getComponent<KeyboardController>());
        srcRect.x = 0;
        srcRect.y = 0;
        if(spriteStructure){
            srcRect.w=spriteStructure->sizex;
            srcRect.h=spriteStructure->sizey;

        }
        else{
            srcRect.w=transform->width;
            srcRect.h=transform->height;
        }

    }

    void notify(const CallbackArgs *args) override{

        std::cout<<"notification"<<std::endl;
        if(args->group() == Subject::GROUPTYPE::COLLISIONS){

            const CollisionCallBackArgs* collision = dynamic_cast<const CollisionCallBackArgs*>(args);
            auto o1 = collision->object1tag;
            transform->resetPosition();
        }
    }

    void update() override{

        destRect.w = transform->width*transform->scale;
        destRect.h = transform->height*transform->scale;
        if(entity->hasComponent<KeyboardController>() && spriteStructure){
            switch (keycontroller->lastdirection){
                case KeyboardController::NONE:
                case KeyboardController::DOWN:
                    srcRect.y = 10*64;
                    break;
                case KeyboardController::UP:
                    srcRect.y = 8*64;
                    break;
                case KeyboardController::LEFT:
                    srcRect.y = 9*64;
                    break;
                case KeyboardController::RIGHT:
                    srcRect.y = 11*64;
                    break;

            }
            srcRect.x = keycontroller->spriteSlide*64;
        }


        destRect.x = static_cast<int>(transform->position.x);
        destRect.y = static_cast<int>(transform->position.y);
    };

    void draw() override{
        TextureManager::Draw(Game::GetRenderer(),texture,srcRect,destRect);
    };

    void setTexture(const char* texturepath){
        texture = TextureManager::LoadTexture(texturepath,Game::GetRenderer());
    }
};


#endif //ATTACKOVERTIME_SPRITECOMPONENT_H
