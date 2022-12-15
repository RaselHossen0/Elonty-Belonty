#pragma once
#include "init.h"
SDL_Rect start_rect;
SDL_Rect cloud_rect;
   SDL_Rect t_rect;
    SDL_Rect playerRect;    
    SDL_Rect playerPosition;
        SDL_Rect gameover_rect;SDL_Rect next,sbg_rect,sbg_rect1;
extern SDL_Texture *cloud;

void loadRect(){

    start_rect.w = 300;
    start_rect.h = 150;
    start_rect.x = (WINDOW_WIDTH - start_rect.w) / 2;
    start_rect.y = (WINDOW_HEIGHT - start_rect.h) / 2;
     
    SDL_QueryTexture(cloud, NULL, NULL, &cloud_rect.w, &cloud_rect.h);
    cloud_rect.w /= 8;
    cloud_rect.h /= 8;
    cloud_rect.x = 0;
    cloud_rect.y = 0;

  
    t_rect.w =300;
    t_rect.h = 100;
    t_rect.x = 0;
    t_rect.y = 0;

    sbg_rect.w =1280;
    sbg_rect.h = 720;
    sbg_rect.x = 0;
    sbg_rect.y = 0;

    sbg_rect1.w =1280;
    sbg_rect1.h = 720;
    sbg_rect1.x =-1280;
    sbg_rect1.y = 0;

    playerPosition.x = 350;
    playerPosition.y = 550;
    playerPosition.w = 150;
    playerPosition.h = 150;


    gameover_rect.w = 400;
    gameover_rect.h = 300;
    gameover_rect.x = (WINDOW_WIDTH - gameover_rect.w) / 2;
    gameover_rect.y = (WINDOW_HEIGHT - gameover_rect.h) / 2 - 250;

    next.w = 180;
    next.h = 180;
    next.x = 490;
    next.y = 450;
}
