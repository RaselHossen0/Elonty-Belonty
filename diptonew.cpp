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
 //void gulli();


struct rect{
    int frmWid,frmHit;
  
    

    rect(int fW,int fH){

        frmWid=fW;
        frmHit=fH;
    }
  
};

int main(int agr, char *args[])
{

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) > 0)
    {
        printf("video and timer: %s\n", SDL_GetError());
    }
    /*if (!(IMG_Init(IMG_INIT_PNG|IMG_INIT_JPG)))
        printf("image: %s\n",SDL_GetError());*/
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048)<0)
    printf("successful");
    TTF_Init();
   // printf("Initialization Complete\n");


    SDL_Window *win = SDL_CreateWindow("SDL Demonstration", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

    if (!win)
    {
        printf("window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    SDL_Renderer *rend = SDL_CreateRenderer(win, -1, render_flags);

    if (!rend)
    {
        printf("renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    SDL_Surface *surface = IMG_Load("res/dip.png");
    if (!surface)
    {
        printf("Redbar Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    SDL_Texture *tex0 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    if (!tex0)
    {
        printf("Redline Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, tex0, NULL, NULL);
    SDL_RenderPresent(rend);
    SDL_Delay(1000/3);

    surface = IMG_Load("res/startb.png");
     SDL_Texture *sTex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("res/deadman.png");
    SDL_Texture *deadmanTex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect deadman;
    deadman.w = 150;
    deadman.h = 150;
    surface = IMG_Load("res/playAgain.png");
    SDL_Texture *againTex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    
    surface = IMG_Load("res/start.png");
    if (!surface)
    {
        printf("Redbar Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    SDL_Texture *tex3 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    if (!tex3)
    {
        printf("Redline Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    SDL_Rect start_rect;
    start_rect.w = 300;
    start_rect.h = 150;
    start_rect.x = (WINDOW_WIDTH - start_rect.w) / 2;
    start_rect.y = (WINDOW_HEIGHT - start_rect.h) / 2 - 100;
    
    surface = IMG_Load("res/all.png");
    if (!surface)
    {
        printf("Redbar Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    SDL_Texture *tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
   //SDL_Texture *tex =SDL_CreateTexture(rend,SDL_PIXELFORMAT_ABGR1555,SDL_TEXTUREACCESS_TARGET,900,900);
    if (!tex)
    {
        printf("Redline Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    SDL_Rect  playerRect;//rect for a single frame of the sprite sheet
    SDL_Rect playerPosition;//rect for the whole sprite sheet
    playerPosition.x=0+50;
    playerPosition.y=340-100;
    playerPosition.w=2*100;
    playerPosition.h=2*100;//ei rec(square) er moddher kothao texture (runman) load hobe

    int textureWidth,textureHeight;
    SDL_QueryTexture(tex,NULL,NULL,&textureWidth,&textureHeight);

    
    struct rect r4(textureWidth/6,textureHeight/6);
    playerRect.x=playerRect.y=0;
    playerRect.w=r4.frmWid;
    playerRect.h=r4.frmHit;
   

    surface = IMG_Load("res/gameover.jpeg");
    if (!surface)
    {
        printf("Green rectangle Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    SDL_Texture *gameover_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    if (!tex)
    {
        printf("Green Rectangle Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    SDL_Rect gameover_rect;
    gameover_rect.w = 400;
    gameover_rect.h = 300;
    gameover_rect.x = (WINDOW_WIDTH - gameover_rect.w) / 2;
    gameover_rect.y = (WINDOW_HEIGHT - gameover_rect.h) / 2 - 150;

    surface =IMG_Load("res/cloudh.png");
    SDL_Texture *cloud_Tex =SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);

    
    SDL_Rect cloud;
    
    cloud.x=0;
    cloud.y=0;
    cloud.w=50;
    cloud.h=50;
    

    surface =IMG_Load("res/bggh.png");
    SDL_Texture *bg_Tex =SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);

    surface =IMG_Load("res/gh.png");
    SDL_Texture *g_Tex =SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
    SDL_Rect  gRect;
    gRect.x=1118;
    gRect.y=125;
    gRect.w=190;
    gRect.h=90;

    surface =IMG_Load("res/rh.png");
    SDL_Texture *r_Tex =SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
    SDL_Rect  rRect;
    rRect.x=1120;
    rRect.y=60;
    rRect.w=190;
    rRect.h=80;

    surface =IMG_Load("res/obs2.png");
    //SDL_Texture *obs_Tex =SDL_CreateTexture(rend,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,150,150);
    SDL_Texture *obs2_Tex =SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
    SDL_Rect  obs2Rect;
    obs2Rect.x=300;
    obs2Rect.y=300;
    obs2Rect.w=230;
    obs2Rect.h=120;

    surface =IMG_Load("res/obs.png");
    //SDL_Texture *obs_Tex =SDL_CreateTexture(rend,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,150,150);
    SDL_Texture *obs_Tex =SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
    SDL_Rect  obsRect;
    obsRect.x=500;
    obsRect.y=500;
    obsRect.w=180;
    obsRect.h=100;

    surface =IMG_Load("res/bomb.png");
    //SDL_Texture *obs_Tex =SDL_CreateTexture(rend,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,150,150);
    SDL_Texture *bomb_Tex =SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
    SDL_Rect  bombRect;
    bombRect.x=198;
    bombRect.y=100;
    bombRect.w=90;
    bombRect.h=50;

    SDL_Rect  bombRect2;
    bombRect2.x=1200;
    bombRect2.y=520;
    bombRect2.w=90;
    bombRect2.h=50;
    
    
    surface =IMG_Load("res/putulh.png");
    SDL_Texture *Putul_Tex =SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
    SDL_Rect  playrRect;
    SDL_Rect playrPosition;
    
    playrPosition.x=1150;
    playrPosition.y=287;
    playrPosition.w=130;
    playrPosition.h=100;

    int texturWidth,texturHeight;
    SDL_QueryTexture(Putul_Tex,NULL,NULL,&texturWidth,&texturHeight);


    struct rect r1(texturWidth/3,texturHeight);
    playrRect.x=playrRect.y=0;
    playrRect.w=r1.frmWid;
    playrRect.h=r1.frmHit;

    surface =IMG_Load("res/fire.png");
    SDL_Texture *fire_Tex =SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);

 
    SDL_Rect  plarRect1;//rect for a single frame of the sprite sheet
    SDL_Rect plarPosition1;//rect for the whole sprite sheet
    plarPosition1.x=250;
    plarPosition1.y=110;
    plarPosition1.w=130;
    plarPosition1.h=130;//ei rec(square) er moddher kothao texture (runman) load hobe
    
    int txturWidth1,txturHeight1;
    SDL_QueryTexture(fire_Tex,NULL,NULL,&txturWidth1,&txturHeight1);

    
    struct rect r2(txturWidth1/10,txturHeight1);
    plarRect1.x=plarRect1.y=0;
    plarRect1.w=r2.frmWid;
    plarRect1.h=r2.frmHit;

    SDL_Rect plarRect2;//rect for a single frame of the sprite sheet
    SDL_Rect plarPosition2;//rect for the whole sprite sheet
    plarPosition2.x=430;
    plarPosition2.y=110;
    plarPosition2.w=130;
    plarPosition2.h=130;

    int txturWidth2,txturHeight2;
    SDL_QueryTexture(fire_Tex,NULL,NULL,&txturWidth2,&txturHeight2);

    
    struct rect r5(txturWidth2/10,txturHeight2);
    plarRect2.x=plarRect2.y=0;
    plarRect2.w=r5.frmWid;
    plarRect2.h=r5.frmHit;
    
    surface =IMG_Load("res/fire2.png");
    SDL_Texture *fire2_Tex =SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);

    SDL_Rect  plarRect22;//rect for a single frame of the sprite sheet
    SDL_Rect plarPosition22;//rect for the whole sprite sheet
    plarPosition22.x=790;
    plarPosition22.y=110;
    plarPosition22.w=130;
    plarPosition22.h=130;//ei rec(square) er moddher kothao texture (runman) load hobe
    
    int txturWidth22,txturHeight22;
    SDL_QueryTexture(fire2_Tex,NULL,NULL,&txturWidth22,&txturHeight22);

  
    struct rect r6(txturWidth2/10,txturHeight2);
    plarRect22.x=plarRect22.y=0;
    plarRect22.w=r6.frmWid;
    plarRect22.h=r6.frmHit;

    SDL_Rect  plarRect3;//rect for a single frame of the sprite sheet
    SDL_Rect plarPosition3;//rect for the whole sprite sheet
    plarPosition3.x=600;
    plarPosition3.y=110;
    plarPosition3.w=130;
    plarPosition3.h=130;//ei rec(square) er moddher kothao texture (runman) load hobe
    
    int txturWidth3,txturHeight3;
    SDL_QueryTexture(fire2_Tex,NULL,NULL,&txturWidth3,&txturHeight3);

    
    struct rect r7(txturWidth1/10,txturHeight1);
    plarRect3.x=plarRect3.y=0;
    plarRect3.w=r7.frmWid;
    plarRect3.h=r7.frmHit;

    surface = IMG_Load("res/replay.png");
    
    SDL_Texture *replay_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

     surface = IMG_Load("res/1.png");
    
    SDL_Texture *a_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect o1;
    o1.x=2400;
    o1.y=365;
    o1.w=100;
    o1.h=100;

    surface = IMG_Load("res/1.png");
    
    SDL_Texture *an_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect o1n;
    o1n.x=340;
    o1n.y=365;
    o1n.w=50;
    o1n.h=50;

    surface = IMG_Load("res/2.png");
    
    SDL_Texture *b_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect o2;
    o2.x=2100;
    o2.y=360;
    o2.w=100;
    o2.h=100;

    surface = IMG_Load("res/4.png");
    
    SDL_Texture *c_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect o3;
    o3.x=400;
    o3.y=340;
    o3.w=140;
    o3.h=150;

    surface = IMG_Load("res/5.png");
    
    SDL_Texture *d_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect o4;
    o4.x=700;
    o4.y=300;
    o4.w=150;
    o4.h=250;

    surface = IMG_Load("res/6.png");
    
    SDL_Texture *e_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect o5;
    o5.x=1000;
    o5.y=250;
    o5.w=250;
    o5.h=250;

    surface = IMG_Load("res/6down.png");
    
    SDL_Texture *ed_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect o5d;
    o5d.x=360;
    o5d.y=310;
    o5d.w=220;
    o5d.h=220;

     surface = IMG_Load("res/7.png");
    
    SDL_Texture *f_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect o6;
    o6.x=1300;
    o6.y=340;
    o6.w=200;
    o6.h=200;

    surface = IMG_Load("res/8.png");
    
    SDL_Texture *g_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect o7;
    o7.x=1650;
    o7.y=360;
    o7.w=180;
    o7.h=180;

    surface = IMG_Load("res/9.png");
    
    SDL_Texture *h_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect o8;
    o8.x=2650;
    o8.y=270;
    o8.w=280;
    o8.h=280;
     surface = IMG_Load("res/9n.png");
    
    SDL_Texture *hn_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect o8n;
    o8n.x=-650;
    o8n.y=-270;
    o8n.w=300;
    o8n.h=300;

    surface = IMG_Load("res/10.png");
    
    SDL_Texture *i_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect o9;
    o9.x=1900;
    o9.y=370;
    o9.w=90;
    o9.h=90;

    surface = IMG_Load("res/coin.png");
    
    SDL_Texture *oc_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect oc;
    oc.x=600;
    oc.y=370;
    oc.w=90;
    oc.h=90;

    
    surface = IMG_Load("res/b49.png");
    
    SDL_Texture *b1_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect b1;
    b1.x=0;
    b1.y=0;
    b1.w=WINDOW_WIDTH;
    b1.h=WINDOW_HEIGHT;

    surface = IMG_Load("res/b50.png");
    
    SDL_Texture *b2_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect b2;
    b2.x=WINDOW_WIDTH;
    b2.y=-29;
    b2.w=WINDOW_WIDTH;
    b2.h=WINDOW_HEIGHT+55;

    surface = IMG_Load("res/b51.png");
    
    SDL_Texture *b3_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect b3;
    b3.x=WINDOW_WIDTH;
    b3.y=0;
    b3.w=WINDOW_WIDTH;
    b3.h=WINDOW_HEIGHT;

    surface = IMG_Load("res/b52.png");
    
    SDL_Texture *b4_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect b4;
    b4.x=WINDOW_WIDTH;
    b4.y=0;
    b4.w=WINDOW_WIDTH;
    b4.h=WINDOW_HEIGHT;
    surface = IMG_Load("res/b5.png");
    SDL_Texture *b5_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect b5;
    b5.x=WINDOW_WIDTH;
    b5.y=0;
    b5.w=WINDOW_WIDTH;
    b5.h=WINDOW_HEIGHT;

    surface = IMG_Load("res/fb.png");
    SDL_Texture *fb_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect fb;
    fb.x=0;
    fb.y=0;
    fb.w=WINDOW_WIDTH;
    fb.h=WINDOW_HEIGHT;

     surface = IMG_Load("res/l.png");
    
    SDL_Texture *lst_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect lst;
    lst.x=WINDOW_WIDTH;
    lst.y=0;
    lst.w=WINDOW_WIDTH;
    lst.h=WINDOW_HEIGHT;

     surface = IMG_Load("res/life.png");
    
    SDL_Texture *life_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect life;
    life.x=WINDOW_WIDTH-60;
    life.y=10;
    life.w=65;
    life.h=50;
    surface = IMG_Load("res/life.png");
    
    SDL_Texture *life2_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect life2;
    life2.x=WINDOW_WIDTH-105;
    life2.y=10;
    life2.w=65;
    life2.h=50;
    surface = IMG_Load("res/life.png");
    
    SDL_Texture *life3_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
     SDL_Rect life3;
    life3.x=WINDOW_WIDTH-150;
    life3.y=10;
    life3.w=65;
    life3.h=50;
    
    surface = IMG_Load("res/nl.png");
    SDL_Texture *nl_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect nl;
    nl.x=WINDOW_WIDTH/2-140;
    nl.y=WINDOW_HEIGHT/2-100;
    nl.w=280;
    nl.h=250;

    surface = IMG_Load("res/monbox.png");
    
    SDL_Texture *monbox_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
     SDL_Rect monboxr;
    monboxr.x=30;
    monboxr.y=0;
    monboxr.w=250;
    monboxr.h=200;
    surface = IMG_Load("res/15.png");
    
    SDL_Texture *f15_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
     SDL_Rect f15;
    f15.x=530;
    f15.y=260;
    f15.w=300;
    f15.h=300;
    surface = IMG_Load("res/16.png");
    
    SDL_Texture *f16_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
     SDL_Rect f16;
    f16.x=530;
    f16.y=260;
    f16.w=300;
    f16.h=300;
    surface = IMG_Load("res/17.png");
    
    SDL_Texture *f17_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect f17;
    f17.x=530;
    f17.y=260;
    f17.w=300;
    f17.h=300;
    surface = IMG_Load("res/18.png");
    
    SDL_Texture *f18_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
     SDL_Rect f18;
    f18.x=530;
    f18.y=260;
    f18.w=300;
    f18.h=300;

    surface = IMG_Load("res/19.png");
    
    SDL_Texture *f19_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect f19;
    f19.x=530;
    f19.y=260;
    f19.w=300;
    f19.h=300;

    surface = IMG_Load("res/20.png");
    
    SDL_Texture *f20_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect f20;
    f20.x=530;
    f20.y=260;
    f20.w=300;
    f20.h=300;

    surface = IMG_Load("res/21.png");
    
    SDL_Texture *f21_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect f21;
    f21.x=530;
    f21.y=260;
    f21.w=300;
    f21.h=300;
    
    surface = IMG_Load("res/failed.png");
    
    SDL_Texture *failed_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect failedr;
    failedr.x=0;
    failedr.y=0;
    failedr.w=WINDOW_WIDTH;
    failedr.h=WINDOW_HEIGHT;
     surface = IMG_Load("res/fp.png");
    
    SDL_Texture *fup_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect fup;
    fup.x=0;
    fup.y=0;
    fup.w=WINDOW_WIDTH;
    fup.h=WINDOW_HEIGHT;


    surface =IMG_Load("res/f.png");
    SDL_Texture *f_Tex =SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);

    SDL_Rect  fRect;//rect for a single frame of the sprite sheet
    SDL_Rect fPosition;//rect for the whole sprite sheet
    fPosition.x=500;
    fPosition.y=350;
    fPosition.w=300;
    fPosition.h=300;//ei rec(square) er moddher kothao texture (runman) load hobe
    
    SDL_Rect fPosition2;//rect for the whole sprite sheet
    fPosition2.x=250;
    fPosition2.y=150;
    fPosition2.w=300;
    fPosition2.h=300;

    int txturWidthf,txturHeightf;
    SDL_QueryTexture(f_Tex,NULL,NULL,&txturWidthf,&txturHeightf);

  
    struct rect rf(txturWidthf/4,txturHeightf/2);
    fRect.x=fRect.y=0;
    fRect.w=rf.frmWid;
    fRect.h=rf.frmHit;

    surface =IMG_Load("res/vanish.png");
    SDL_Texture *v_Tex =SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);

    SDL_Rect  vRect;//rect for a single frame of the sprite sheet
    SDL_Rect  vRectp;
    vRectp.x=0;
    vRectp.y=0;
    vRectp.w=100;
    vRectp.h=100;
    int vtxturWidth,vtxturHeight;
    SDL_QueryTexture(v_Tex,NULL,NULL,&vtxturWidth,&vtxturHeight);

    
    struct rect rv(vtxturWidth/4,vtxturHeight);
    vRect.x=vRect.y=0;
    vRect.w=rv.frmWid;
    vRect.h=rv.frmHit;
    


Mix_Chunk *main;
main=Mix_LoadWAV("res/aud.mp3");
Mix_Chunk *ore1;
ore1=Mix_LoadWAV("res/ore1.mp3");
Mix_Chunk *ore2;
ore2=Mix_LoadWAV("res/ore2.mp3");
Mix_Chunk *ore3;
ore3=Mix_LoadWAV("res/ore3.mp3");
Mix_Chunk *ore4;
ore4=Mix_LoadWAV("res/ore4.mp3");
Mix_Chunk *orena1;
orena1=Mix_LoadWAV("res/orena1.mp3");
Mix_Chunk *orena2;
orena2=Mix_LoadWAV("res/orena2.mp3");
Mix_Chunk *orena3;
orena3=Mix_LoadWAV("res/orena3.mp3");


    SDL_Rect replay_rect;
    replay_rect.w = 300;
    replay_rect.h = 150;
    replay_rect.x = (WINDOW_WIDTH - replay_rect.w) / 2;
    replay_rect.y = (WINDOW_HEIGHT - replay_rect.h) / 2 + 100;
    
    int ox=0,lifecount=0,o1f=0;
    bool isRunning =true;
    float x_pos =0.0,cloudx=0.0;
    int gameover = 1;
    int frameTime=0,FPS=60;
    double count=0,count2=0,tim=0,last=0;
    int timee=0;
    int flast=0;
    int t1,t2;
    int ore=0,frameTime3=0;
    srand(time(NULL));
           int c=rand()%5;
           switch(c){
            case 0:
            t1=4;
            t2=13;
            break;
            case 1:
            t1=4;
            t2=14;
            break;
            case 2:
            t1=5;
            t2=14;
            break;
            case 3:
            t1=3;
            t2=12;
            break;
            case 4:
            t1=5;
            t2=17;
            break;

           }
           
    bool b[2]={0,0};
    //int camx=0,camy=0;
    int bcnt=0;
    int var=2;
    int bf=0,bf2=0;
double bx=0,by=0;
double b2x=0,b2y=0;
int temp=0,f=0,temp2=0;
int money=0;
int failed=0;
int ftham=0;
int ftime;
   
   int lastTime=SDL_GetTicks()/1000;
    
    TTF_Font* ff=TTF_OpenFont( "res/fonts/Oswald-Bold.ttf", 28 );
       int f1,f2,f3,f4,f5,f6,f7;
        srand(time(NULL));
           int cf=rand()%3;
           switch(cf){
            case 0:
             f1=26,f2=6,f3=22,f4=10,f5=14,f6=30,f7=18;
            
            break;
            case 1:
            f2=30,f4=26,f6=6,f7=10,f5=14,f1=18,f3=22;
            break;
            case 2:
            f1=30,f4=26,f3=6,f7=10,f5=14,f6=18,f2=22;
            break;
           

           }

    SDL_Event ev;
while(isRunning){
        int flag=0;
        
         
        
        
         while (SDL_PollEvent(&ev))
        {
            switch (ev.type)
            {
            case SDL_QUIT:
                isRunning=false;
                break;
            case SDL_KEYDOWN:
                switch (ev.key.keysym.scancode)
                {
                  case SDL_SCANCODE_RIGHT:
                  {
                     // b[0]=1;
                     b[1]=1;
                      playerRect.y=0;
                      if(gameover==0)
                      {x_pos = x_pos + (250/ 60);
                      if(playerPosition.x<1180)
                         playerPosition.x= (int)x_pos;
                      else
                        {x_pos=1180;
                         playerPosition.x =1180;}}

                      playerRect.x+=r4.frmWid;
                      if(playerRect.x>=textureWidth)
                        playerRect.x=0;
                    
                    
                   flag=1;
                   if(ftime>=34)
                        ore=10;
                   

                
                    
                  } 
                    break;
                 case SDL_SCANCODE_LEFT:
                 {  //b[1]=1;
                   // b[0]=1;
                    playerRect.y=0;
                     x_pos =  x_pos-(250 / 60);
                    if(x_pos>0)
                     playerPosition.x = (int)x_pos;
                     else
                     {x_pos=0;
                     playerPosition.x =0;}
                       
                      playerRect.x-=r4.frmWid;
                      if(playerRect.x<=0)
                         playerRect.x=textureWidth- r4.frmWid;
                     
                    flag=1;    
                 }
                 break;
                 case SDL_SCANCODE_R:
                     var=5;
                      b[1]=1;
                      if(gameover==0)
                     { x_pos = x_pos + (280/ 60);
                      if(playerPosition.x<1180)
                         playerPosition.x= (int)x_pos;
                      else
                        {x_pos=1180;
                         playerPosition.x =1180;}}
                      playerRect.y=r4.frmHit;
                      playerRect.x+=r4.frmWid;
                      if(playerRect.x>=textureWidth)
                        playerRect.x=0;
                        
                    
                    
                   flag=1;  
                   break;
                 case SDL_SCANCODE_J:
                      var=2;
                      b[1]=1;
                      playerRect.y=2*r4.frmHit;
                       playerRect.x=0;
                       if(!(o5.x<=330&&o5.x>=173))
                      f=1;
                      flag=1; 
                      
                      // playerRect.x+=r4.frmWid;//
                   // if(playerRect.x>=textureWidth-2*r4.frmWid)//
                            //playerRect.x=0;//
                      
                      break;
                    case SDL_SCANCODE_T:
                     if(o5.x<=330&&o5.x>=273)
                     f=1,o5.y=-323, SDL_RenderCopy(rend,ed_tex,NULL,&o5d), o5d.x=360;
    
                     else
                     f=0;
                     // ox=0;
                     var=5;
                      b[1]=1;
                       playerRect.y=5*r4.frmHit;
                      playerRect.x+=r4.frmWid;
                      if(playerRect.x>=textureWidth-r4.frmWid*2)
                        playerRect.x=0;
                       
                      
                      
                       
                   break;
                   case SDL_SCANCODE_UP:
                     playerRect.y=5*r4.frmHit;
                     ore=1;
                        playerRect.x=4*r4.frmWid;

                   break;
                   case SDL_SCANCODE_DOWN:
                     playerRect.y=2*r4.frmHit;
                     ore=0;
                    playerRect.x=5*r4.frmWid;
                    break;
            }
            break;
            case SDL_KEYUP:
                    switch (ev.key.keysym.scancode){
                    case SDL_SCANCODE_RIGHT:
                    b[1]=0;
                    break;
                    case SDL_SCANCODE_J:
                    var=2;
                   // b[1]=0;
                    ///f=0;
                    break;
                     case SDL_SCANCODE_R:
                     var=2;
                    b[1]=0;
                    break;
                   case SDL_SCANCODE_T:
                    b[1]=0;
                    f=0;
                    break;
                   }
                break;

                
            }
        }
      
         vRectp.x=playerPosition.x;
        vRectp.y=playerPosition.y+55;
    
       if (gameover == 0)

        {
           
             SDL_RenderClear(rend);
            

               cloudx =cloudx+0.5;
               cloud.x=(int)cloudx;
            if (cloud.x >= WINDOW_WIDTH)
                cloudx = 0;
     
           frameTime++;

           
           count=SDL_GetTicks() / 1000.0;
          
            tim=count-count2-last;
            timee=tim;
            std::string i=std::to_string(timee);
            SDL_Surface* surface=TTF_RenderText_Solid(ff,i.c_str(),{255,255,255});
            SDL_Texture* texx=SDL_CreateTextureFromSurface(rend,surface);
            SDL_FreeSurface(surface);
    
            SDL_Rect rectt;//for font
            rectt.x=1123;
            rectt.y=225;
            rectt.w=60;
            rectt.h=60;
    
        
           
           if(FPS/frameTime==1)//will be repeated 7 times a second
           {
                        frameTime=0;//repeat
                        fRect.x+=rf.frmWid;
                        if(fRect.x>=txturWidthf-rf.frmWid)
                                        {fRect.x=0;
                                        fRect.y+=rf.frmHit;}
                        if(fRect.y>=txturHeightf-rf.frmHit)
                                        fRect.y=0;

                        playrRect.x+=r1.frmWid;
                        if(playrRect.x>=texturWidth)
                                        {playrRect.x=0;}
                         if(temp2==5){
                         
                    playerRect.y=3*r4.frmHit;
                    playerRect.x+=r4.frmWid;
                    if(playerRect.x>=2*r4.frmWid)
                    {playerRect.x=2*r4.frmWid;  
                   gameover=4; 
                   temp2=6;
                   printf("t%d",temp2);
                   }         
                         }
                        if(f==1){
                            
                             if(temp2==5)
                           f=0;
                            
                            x_pos = x_pos + (1400/ 60);
                            if(playerPosition.x<1180)
                                playerPosition.x= (int)x_pos;
                            else
                               {x_pos=1180;
                                playerPosition.x =1180;}
                      
                           
                            playerRect.x+=r4.frmWid;
                           

                             if(playerRect.x>=textureWidth-2*r4.frmWid)
                            { playerRect.x=textureWidth-r4.frmWid;
                            playerPosition.x= (int)x_pos-600/60;
                             f=0;
                             }
                        }
         
                        plarRect1.x+=r2.frmWid;
                        if(plarRect1.x>=txturWidth1-r2.frmWid)
                                        plarRect1.x=0;
                        
                         vRect.x+=rv.frmWid;
                        if(vRect.x>=vtxturWidth-rv.frmWid)
                                        vRect.x=0;
                            
                        plarRect2.x+=r5.frmWid;
                        if(plarRect2.x>=txturWidth2-r5.frmWid)
                                        plarRect2.x=0;

                        plarRect3.x+=r7.frmWid;
                        if(plarRect3.x>=txturWidth3-r7.frmWid)
                                        plarRect3.x=0;
                        
                        plarRect22.x+=r6.frmWid;
                        if(plarRect22.x>=txturWidth22-r6.frmWid)
                                        plarRect22.x=0;
                            
          
          }
           
            SDL_RenderCopy(rend,bg_Tex,NULL,NULL);
            
            SDL_RenderCopy(rend,cloud_Tex,NULL,&cloud);

            SDL_RenderCopy(rend,tex,&playerRect,&playerPosition);
            SDL_RenderCopy(rend,Putul_Tex,&playrRect,&playrPosition);
             
            SDL_RenderCopy(rend,texx,NULL,&rectt);
            SDL_RenderCopy(rend,fire_Tex,&plarRect1,&plarPosition1);
            SDL_RenderCopy(rend,fire_Tex,&plarRect2,&plarPosition2);
            SDL_RenderCopy(rend,fire2_Tex,&plarRect22,&plarPosition22);
            SDL_RenderCopy(rend,fire2_Tex,&plarRect3,&plarPosition3);
           
            if(((playerPosition.x-350)*(playerPosition.x-350)+(playerPosition.y-200)*(playerPosition.y-245))<1)
            {SDL_RenderCopy(rend,v_Tex,&vRect,&vRectp);
            gameover=4;
            temp=1;
            
            }
            if(tim>3){
              bx+=0.1;
              by+=0.1;
                 if(bombRect.x<350){
           
                    bombRect.x+=(int)bx;
                    bombRect.y-=(int)by;
                 }
                 else
                {
           
                  bombRect.x+=(int)bx;
                  bombRect.y+=(int)by;
                }
            
                
                if(!(bombRect.x>=500&&bombRect.y>=500)){
           
                 SDL_RenderCopy(rend, bomb_Tex, NULL,&bombRect);
                }
                 if(tim>5&&tim<7)
                SDL_RenderCopy(rend,f_Tex,&fRect,&fPosition);
                if(tim>6.5)
                SDL_RenderCopy(rend, obs_Tex, NULL,&obsRect);
           

           }
           if(tim>7){
          
             b2x+=0.1;
              b2y+=0.1;
              if(bombRect2.x>650){
           
                bombRect2.x-=(int)b2x;
                bombRect2.y-=(int)b2y;
              }
              else
              {
           
                bombRect2.x-=(int)b2x;
                bombRect2.y+=(int)(b2y-0.05);
              }
            
              if(!(bombRect2.x<=300&&bombRect2.y>=180)){
           
               SDL_RenderCopy(rend, bomb_Tex, NULL,&bombRect2);
               }
              if(tim>9&&tim<11)
              SDL_RenderCopy(rend,f_Tex,&fRect,&fPosition2);
              if(tim>10.5)
              SDL_RenderCopy(rend, obs2_Tex, NULL,&obs2Rect);
           
           }
            
        
           
           if (timee >=t1&&timee<=t1+3||timee >=t2&&timee<=t2+4||timee>=22){

            Mix_HaltChannel(-1);
            SDL_RenderCopy(rend,r_Tex,NULL,&rRect);
                if(flag||timee>=22){
                   
                    deadman.x = 350;
                    deadman.y = playerPosition.y;
                    SDL_SetRenderDrawColor(rend, 0,0,0,0);
                    for(int i=0;i<7;i++)
                    SDL_RenderDrawLine(rend, 1200, 600 , playerPosition.x+i+100,playerPosition.y+i+50);
                    
                    SDL_SetRenderDrawColor(rend, 0,0,0,0);
                        
                    



                   
                    //SDL_RenderCopy(rend, deadmanTex, NULL, &deadman);
                    
                   //gameover=4;
                   //playerRect.x=0;
                    temp++;
                    //temp=1;
                    
               
                }
                //else
                 // { SDL_RenderCopy(rend,tex,&playerRect,&playerPosition);
               
                 // }
                 if(temp==1){
                    playerRect.x=0;
                    temp2=5;
                    //temp=0;

                 }
             
            }
            
            
            else
            {
               //SDL_RenderCopy(rend,tex,&playerRect,&playerPosition);
               SDL_RenderCopy(rend,g_Tex,NULL,&gRect);
            
               Mix_PlayChannel(-1,main,0);
            
            }
       
        
           if(playerPosition.x>=1100)
            {
                SDL_Delay(1500);

                playerPosition.y=100;
                gameover=2;
                Mix_HaltChannel(-1);
            }
        SDL_RenderPresent(rend);
        }
       else if(temp2==6)
           {
            SDL_Delay(2000);
           SDL_RenderClear(rend);
            //temp2=11;
             Mix_HaltChannel(-1);
            temp2=22;
            printf("hello");
            }
        else if(gameover==10){
            //gameover=0;
            frameTime++;
            //playerPosition.x=100;
             SDL_RenderClear(rend);
             
             SDL_RenderCopy(rend,b1_tex,NULL,&b1);
             SDL_RenderCopy(rend,b2_tex,NULL,&b2);
             SDL_RenderCopy(rend,b3_tex,NULL,&b3);
             SDL_RenderCopy(rend,b4_tex,NULL,&b4);
              SDL_RenderCopy(rend,b5_tex,NULL,&b5);
            
            
             SDL_RenderCopy(rend,life_tex,NULL,&life);
             SDL_RenderCopy(rend,life2_tex,NULL,&life2);
             SDL_RenderCopy(rend,life3_tex,NULL,&life3);
              SDL_RenderCopy(rend,g_tex,NULL,&o7);
              SDL_RenderCopy(rend,a_tex,NULL,&o1);
              SDL_RenderCopy(rend,b_tex,NULL,&o2);
               SDL_RenderCopy(rend,c_tex,NULL,&o3);
                SDL_RenderCopy(rend,d_tex,NULL,&o4);
                 SDL_RenderCopy(rend,e_tex,NULL,&o5);
                  SDL_RenderCopy(rend,f_tex,NULL,&o6);
                  
                 SDL_RenderCopy(rend,h_tex,NULL,&o8);
                  SDL_RenderCopy(rend,i_tex,NULL,&o9);
                  SDL_RenderCopy(rend,oc_tex,NULL,&oc);
                  SDL_RenderCopy(rend,f_Tex,&fRect,&fPosition);
                  SDL_RenderCopy(rend,hn_tex,NULL,&o8n);
                  
           
             
            
                 // if(b[0]){
                //camx+=5;
                //b1.x+=5;
                //if(b1.x>=1500)
                //b1.x=0;
           // }
           // else
           //frameTime++;
           //if(frameTime==60)
         // printf("%d",b[1]);
                if(40/frameTime==1){
                    frameTime=0;
                    if(o1f==1){
                        playerRect.y=4*r4.frmHit;
                        playerRect.x+=r4.frmWid;
                   //playerPosition.x+=10;
                    if(playerRect.x>=textureWidth)
                            {playerRect.x=textureWidth-r4.frmWid;
                        SDL_RenderCopy(rend,an_tex,NULL,&o1n);
                         if(o1n.y>=150&&o1n.x>=500)
                         o1n.x+=50,o1n.y+=50;
                         else
                          o1n.x+=50,o1n.y-=50;
                         if(o1n.y>=370)
                         o1n.y=351,o1f=0,o1n.x=450;}

                         }
                        //static int fp=200;
                    if(o1n.x==450&&o1n.y==351){ 
                        fPosition.x=650;
                       fPosition.y=200;
                        
                         fRect.x+=rf.frmWid;
                        if(fRect.x>=txturWidthf)
                                        {fRect.x=0;
                                        fRect.y+=rf.frmHit;}
                        if(fRect.y>=txturHeightf)
                                        {fRect.y=0,fPosition.y=-400;
                                        o8.y=-400;
                                         }
                            


                    }
                    if(o8.y==-400)
                    o8n.x=600,o8n.y=270,o8.y=-401,o1n.y=-351;
                    
               
          
                    
                         
                   if(f==1&&b[1]==1)
           
           //printf("A%d",frameTime);
                        //frameTime=0;
                
                   // frameTime=0;
                    
                    
                     //playerPosition.y=342;
                   { playerRect.x+=r4.frmWid;
                   //playerPosition.x+=10;
                    if(playerRect.x>=textureWidth)
                            {playerRect.x=textureWidth-r4.frmWid;
                            //playerPosition.y=340;
                            b[1]=0;
                            f=0;
                            }
                            }
               
                }

             if(b[1]){
           
                b1.x-=var;
                o2.x-=var;
                o3.x-=var;
                o4.x-=var;
                o5.x-=var;
                o6.x-=var;
                o7.x-=var;
                o8.x-=var;
                o8n.x-=var;
                o9.x-=var;
                o1.x-=var;
                oc.x-=var;
                if(b1.x<=0)
                b2.x-=var;
                if(b2.x<=0)
                b3.x-=var;

                if(b3.x<=2&&b3.x>=-20&&bf==0)
                {
                 
                 b2.x=WINDOW_WIDTH;
                 b2.y=-27;
                 b3.x=0;
                 bf=1;
                 oc.x=890;
                 oc.y=370;

                 
                // if(b2.x<=5)
                //b3.x-=5;
               
                 
                }
                else if(b3.x<2)
                {b3.x-=var;
                if(b3.x<-20)
                bf=0;}
                
                if(b2.x<=0&&b2.x>=-20&&b1.x<0&&bf2==0)
                {  
                     bcnt++;
                    if(bcnt<3)
                    b3.x=WINDOW_WIDTH-8,oc.x=WINDOW_WIDTH+300,oc.y=370;;
                    bf2=1;
                    
                    //b2.x-=5;
                }
                if(b2.x<-20)
                bf2=0;
                if(bcnt>=3)
                b4.x-=var;
                if(b4.x<=0)
                b5.x-=var;
                if(b4.x<=-500){
                   // SDL_DestroyTexture(a_tex);
                   // SDL_DestroyTexture(h_tex);
                    playerPosition.x=-100;
                   
                        lst.x=0;
                 
                   
                }
             
            }
              
            if(o8.x==WINDOW_WIDTH-50&&b4.x>800){
                
                o3.x=400+1200;
                o3.y=340;
                o4.x=700+1200;
                o4.y=300;
                
                o5.x=1000+1200;
                o5.y=250;
                o6.x=1300+1200;
                o6.y=340;

               
               

            }
            if(o8.x==0&&b4.x>800)
            {
               o7.x=1593;
                o7.y=360;
                o1.x=2400;
                o1.y=365;
                o2.x=2100;
                o2.y=360;
                 o9.x=1900;
                o9.y=370;
            }
            if(o8.x<-150&&b4.x>800){
                o8.x=2430;
                o8.y=250;
            }
             ///if(o1.x<=340)
             ///{o1.y-=2;
             ///if(o1.y<=245)
             ///o1.y=250;
             ///o1.x=341;}

             

            
            if(o3.x<=330&&o3.x>=214||o4.x<=330&&o4.x>=208||o5.x<=330&&o5.x>=173||o6.x<=330&&o6.x>=214||o7.x<=290&&o7.x>=210||o8.x<=290&&o8.x>=160||o9.x<=340&&o9.x>=208){
                if(f==0){
                    SDL_SetTextureColorMod(tex,255,0,0);
                   // SDL_SetTextureColorMod(life_tex,0,0,0);
                    if((o3.x==330||o4.x==330||o5.x==330||o6.x==330||o7.x==330||o8.x==330||o9.x==330)&&ox==0)
                    ox=1,lifecount++;
                    if(lifecount==1)
                    SDL_SetTextureColorMod(life_tex,0,0,0);
                    if(lifecount==2)
                    SDL_SetTextureColorMod(life2_tex,0,0,0);
                    if(lifecount==3)
                    SDL_SetTextureColorMod(life3_tex,0,0,0), failed=1;
                    
                }
                 else
                SDL_SetTextureColorMod(tex,255,255,255),ox=0;
                
            }
            else
                SDL_SetTextureColorMod(tex,255,255,255),ox=0;


             if(o2.x<=330&&o2.x>=208){
               // printf("%d",f);
                //if(f==0){
                    
                    o2.y-=10;
                    if(o2.y==200)
                    money=money+70;
                    // printf("%d",ox);
                    
                    ///if(o2.x==330&&ox==0)
                    ///money=money+70,ox=1;
                    ///else
                    ///ox=0;
                //}
                
                
            }
               if(oc.x<=330&&oc.x>=214){
                //if(f==0){
                    oc.y-=10;
                 
                    
                    if(oc.x==330&&ox==0)
                    money=money+10,ox=1;
                    else 
                    ox=0;
               // }
                
                
            }
            if(o5.y==-323)
            {SDL_RenderCopy(rend,ed_tex,NULL,&o5d);
            if(b[1])
            o5d.x-=var;
            if(o5.x==-200)
            o5.y=250;
            

            }
            
                
            std::string i=std::to_string(money);
            SDL_Surface* surface=TTF_RenderText_Solid(ff,i.c_str(),{255,165,0});
            SDL_Texture* moneytex=SDL_CreateTextureFromSurface(rend,surface);
            SDL_FreeSurface(surface);
    
            SDL_Rect moneyr;//for font
            moneyr.x=158;
            moneyr.y=89;
            moneyr.w=60;
            moneyr.h=60;
            SDL_RenderCopy(rend,monbox_tex,NULL,&monboxr);
             SDL_RenderCopy(rend,moneytex,NULL,&moneyr);
         
               

            //printf("p%d\n",o1.x);
            
            int mousx, mousy;
           // int tham=1;
            int button = SDL_GetMouseState(&mousx, &mousy);
            //printf("%d %d\n", mousx, mousy);
            if(o1.x<-2750)
            o1.y=380,o1.x=380;
            if (button & SDL_BUTTON(SDL_BUTTON_LEFT))
            {
                if (mousx >= nl.x && mousx <= (nl.x +nl.w) && mousy >=nl.y && mousy <= (nl.y +nl.h))
                {
                    if(lst.x==0)
                    {gameover =0;
                    fPosition.x=500;
                    fPosition.y=350;
                    playerPosition.x=0;
                    playerPosition.y=400;
                    playerRect.x=playerRect.y=0;
                    f=0;
                    flag=0;
                    frameTime=0;
                    }

                    last=SDL_GetTicks()/1000;                   
                }
               // if(o1.y==250)
                
                    if (mousx >= o1.x && mousx <= (o1.x +o1.w) && mousy >=o1.y && mousy <= (o1.y +o1.h))
                        //o1.x=330;
                         o1f=1,o1.y=-400,playerRect.x=0, o1n.x=340,o1n.y=365;
    
                   // }
                    //if(o1.y==251){  
                         
                        

                         


                         
               
            }
             SDL_RenderCopy(rend,tex,&playerRect,&playerPosition);
                 if(failed==1){
                SDL_RenderClear(rend);
                SDL_RenderCopy(rend,failed_tex,NULL,&failedr);
               }  
               if(lst.x==0)
                SDL_RenderClear(rend), SDL_RenderCopy(rend,lst_tex,NULL,&lst), SDL_RenderCopy(rend,nl_tex,NULL,&nl);
                SDL_RenderPresent(rend);
           
            
            }
        else if(gameover==4&&temp2==22){
            //SDL_Delay(2000);
            SDL_RenderClear(rend);
            
            SDL_RenderCopy(rend,againTex,NULL,NULL);
             SDL_RenderPresent(rend);

            int mousex, mousey;
            int buttons = SDL_GetMouseState(&mousex, &mousey);
           

            if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
            {
                if (mousex >= WINDOW_WIDTH/3.5 && mousex <= WINDOW_WIDTH/1.5 && mousey >= WINDOW_HEIGHT/3.5&& mousey <= WINDOW_HEIGHT/1.5)
                {
                    gameover = 0;
                    x_pos=0.0;
                    count2=SDL_GetTicks() / 1000-last;
                   playerPosition.x=0;
                   playerPosition.y=400;
                   playerRect.x=playerRect.y=0;
                   bx=0;
                   by=0;
                   b2x=0;
                   b2y=0;
                    bombRect.x=98;
                    bombRect.y=505;
                     bombRect2.x=1120;
                     bombRect2.y=520;
                     temp=0;
                    
                   
                }
            }


        }
    else if(gameover==100){
        SDL_RenderCopy(rend,fb_tex,NULL,&fb);
         SDL_RenderCopy(rend,tex,&playerRect,&playerPosition);
        frameTime3++;
        if(60/frameTime3==1){
            frameTime3=0;
            if(ore==1)
           { playerRect.x+=r4.frmWid;
           if(playerRect.x>=textureWidth)
           playerRect.x=4*r4.frmWid;}
           if(playerRect.y==3*r4.frmHit&&playerRect.x==4*r4.frmWid)
           ftham=1,gameover=101;
                
         
         }
     
         


            ftime=SDL_GetTicks()/1000-flast;
        
            std::string i=std::to_string(ftime);
            SDL_Surface* surface=TTF_RenderText_Solid(ff,i.c_str(),{255,255,255});
            SDL_Texture* texx=SDL_CreateTextureFromSurface(rend,surface);
            SDL_FreeSurface(surface);
            SDL_Rect ftr;//for font
            ftr.x=358;
            ftr.y=89;
            ftr.w=60;
            ftr.h=60;
             int ftim=ftime;
             if(ftime ==1)ftim =3;
              if(ftime==2)ftim =2;
               if(ftime ==3)ftim =1;
                if(ftime ==4)ftim =0;

             
        
            std::string fi=std::to_string(ftim);
            SDL_Surface* fsurface=TTF_RenderText_Solid(ff,fi.c_str(),{255,255,255});
            SDL_Texture* ftex=SDL_CreateTextureFromSurface(rend,fsurface);
            SDL_FreeSurface(fsurface);
            SDL_Rect fr;//for font
            fr.x=500;
            fr.y=120;
            fr.w=260;
            fr.h=260;
            if(ftime>4)
            SDL_DestroyTexture(ftex);
            
            if(ftime>=f1&&ftime<=f1+2)
            {   SDL_RenderCopy(rend,f18_tex,NULL,&f15);
            if(ftime<f1+2)
                Mix_PlayChannel(-1,ore1,0);
            if(ore==0&&ftime==f1+2){playerRect.y=3*r4.frmHit;
             SDL_SetRenderDrawColor(rend, 0,0,0,0);
                    for(int i=0;i<7;i++)
                    SDL_RenderDrawLine(rend, 1075, 160 , playerPosition.x+i+100,playerPosition.y+i+50);
                    
                    SDL_SetRenderDrawColor(rend, 0,0,0,0);}
            }
            else if(ftime>=f3&&ftime<=f3+2)
            { SDL_RenderCopy(rend,f20_tex,NULL,&f20);
            if(ftime<f3+2)
                Mix_PlayChannel(-1,ore2,0);
            if(ore==0&&ftime==f3+2){playerRect.y=3*r4.frmHit;
             SDL_SetRenderDrawColor(rend, 0,0,0,0);
                    for(int i=0;i<7;i++)
                    SDL_RenderDrawLine(rend, 1075, 160 , playerPosition.x+i+100,playerPosition.y+i+50);
                    
                    SDL_SetRenderDrawColor(rend, 0,0,0,0);}
             }
            else if(ftime>=f4&&ftime<=f4+2)
            { SDL_RenderCopy(rend,f19_tex,NULL,&f19);
            if(ftime<f4+2)
                Mix_PlayChannel(-1,ore3,0);
            if(ore==0&&ftime==f4+2){playerRect.y=3*r4.frmHit;
             SDL_SetRenderDrawColor(rend, 0,0,0,0);
                    for(int i=0;i<7;i++)
                    SDL_RenderDrawLine(rend,1075, 160 , playerPosition.x+i+100,playerPosition.y+i+50);
                    
                    SDL_SetRenderDrawColor(rend, 0,0,0,0);}
            }
            else if(ftime>=f5&&ftime<=f5+2)
           {SDL_RenderCopy(rend,f21_tex,NULL,&f21);
           if(ftime<f5+2)
             Mix_PlayChannel(-1,ore4,0);
            if(ore==0&&ftime==f5+2){playerRect.y=3*r4.frmHit;
           SDL_SetRenderDrawColor(rend, 0,0,0,0);
                    for(int i=0;i<7;i++)
                    SDL_RenderDrawLine(rend, 1075, 160  , playerPosition.x+i+100,playerPosition.y+i+50);
                    
                    SDL_SetRenderDrawColor(rend, 0,0,0,0);}
           }
            else if(ftime>=f6&&ftime<=f6+2)
            {   SDL_RenderCopy(rend,f16_tex,NULL,&f16);
            if(ftime<f6+2)
                Mix_PlayChannel(-1,orena1,0);
            if(ore==1&&ftime==f6+2){playerRect.y=3*r4.frmHit;
            SDL_SetRenderDrawColor(rend, 0,0,0,0);
                    for(int i=0;i<7;i++)
                    SDL_RenderDrawLine(rend, 1075, 160 , playerPosition.x+i+100,playerPosition.y+i+50);
                    
                    SDL_SetRenderDrawColor(rend, 0,0,0,0);}
            
            }
            else if(ftime>=f7&&ftime<=f7+2)
           {SDL_RenderCopy(rend,f17_tex,NULL,&f17);
           if(ftime<f7+2)
            Mix_PlayChannel(-1,orena2,0);
            if(ore==1&&ftime==f7+2){playerRect.y=3*r4.frmHit;
            SDL_SetRenderDrawColor(rend, 0,0,0,0);
                    for(int i=0;i<7;i++)
                    SDL_RenderDrawLine(rend, 1075, 160  , playerPosition.x+i+100,playerPosition.y+i+50);
                    
                    SDL_SetRenderDrawColor(rend, 0,0,0,0);}
             }
            else if(ftime>=f2&&ftime<=f2+2)
            {SDL_RenderCopy(rend,f15_tex,NULL,&f15);
            if(ftime<f2+2)
                Mix_PlayChannel(-1,orena3,0);
            if(ore==1&&ftime==f2+2){playerRect.y=3*r4.frmHit;
             SDL_SetRenderDrawColor(rend, 0,0,0,0);
                    for(int i=0;i<7;i++)
                    SDL_RenderDrawLine(rend, 1075, 160  , playerPosition.x+i+100,playerPosition.y+i+50);
                    
                    SDL_SetRenderDrawColor(rend, 0,0,0,0);}
            }
    
           
             SDL_RenderCopy(rend,texx,NULL,&ftr);

             SDL_RenderCopy(rend,ftex,NULL,&fr);
   


        if(ftham==1)
         SDL_Delay(2000),SDL_RenderClear(rend),SDL_RenderCopy(rend,failed_tex,NULL,&failedr),Mix_HaltChannel(-1);
         else if(ftime>=34)
         {SDL_RenderClear(rend),SDL_RenderCopy(rend,fup_tex,NULL,&fup),Mix_HaltChannel(-1);
         if(ore==10){
        playerPosition.x=300;
        fPosition.x=-500;
        fPosition.y=-350;
      
         playerPosition.y=340;
         playerPosition.w=100;
         playerPosition.h=100;
         gameover=10; }
         //printf("%d",ore);
         }

         

         SDL_RenderPresent(rend);



    }
    else if(gameover==1)
    {
        SDL_RenderClear(rend);
        SDL_RenderCopy(rend,sTex,NULL,NULL);
        SDL_RenderCopy(rend, tex3, NULL, &start_rect);
        SDL_RenderPresent(rend);
    
        int mousx, mousy;
            int button = SDL_GetMouseState(&mousx, &mousy);
            //printf("%d %d\n", mousx, mousy);

            if (button & SDL_BUTTON(SDL_BUTTON_LEFT))
            {
                if (mousx >= start_rect.x && mousx <= (start_rect.x + start_rect.w) && mousy >= start_rect.y && mousy <= (start_rect.y + start_rect.h))
                {
                    
                    gameover=100;
                    playerPosition.x=300;
                    fPosition.x=-500;
                  fPosition.y=-350;
                    flast=SDL_GetTicks()/1000;                   
                }
              
            }
    }
    else if(gameover==2)
    {

            SDL_RenderClear(rend);
            SDL_RenderCopy(rend, gameover_tex, NULL, &gameover_rect);
            SDL_RenderCopy(rend, replay_tex, NULL, &replay_rect);

            

          

            SDL_RenderPresent(rend);

            int mousex, mousey;
            int buttons = SDL_GetMouseState(&mousex, &mousey);
            //printf("%d %d\n", mousex, mousey);

            if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
            {
                if (mousex >= replay_rect.x && mousex <= (replay_rect.x + replay_rect.w) && mousey >= replay_rect.y && mousey <= (replay_rect.y + replay_rect.h))
                {

                  count2=SDL_GetTicks() / 1000-last;
                    gameover = 0;
                    x_pos=0.0;
                   
                   playerPosition.x=0;
                   playerPosition.y=400;
                   playerRect.x=playerRect.y=0;
                   bx=0;
                   by=0;
                    b2x=0;
                   b2y=0;
                     bombRect.x=98;
                     bombRect.y=505;
                     bombRect2.x=1120;
                     bombRect2.y=520;
                     temp=0;
                    
                   
                }
            }
     }
}
    

    SDL_Delay(100);
    Mix_FreeChunk(main);
    Mix_FreeChunk(ore1);
    Mix_FreeChunk(ore2);
    Mix_FreeChunk(ore3);
    Mix_FreeChunk(ore4);
    //SDL_CloseAudioDevice(deviceId);
    //SDL_FreeWAV(wavBuffer);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    Mix_Quit();
    SDL_Quit();
    return 0;
}

