//
// Created by frannuca on 03.01.19.
//

#include "TileComponent.h"

TileComponent::TileComponent(int x, int y, int w, int h, int id,std::string name,bool withcollision) {
    tileRect.x=x;
    tileRect.y=y;
    tileRect.w=w;
    tileRect.h=h;
    tileID=id;
    hascollision=withcollision;
    tag = name;
    switch (tileID){
        case 0:
            path = "/home/frannuca/code/zelda/assets/water.png";
            break;
        case 1:
            path= "/home/frannuca/code/zelda/assets/dirt.png";
            break;
        case 2:
            path = "/home/frannuca/code/zelda/assets/grass.png";
            break;
        default:
            break;

    }
}

void TileComponent::init() {
    entity->addComponent<TransformComponent>(tileRect.x,tileRect.y,tileRect.w,tileRect.h,1.0);
    entity->addComponent<SpriteComponent>(path,
                                          SpriteComponent::SpriteStructure{.upslice=0,.downslice=0,.leftslice =0,.rightslice = 0, .sizex = 32,.sizey = 32});
    sprite = &entity->getComponent<SpriteComponent>();

    if(hascollision)
        entity->addComponent<ColliderComponent>(tag);


}
