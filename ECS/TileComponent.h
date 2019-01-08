//
// Created by frannuca on 03.01.19.
//

#ifndef ATTACKOVERTIME_TILECOMPONENT_H
#define ATTACKOVERTIME_TILECOMPONENT_H
#include "ECS.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "ColliderComponent.h"
#include <SDL.h>
#include <string>
class TileComponent: public Component {

public:
    bool hascollision;
    TransformComponent *transform;
    SpriteComponent *sprite;
    ColliderComponent* collider;
    std::string tag;
    const char* path;
    SDL_Rect tileRect;
    int tileID;
    TileComponent(int x, int y, int w, int h, int id,std::string name,bool withcollision=false);

    void init() override;
};


#endif //ATTACKOVERTIME_TILECOMPONENT_H
