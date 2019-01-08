//
// Created by frannuca on 03.01.19.
//

#ifndef ATTACKOVERTIME_COLLISION_H
#define ATTACKOVERTIME_COLLISION_H

#include <SDL.h>
class ColliderComponent;
class Collision {
public:
    static bool AABB(const SDL_Rect& rectA, const SDL_Rect& rectB);
    static bool AABB(const ColliderComponent& a, const ColliderComponent& b);
};


#endif //ATTACKOVERTIME_COLLISION_H
