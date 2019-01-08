//
// Created by frannuca on 01.01.19.
//

#ifndef ATTACKOVERTIME_POSITIONCOMPONENT_H
#define ATTACKOVERTIME_POSITIONCOMPONENT_H

#include "ECS.h"
#include "../Vector2D.h"
struct TransformComponent: public Component{

    Vector2D position;
    Vector2D lastposition;
    Vector2D velocity;
    int speed = 1;

    int height=32;
    int width = 32;
    int scale = 8;

    TransformComponent(){
        position = Vector2D(0,0);
        lastposition.zero();
    }
    TransformComponent(int sc){
        position = Vector2D(0,0);
        lastposition.zero();
        scale=sc;
    }
    TransformComponent(int x, int y){
       position = Vector2D(x,y);
        lastposition=position;
    }
    TransformComponent(int x, int y,int w, int h, int s){
        position = Vector2D(x,y);
        lastposition=position;
        height=h;
        width=w;
        scale=s;
    }
    void init() override{
        velocity.zero();
    }

    void update() override{

        lastposition=position;
        position += velocity*speed;
    }

    void resetPosition(){
        position=lastposition;
    }
};


#endif //ATTACKOVERTIME_POSITIONCOMPONENT_H
