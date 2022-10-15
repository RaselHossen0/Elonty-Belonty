#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h>

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
    SDL_Delay(1000/2);
    
    
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
    
   

    

    surface = IMG_Load("res/runman.png");
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
    if (!tex)
    {
        printf("Redline Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    SDL_Rect  playerRect;
    SDL_Rect playerPosition;
    playerPosition.x=0;
    playerPosition.y=400;
    playerPosition.w=playerPosition.h=320;

    

    int frameWidth,frameHeight;
    int textureWidth,textureHeight;
    SDL_QueryTexture(tex,NULL,NULL,&textureWidth,&textureHeight);

     frameWidth=textureWidth/4;
    frameHeight=textureHeight/2;
    playerRect.x=playerRect.y=0;
    playerRect.w=frameWidth;
    playerRect.h=frameHeight;
   // SDL_SetRenderDrawColor(rend,0xFF,0,0,0xFF);

    

    

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

    surface = IMG_Load("res/replay.png");
    if (!surface)
    {
        printf("replay Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    SDL_Texture *replay_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    if (!tex)
    {
        printf("replayTexture %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
 SDL_Init(SDL_INIT_AUDIO);
  SDL_AudioSpec wavSpec;
Uint32 wavLength;
Uint8 *wavBuffer;
 
SDL_LoadWAV("res/background.wav", &wavSpec, &wavBuffer, &wavLength);
SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
 //   SDL_Rect dest;
 //  SDL_QueryTexture(tex2, NULL, NULL, &dest.w, &dest.h);

int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
SDL_PauseAudioDevice(deviceId, 0);

SDL_Delay(1000);
    SDL_Rect replay_rect;
    replay_rect.w = 300;
    replay_rect.h = 150;
    replay_rect.x = (WINDOW_WIDTH - replay_rect.w) / 2;
    replay_rect.y = (WINDOW_HEIGHT - replay_rect.h) / 2 + 100;

   bool isRunning =true;
    float x_pos = 0;
    int gameover = 1;
    int frameTime=0,FPS=60;

    SDL_Event ev;
    while(isRunning){
        
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
            case SDL_SCANCODE_LEFT:
                  {
                    x_pos =  x_pos - (900 / 60);
                    if(x_pos>0)
                     playerPosition.x = (int)x_pos;
                    else
                       {x_pos=0;
                        playerPosition.x =0;}
                        playerRect.x-=frameWidth;
                    if(playerRect.x<=0)
                        playerRect.x=0;
                    if(playerRect.y>0&&playerRect.x==0)
                        {playerRect.y-=frameHeight;
                         playerRect.x=textureWidth-frameWidth;}
                    if(playerRect.y==0&&playerRect.x==0)
                       {playerRect.x=textureWidth-frameWidth;
                        playerRect.y=textureHeight-frameHeight;}

                
                    }
                    
                    break;
            case SDL_SCANCODE_RIGHT:
                 {
                         x_pos = x_pos + (900 / 60);
                      if(x_pos<1150)
                         playerPosition.x = (int)x_pos;
                      else
                        {x_pos=1150;
                         playerPosition.x =1150;}

                      playerRect.x+=frameWidth;
                      if(playerRect.x>=textureWidth)
                        {playerRect.x=0;
                         playerRect.y+=frameHeight;}
                      if(playerRect.y>=textureHeight)
                         playerRect.y=0;
                 }
                }
            }
        }
      
        
    
       if (gameover == 0)
        {
           frameTime++;
           if(FPS/frameTime==1)//will be repeated 7 times a second
          {
            frameTime=0;//repeat
          
          }
       

            //SDL_SetRenderDrawColor(rend,0xFF,0xFF,0xFF,0xFF);
            SDL_SetRenderDrawColor(rend,0xFF,0,0,0xFF);
            SDL_RenderClear(rend);
            SDL_SetRenderDrawColor(rend,0x00,0x00,0x00,0x00);
            for(int i=0;i<5;i++)
            SDL_RenderDrawLine(rend,1200+i,1100+i,900+i,300+i);
             //SDL_RenderDrawLine(rend,1201,1101,901,301);
            // SDL_RenderDrawLine();
            //SDL_RenderClear(rend);
            SDL_RenderCopy(rend,tex,&playerRect,&playerPosition);
            SDL_RenderPresent(rend);
        
           
            if(playerPosition.x>=WINDOW_WIDTH*0.75)
            {playerPosition.x=WINDOW_WIDTH*0.75;
            gameover=2;
            }
        }
        else if(gameover==1)
    {
        SDL_RenderClear(rend);
    SDL_RenderCopy(rend, tex3, NULL, &start_rect);
    SDL_RenderPresent(rend);
    //SDL_Delay(3000);
        int mousx, mousy;
            int button = SDL_GetMouseState(&mousx, &mousy);
            //printf("%d %d\n", mousx, mousy);

            if (button & SDL_BUTTON(SDL_BUTTON_LEFT))
            {
                if (mousx >= start_rect.x && mousx <= (start_rect.x + start_rect.w) && mousy >= start_rect.y && mousy <= (start_rect.y + start_rect.h))
                {
                  
                    gameover = 0;
                   
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
                    gameover = 0;
                    x_pos=0;
                   playerPosition.x=0;
                   playerPosition.y=400;
                   playerRect.x=playerRect.y=0;
                    
                   
                }
            }
        }
    }
    

    SDL_Delay(100);
    SDL_CloseAudioDevice(deviceId);
    SDL_FreeWAV(wavBuffer);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);

    SDL_Quit();
    return 0;
}
