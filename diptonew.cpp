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

    if (!rend)
    {
        printf("renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    SDL_Surface *surface = IMG_Load("res/dip.jpg");
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

    surface = IMG_Load("res/deadman.png");
    SDL_Texture *deadmanTex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect deadman;
    deadman.w = 150;
    deadman.h = 150;
    surface = IMG_Load("res/playAgain.png");
    SDL_Texture *againTex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    
    surface = IMG_Load("res/start.jpg");
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
    
    surface = IMG_Load("res/char.png");
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
    playerPosition.x=0;
    playerPosition.y=400;
    playerPosition.w=100;
    playerPosition.h=100;//ei rec(square) er moddher kothao texture (runman) load hobe

    int textureWidth,textureHeight;
    SDL_QueryTexture(tex,NULL,NULL,&textureWidth,&textureHeight);

    
    struct rect r4(textureWidth/6,textureHeight/5);
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

    SDL_Rect replay_rect;
    replay_rect.w = 300;
    replay_rect.h = 150;
    replay_rect.x = (WINDOW_WIDTH - replay_rect.w) / 2;
    replay_rect.y = (WINDOW_HEIGHT - replay_rect.h) / 2 + 100;
    

    bool isRunning =true;
    float x_pos =0.0,cloudx=0.0;
    int gameover = 1;
    int frameTime=0,FPS=60;
    double count=0,count2=0,tim=0,last=0;
    int timee=0;
    int t1,t2;
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
           
    
double bx=0,by=0;
double b2x=0,b2y=0;
int temp=0,f=0,temp2=0;
   
   int lastTime=SDL_GetTicks()/1000;
    
    TTF_Font* ff=TTF_OpenFont( "res/fonts/Oswald-Bold.ttf", 28 );

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
                      playerRect.y=0;
                      x_pos = x_pos + (250/ 60);
                      if(playerPosition.x<1180)
                         playerPosition.x= (int)x_pos;
                      else
                        {x_pos=1180;
                         playerPosition.x =1180;}

                      playerRect.x+=r4.frmWid;
                      if(playerRect.x>=textureWidth-r4.frmWid)
                        playerRect.x=0;
                    
                    
                   flag=1;
                   

                
                    
                  } 
                    break;
                 case SDL_SCANCODE_LEFT:
                 {
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
                    
                      x_pos = x_pos + (280/ 60);
                      if(playerPosition.x<1180)
                         playerPosition.x= (int)x_pos;
                      else
                        {x_pos=1180;
                         playerPosition.x =1180;}
                      playerRect.y=r4.frmHit;
                      playerRect.x+=r4.frmWid;
                      if(playerRect.x>=textureWidth-r4.frmWid)
                        playerRect.x=0;
                    
                    
                   flag=1;  
                   break;
                 case SDL_SCANCODE_J:
                      playerRect.y=2*r4.frmHit;
                       playerRect.x=0;
                      f=1;
                      flag=1; 
                      break;
                   

                }
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
       
        
           if(playerPosition.y<=100)
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
    else if(gameover==1)
    {
        SDL_RenderClear(rend);
        SDL_RenderCopy(rend, tex3, NULL, &start_rect);
        SDL_RenderPresent(rend);
    
        int mousx, mousy;
            int button = SDL_GetMouseState(&mousx, &mousy);
            //printf("%d %d\n", mousx, mousy);

            if (button & SDL_BUTTON(SDL_BUTTON_LEFT))
            {
                if (mousx >= start_rect.x && mousx <= (start_rect.x + start_rect.w) && mousy >= start_rect.y && mousy <= (start_rect.y + start_rect.h))
                {
                  
                    gameover = 0;
                    last=SDL_GetTicks()/1000;                   
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
    //SDL_CloseAudioDevice(deviceId);
    //SDL_FreeWAV(wavBuffer);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);

    SDL_Quit();
    return 0;
}
