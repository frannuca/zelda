//
// Created by frannuca on 01.01.19.
//

#ifndef ATTACKOVERTIME_ECS_H
#define ATTACKOVERTIME_ECS_H
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>
#include "../Game.h"
#include "../Observer.h"

class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID getComponentTypeID(){
    static ComponentID lastID = 0;
    return lastID++;
}

template<typename T> inline  ComponentID getComponentTypeID() noexcept{
    static  ComponentID typeID = getComponentTypeID();
    return typeID;

}

constexpr std::size_t maxComponents=32;
using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*,maxComponents>;

class Component:public Observer{
public:
    Entity* entity;
    virtual void init(){}
    virtual void update(){}
    virtual void draw(){}

    virtual void notify(const CallbackArgs *args) override
    {}

    virtual ~Component(){}
};


class Entity{
private:
    bool active=true;
    std::vector<std::unique_ptr<Component>> components;

    ComponentArray componentArray;
    ComponentBitSet componentBitSet;
    int order;
public:
    const int& getOrder() const{return order;}
    Entity(int order_=0){
        renderer = Game::GetRenderer();
        order=order_;
    }

    SDL_Renderer * renderer = nullptr;
    void update(){
        for(auto& c : components) c->update();
    }
    void draw(){
        for(auto& c: components) c->draw();
    }

    bool isActive(){return active;}

    void destroy(){active=false;}

    template <typename T> bool hasComponent() const{
        return componentBitSet[getComponentTypeID<T>()];
    }

    template <typename T, typename ... TArgs>
    T& addComponent(TArgs&& ... mArgs){
        T* c(new T(std::forward<TArgs>(mArgs)...));
        c->entity = this;
        std::unique_ptr<Component> uPtr{c};
        components.emplace_back(std::move(uPtr));

        componentArray[getComponentTypeID<T>()] = c;
        componentBitSet[getComponentTypeID<T>()] = true;
        c->init();
        return *c;
    }

    template<typename T> T& getComponent() const{
        auto ptr(componentArray[getComponentTypeID<T>()]);
        return *static_cast<T*>(ptr);
    }

    template<typename T> T* getComponentPtr() const{
        return  static_cast<T*>(componentArray[getComponentTypeID<T>()]);
    }
};

class Manager{
private:
    std::vector<std::unique_ptr<Entity>> entities;
public:

    void update(){
        for(auto& e: entities) e->update();
    }

    void draw(){
        for(auto& e:entities) e->draw();
    }

    void refresh(){
        entities.erase(std::remove_if(std::begin(entities),std::end(entities),[](const std::unique_ptr<Entity>& mEntity){
            return !mEntity->isActive();
        }),std::end(entities));
    }

    Entity& addEntity(int order=0){
        Entity* e = new Entity(order);
        std::unique_ptr<Entity> uPtr {e};
        entities.emplace_back(std::move(uPtr));
        std::sort(entities.begin(),entities.end(),
                  [](const std::unique_ptr<Entity> &a,const std::unique_ptr<Entity> &b){return a->getOrder()<b->getOrder();});
        return *e;

    }

    template<typename T>
    std::vector<T*> getComponents(){

        std::vector<T*> components;
        for(auto& e:entities){

            if(e->hasComponent<T>()){
                T* a = e->getComponentPtr<T>();
                components.push_back(a);
            }
        }

        return components;
    }
};
#endif //ATTACKOVERTIME_ECS_H
