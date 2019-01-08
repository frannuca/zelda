//
// Created by frannuca on 31.12.18.
//
#include "Game.h"
#include <iostream>
#include <SDL_image.h>
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Vector2D.h"
#include "ECS/Collision.h"

Map* gamemap = nullptr;
Manager manager;

Entity& player(manager.addEntity(100));
Entity& wall1(manager.addEntity(99));
Entity& wall2(manager.addEntity(100));
Entity& wall3(manager.addEntity(99));

SDL_Renderer *Game::renderer = nullptr;

Game::Game() {

}

Game::~Game() {

}
SDL_Event Game::event;
void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {



    int flags=0;
    if(fullscreen){
        flags  = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout<<"Subsystem SDL initialized"<<std::endl;

        window = SDL_CreateWindow(title,xpos,ypos,width,height,flags);

        if(window){
            std::cout<<"SDL Windows successfully created"<<std::endl;
        }

        renderer = SDL_CreateRenderer(window,-1,0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer,255,255,255,255);
            std::cout<<"Renderer created"<<std::endl;
        }
        isRunning=renderer!=NULL;
    }

    gamemap = new Map(renderer);
    gamemap->LoadMap();
//int x, int y,int w, int h, int s
    player.addComponent<TransformComponent>(0,0,64,64,1);
    player.addComponent<KeyboardController>();
    player.addComponent<SpriteComponent>("/home/frannuca/code/zelda/assets/hero2.png",
            SpriteComponent::SpriteStructure{.upslice=8,.downslice=10,.leftslice =9,.rightslice = 11, .sizex = 64,.sizey = 64});
    player.addComponent<ColliderComponent>("player");

    //int x, int y, int w, int h, int id,std::string name
    wall1.addComponent<TileComponent>(300.0f,300.0f,300,20,1,"wall1",false);
    wall2.addComponent<TileComponent>(300.0f,400.0f,300,20,0,"wall2",true);
    wall3.addComponent<TileComponent>(300.0f,500.0f,300,20,1,"wall3",false);

}

void Game::handleEvents() {

    SDL_PollEvent(&event);
    switch (event.type){
        case(SDL_QUIT):
            isRunning=false;
            break;
        default:
            break;
    }
}

void Game::update() {

    manager.refresh();
    manager.update();
    std::vector<ColliderComponent*> colliders = manager.getComponents<ColliderComponent>();
    ColliderComponent* playercollider = player.getComponentPtr<ColliderComponent>();
    for(auto c:colliders){


        if(Collision::AABB(*playercollider,*c)){
            CollisionCallBackArgs args("player","wall");

            subject().notify(Subject::GROUPTYPE::COLLISIONS,&args);
            break;
        }
    }

}

void Game::render() {
    SDL_RenderClear(renderer);
    gamemap->DrawMap();
    manager.draw();
    SDL_RenderPresent(renderer);
}

void Game::clean() {

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout<<"Game Cleaned"<<std::endl;
}

bool Game::running() {
    return isRunning;
}

SDL_Renderer *Game::GetRenderer() {
    return renderer;
}

Subject &Game::subject() {
    static Subject local;
    return local;
}

