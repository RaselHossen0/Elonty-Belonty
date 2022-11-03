#pragma once
#include "init.h"
SDL_Rect start_rect;
SDL_Rect cloud_rect;
   SDL_Rect t_rect;
    SDL_Rect playerRect;    
    SDL_Rect playerPosition;
        SDL_Rect gameover_rect;


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

    playerPosition.x = 350;
    playerPosition.y = 550;
    playerPosition.w = 150;
    playerPosition.h = 150;


    gameover_rect.w = 400;
    gameover_rect.h = 300;
    gameover_rect.x = (WINDOW_WIDTH - gameover_rect.w) / 2;
    gameover_rect.y = (WINDOW_HEIGHT - gameover_rect.h) / 2 - 250;
}