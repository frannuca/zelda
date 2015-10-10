//Include SDL functions and datatypes

#include "SDLInitializer.h"
#include <SDL2/SDL_timer.h>
SDL_Texture* createlink(std::string imagePath,SDLInitializer &sdlinit,bool withTransparency=true) {


    auto link = SDL_LoadBMP(imagePath.c_str());
    if (link == nullptr ){
        throw;
    }
    if(withTransparency)
    {
        Uint32 colorkey = SDL_MapRGB(link->format,0xFF,0x00,0xFF);
        SDL_SetColorKey(link,SDL_TRUE,colorkey);


    }

    SDL_Texture *tex_link = SDL_CreateTextureFromSurface(sdlinit.getRenderer(), link);
    SDL_FreeSurface(link);
    if (tex_link == nullptr){
        throw;
    }

    return tex_link;
}
static Uint32 next_time;
#define TICK_INTERVAL    60
Uint32 time_left(void)
{
    Uint32 now;

    now = SDL_GetTicks();
    if(next_time <= now)
        return 0;
    else
        return next_time - now;
}

const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;
const int IW = 128;
const int IL = 13;
const int IL_plants =10;
int main( int argc, char* args[] ) {




    SDLInitializer sdlinit("Zelda",1480,850);
    SDL_Surface* display = SDL_GetWindowSurface(sdlinit.getWindow());


    SDL_Texture *tex_link_down  = createlink( "/home/fran/code/github/zelda/resources/link_down_1664x128.bmp",sdlinit);
    SDL_Texture *tex_link_down_sword  = createlink( "/home/fran/code/github/zelda/resources/link_down_1664x128.bmp",sdlinit);
    SDL_Texture *tex_link_up  = createlink( "/home/fran/code/github/zelda/resources/link_up_1664x128.bmp",sdlinit);
    SDL_Texture *tex_link_left  = createlink( "/home/fran/code/github/zelda/resources/link_left_1664x128.bmp",sdlinit);
    SDL_Texture *tex_link_right = createlink( "/home/fran/code/github/zelda/resources/link_right_1664x128.bmp",sdlinit);
    SDL_Texture *tex_link_dying = createlink( "/home/fran/code/github/zelda/resources/link_down_1664x128.bmp",sdlinit);


    SDL_Texture *tex_bean = createlink( "/home/fran/code/github/zelda/resources/bean_1280x128.bmp",sdlinit,false);

    //A sleepy rendering loop, wait for 3 seconds and render and present the screen each time
    bool quit=false;
    SDL_Event event;
    const Uint8* keys = SDL_GetKeyboardState(NULL);
    SDL_Rect r_link;
    r_link.x=0;
    r_link.y=0;
    r_link.h=IW;
    r_link.w=IW;

    SDL_Rect rwindow;
    rwindow.x=330;
    rwindow.y=330;
    rwindow.w=IW;
    rwindow.h=IW;


    SDL_Rect r_bean;
    r_bean.x=0;
    r_bean.y=0;
    r_bean.w=IW;
    r_bean.h=IW;

    SDL_Rect r_window_bean;
    r_window_bean.x=530;
    r_window_bean.y=600;
    r_window_bean.w=IW;
    r_window_bean.h=IW;

    int counter_down=0;
    int walking_frame=0;
    int speed = 6;

    int plant_counter=0;
    SDL_Texture * current_link = tex_link_down;
    next_time = SDL_GetTicks() + TICK_INTERVAL;
    int last_move=SDL_SCANCODE_DOWN;
    int counter_bean=0;
    while( !quit){
        //The frames per second timer

        SDL_PollEvent(&event);

        if(keys[SDL_SCANCODE_DOWN]) {last_move = SDL_SCANCODE_DOWN;current_link = tex_link_down; { counter_down = ++counter_down%IL; r_link.x=counter_down*IW;};rwindow.y+=speed;}
        if(last_move == SDL_SCANCODE_DOWN && keys[SDL_SCANCODE_SPACE]) {last_move = SDL_SCANCODE_DOWN;current_link = tex_link_down_sword; { counter_down = ++counter_down%IL; r_link.x=counter_down*IW;};rwindow.y+=speed;}
        if(keys[SDL_SCANCODE_UP]) {last_move = SDL_SCANCODE_UP;current_link = tex_link_up; { counter_down = ++counter_down%IL; r_link.x=counter_down*IW;};rwindow.y-=speed;}
        if(keys[SDL_SCANCODE_LEFT]){last_move = SDL_SCANCODE_LEFT;current_link = tex_link_left; { counter_down = ++counter_down%IL; r_link.x=counter_down*IW;};rwindow.x-=speed;}
        if(keys[SDL_SCANCODE_RIGHT]) {last_move = SDL_SCANCODE_RIGHT;current_link = tex_link_right; { counter_down = ++counter_down%IL; r_link.x=counter_down*IW;};rwindow.x+=speed;}
        if(!keys[SDL_SCANCODE_UP] && !keys[SDL_SCANCODE_DOWN]&& !keys[SDL_SCANCODE_LEFT] && ! keys[SDL_SCANCODE_RIGHT])
        {
            counter_down=0;
            r_link.x = 0;
        }

        if(keys[SDL_SCANCODE_ESCAPE]){
          for (int i=0;i<3;++i){
              r_link.x=i*IW;
              //First clear the renderer
              SDL_RenderClear(sdlinit.getRenderer());
              //Draw the texture
              SDL_RenderCopy(sdlinit.getRenderer(), tex_link_dying,&r_link,&rwindow);
                SDL_Delay(500);
              //Update the screen
              SDL_RenderPresent(sdlinit.getRenderer());
          }
            SDL_Delay(1500);
            break;
        }


//SDL_BlitSurface(bmp,NULL,buffer,&bmp->clip_rect);

        //First clear the renderer
        SDL_RenderClear(sdlinit.getRenderer());


        if(plant_counter%2==0)
        {
            r_bean.x= (counter_bean%IL_plants)*IW;
            counter_bean++;
        }
        plant_counter++;

        //Draw the texture
        SDL_RenderCopy(sdlinit.getRenderer(), tex_bean,&r_bean,&r_window_bean);

        //Draw the texture
        SDL_RenderCopy(sdlinit.getRenderer(), current_link,&r_link,&rwindow);

        //Update the screen
        SDL_RenderPresent(sdlinit.getRenderer());

        SDL_Delay(time_left());
        next_time += TICK_INTERVAL;

    }



}