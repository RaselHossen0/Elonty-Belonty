#include "init.h"
SDL_Texture *bg222;
 SDL_Texture *replay_tex,*tex3,*bg_Tex,*gameover_tex,*tex,*tex0,*againTex,*cloud,*Putul_Tex ;
 SDL_Rect replay_rect;

void texCreate()
{
    surface=IMG_Load("res/bg.jpg");
    bg222=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);

    surface=IMG_Load("");
    extern SDL_Texture *tryA;

    surface = IMG_Load("res/replay.png");
    if (!surface)
    {
        printf("replay Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
       // return 1;
    }
   replay_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    if (!replay_tex)
    {
        printf("replayTexture %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        //return 1;
    }
 
    replay_rect.w = 200;
    replay_rect.h = 100;
    replay_rect.x = (WINDOW_WIDTH - replay_rect.w) / 2;
    replay_rect.y = (WINDOW_HEIGHT - replay_rect.h) / 2;

     surface = IMG_Load("res/start.jpg");
    if (!surface)
    {
        printf("Redbar Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
       // return 1;
    }
    tex3 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    if (!tex3)
    {
        printf("Redline Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        //return 1;
    }

    surface = IMG_Load("res/3.png");
    bg_Tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("res/gameover.jpeg");
    if (!surface)
    {
        printf("Green rectangle Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
      //  return 1;
    }
    gameover_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("res/newman.png");
    if (!surface)
    {
        printf("Redbar Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        //return 1;
    }

    tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    if (!tex)
    {
        printf("Redline Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
       // return 1;
    }
   surface = IMG_Load("res/dip.jpg");
    if (!surface)
    {
        printf("Redbar Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
      //  return 1;
    }
    tex0 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    if (!tex0)
    {
        printf("Redline Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
      //  return 1;
    }
     surface = IMG_Load("res/playAgain.png");
    againTex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

     surface = IMG_Load("res/cloud.png");
    cloud = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    surface = IMG_Load("res/putull.png");
    Putul_Tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
}