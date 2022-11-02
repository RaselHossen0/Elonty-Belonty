#include "init.h"
SDL_Texture *tex0,*tex3,*tex,*gameover_tex,*bg_Tex ,*Putul_Tex,*next_level,*l2boy,*fire2_Tex ,*fire_Tex;
SDL_Texture *replay_tex,*cloud,*againTex,*fir;
void loadMedia()
{
        bool success=1;
        surface = IMG_Load("res/dip.jpg");
    if (!surface)
    {
        printf("Redbar Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        success=0;   
    }
    tex0 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    if (!tex0)
    {
        printf("Redline Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        success=0;
    }
    surface = IMG_Load("res/start.jpg");
    if (!surface)
    {
        printf("Redbar Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        //return 1;
    }
    tex3 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    if (!tex3)
    {
        printf("Redline Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
       // return 1;
    }
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
        //return 1;
    }
    surface = IMG_Load("res/gameover.jpeg");
    if (!surface)
    {
        printf("Green rectangle Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        //return 1;
    }
    gameover_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    if (!tex)
    {
        printf("Green Rectangle Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        //return 1;
    }
    surface = IMG_Load("res/bg.png");
    bg_Tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("res/putull.png");
    Putul_Tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("res/2883482.png");
    next_level = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("res/sprite-02.png");
    l2boy = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("res/fire2.png");
    fire2_Tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("res/fire.png");
    fire_Tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("res/replay.png");
    if (!surface)
    {
        printf("replay Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
      //  return 1;
    }
    replay_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    if (!replay_tex)
    {
        printf("replayTexture %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
      //  return 1;
    }
     surface = IMG_Load("res/cloud.png");
    cloud = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
      surface = IMG_Load("res/playAgain.png");
    againTex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    surface=IMG_Load("res/fireA.png");
    fir=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
  //  return success;
}