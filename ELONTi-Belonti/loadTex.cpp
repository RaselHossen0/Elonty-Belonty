#include "init.h"

SDL_Texture *bg222;
 SDL_Texture *replay_tex,*tex3,*bg_Tex,*gameover_tex,*tex,*tex0,*againTex,*cloud,*Putul_Tex,*next_level,*l2boy ;
   SDL_Texture *fire_Tex,*fire2_Tex,*sbg,*deadmanTex ;
 SDL_Rect replay_rect;

void texCreate()
{
    surface=IMG_Load("res/bg.jpg");
    bg222=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);

     surface=IMG_Load("res/startbg.jpeg");
    sbg=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);

    surface=IMG_Load("");
    extern SDL_Texture *tryA;

    surface = IMG_Load("res/replay.png");
    replay_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
  
 
    replay_rect.w = 200;
    replay_rect.h = 100;
    replay_rect.x = (WINDOW_WIDTH - replay_rect.w) / 2;
    replay_rect.y = (WINDOW_HEIGHT - replay_rect.h) / 2;

     surface = IMG_Load("res/start.jpg");
    tex3 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
   

    surface = IMG_Load("res/3.png");
    bg_Tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("res/gameover.jpeg");
    gameover_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("res/newman.png");
    tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);


    surface = IMG_Load("res/dip.jpg");
    tex0 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
   
    surface = IMG_Load("res/playAgain.png");
    againTex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("res/cloud.png");
    cloud = SDL_CreateTextureFromSurface(rend, surface);
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

     surface = IMG_Load("res/fire.png");
    fire_Tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

     surface = IMG_Load("res/fire2.png");
    fire2_Tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("res/deadman.png");
    deadmanTex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

}