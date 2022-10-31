#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <bits/stdc++.h>

#define WINDOW_WIDTH (1280)
#define WINDOW_HEIGHT (720)
#define SCROLL_SPEED (900)
#define RECT_SPEED (5.0)


            


int main(int agr, char *args[])
{

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) > 0)
    {

        
        printf("video and timer: %s\n", SDL_GetError());
    }
    /*if (!(IMG_Init(IMG_INIT_PNG|IMG_INIT_JPG)))
        printf("image: %s\n",SDL_GetError());*/
    if(TTF_Init()==-1){
        std::cout<<"error";
    }
    else
    std::cout<<"success";
    printf("Initialization Complete\n");

    SDL_Window *win = SDL_CreateWindow("SDL Demonstration", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

    if (!win)
    {
        printf("window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    SDL_Renderer *rend = SDL_CreateRenderer(win, -1, render_flags);
    
 TTF_Font* ff=TTF_OpenFont( "res/fonts/Oswald-Bold.ttf", 28 );
 
    bool running =true;
    while(running){
        SDL_Event e;
        while(SDL_PollEvent(&e)){
            if(e.type==SDL_QUIT){
                running=false;
            }
        }
       
    int count=SDL_GetTicks()/1000;
    std::string i=std::to_string(count);
    SDL_Surface* surface=TTF_RenderText_Solid(ff,i.c_str(),{255,255,255});
    SDL_Texture* tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
    
    SDL_Rect rect;
    rect.x=10;
    rect.y=10;
    rect.w=400;
    rect.h=100;
     //SDL_SetRenderDrawColor(rend,0,0,0xFF,SDL_ALPHA_OPAQUE);
        SDL_RenderClear(rend);
        SDL_RenderCopy(rend,tex,NULL,&rect);
        SDL_RenderPresent(rend);
    }

   

    
    

    //SDL_Delay(100);
    
   
    //SDL_DestroyTexture(tex);
    SDL_DestroyWindow(win);
    //TTF_CloseFont(ff);

    SDL_Quit();
    return 0;
}

