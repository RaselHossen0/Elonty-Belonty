
    #include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
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
    SDL_Init(SDL_INIT_AUDIO);

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

    //Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,1024);
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
				{
					printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
					//success = false;
				}
   Mix_Music *music=Mix_LoadMUS("res/replay.mp3");
    Mix_Chunk *replay=Mix_LoadWAV("res/music.wav");
    Mix_Chunk *replay1=Mix_LoadWAV("res/game_over.wav");
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
    
   

    

    surface = IMG_Load("res/man1.png");
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

    SDL_Rect  playerRect;//rect for a single frame of the sprite sheet
    SDL_Rect playerPosition;//rect for the whole sprite sheet
    playerPosition.x=450;
    playerPosition.y=550;
    playerPosition.w=150;
    playerPosition.h=150;//ei rec(square) er moddher kothao texture (runman) load hobe

    

    int frameWidth,frameHeight;
    int textureWidth,textureHeight;
    SDL_QueryTexture(tex,NULL,NULL,&textureWidth,&textureHeight);

    frameWidth=textureWidth/9;
    frameHeight=textureHeight;
    playerRect.x=playerRect.y=0;
    playerRect.w=frameWidth;
    playerRect.h=frameHeight;
     SDL_Rect  boy2;//rect for a single frame of the sprite sheet
    SDL_Rect boy2_pos;//rect for the whole sprite sheet
    boy2_pos.x=450;
    boy2_pos.y=550;
    boy2_pos.w=150;
    boy2_pos.h=150;//ei rec(square) er moddher kothao texture (runman) load hobe

    

    // int frameWidth,frameHeight;
    // int textureWidth,textureHeight;
   // SDL_QueryTexture(tex,NULL,NULL,&textureWidth,&textureHeight);

    // frameWidth=textureWidth/9;
    // frameHeight=textureHeight;
    boy2.x=400;
    boy2.y=50;
    boy2.w=frameWidth;
    boy2.h=frameHeight;
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

    surface =IMG_Load("res/bg.png");
    SDL_Texture *bg_Tex =SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);

    surface =IMG_Load("res/putull.png");
    SDL_Texture *Putul_Tex =SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);

    SDL_Rect  playrRect;//rect for a single frame of the sprite sheet
    SDL_Rect playrPosition;//rect for the whole sprite sheet
    playrPosition.x=568;
    playrPosition.y=30;
    playrPosition.w=75;
    playrPosition.h=75;//ei rec(square) er moddher kothao texture (runman) load hobe

    

    int framWidth,framHeight;
    int texturWidth,texturHeight;
    SDL_QueryTexture(Putul_Tex,NULL,NULL,&texturWidth,&texturHeight);

    framWidth=texturWidth/4;
    framHeight=texturHeight/3;
    playrRect.x=playrRect.y=0;
    playrRect.w=framWidth;
    playrRect.h=framHeight;


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
    if (!replay_tex)
    {
        printf("replayTexture %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
 
SDL_AudioSpec wavSpec;
Uint32 wavLength;
Uint8 *wavBuffer;
 
SDL_LoadWAV("res/background.wav", &wavSpec, &wavBuffer, &wavLength);
SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);


int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
SDL_PauseAudioDevice(deviceId, 0);




    SDL_Rect replay_rect;
    replay_rect.w = 300;
    replay_rect.h = 150;
    replay_rect.x = (WINDOW_WIDTH - replay_rect.w) / 2;
    replay_rect.y = (WINDOW_HEIGHT - replay_rect.h) / 2 + 100;

   bool isRunning =true;
    float y_pos = 550.0;
    float y_pos1=450.0;
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
            case SDL_SCANCODE_UP:
                  {
                    y_pos =  y_pos - (500 / 60);
                    if(y_pos>0)
                     playerPosition.y= (int)y_pos;
                    else
                       {y_pos=0;
                        playerPosition.y=0;}
                   playerRect.x+=frameWidth;
                      if(playerRect.x>=textureWidth-frameWidth)
                        playerRect.x=0;

                         y_pos1 =  y_pos1 - (550 / 60);
                    if(y_pos1>0)
                     boy2_pos.y= (int)y_pos1;
                    else
                       {y_pos1=0;
                        boy2_pos.y=0;}
                   boy2.x+=frameWidth;
                      if(boy2.x>=textureWidth-frameWidth)
                        boy2.x=0;

                
                    }
                    
                    break;
            case SDL_SCANCODE_DOWN:
                 {
                         y_pos = y_pos + (500 / 60);
                      if(y_pos<550)
                         playerPosition.y= (int)y_pos;
                      else
                        {
                            y_pos=550;
                         playerPosition.y =550;
                         }

                      playerRect.x-=frameWidth;
                      if(playerRect.x<=0)
                        {playerRect.x=0;
                        playerRect.x=textureWidth-frameWidth;}

                        y_pos1 = y_pos1 + (560 / 60);
                      if(y_pos1<550)
                         boy2_pos.y= (int)y_pos1;
                      else
                        {
                            y_pos1=550;
                         boy2_pos.y =550;
                         }

                      boy2.x-=frameWidth;
                      if(boy2.x<=0)
                        {boy2.x=0;
                        boy2.x=textureWidth-frameWidth;}
                 }
                }
            }
        }
      
        
    
       if (gameover == 0)
        {
              
                    

          
           
            
       // Mix_PlayMusic(music,0);
       
           frameTime++;
           if(FPS/frameTime==1)//will be repeated 7 times a second
            {
           frameTime=0;//repeat
           playrRect.x+=framWidth;
           if(playrRect.x>=texturWidth-framWidth)
                        {playrRect.x=0;
                         playrRect.y+=framHeight;}
            if(playrRect.y>=texturHeight-framHeight)
                         playrRect.y=0;

                         boy2.x+=framWidth;
           if(boy2.x>=texturWidth-framWidth)
                        {boy2.x=0;
                         boy2.y+=framHeight;}
            if(boy2.y>=texturHeight-framHeight)
                         boy2.y=0;
          
          }
            SDL_RenderClear(rend);
            SDL_RenderCopy(rend, tex0, NULL, NULL);
          SDL_SetRenderDrawColor(rend,0x00,0x00,0x00,0x00);
            for(int i=0;i<5;i++)
            SDL_RenderDrawLine(rend,135+i,135+i,1200+i,135+i);

            
            SDL_RenderCopy(rend,bg_Tex,NULL,NULL);
            SDL_RenderCopy(rend,Putul_Tex,&playrRect,&playrPosition);
            
            SDL_RenderCopy(rend,tex,&playerRect,&playerPosition);
              SDL_RenderCopy(rend,tex,&boy2,&boy2_pos);
             

            SDL_RenderPresent(rend);

            
            
        
           
            if(playerPosition.y<=100)
            {
                SDL_Delay(1500);

            playerPosition.y=100;

             if(boy2_pos.y<=100)
            {
                SDL_Delay(1500);

            boy2_pos.y=100;
            gameover=2;
            }
        }
        }
        else if(gameover==1)
    {
        Mix_PlayChannel( -1, replay, 0 );
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
                   
                }
            }
    }
        else if(gameover==2)
        {
             Mix_PlayChannel( -1, replay1, 0 );

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
                    y_pos=550.0;
                   playerPosition.x=400;
                   playerPosition.y=550;
                   playerRect.x=playerRect.y=0;

                     y_pos1=550.0;
                   boy2_pos.x=400;
                   boy2_pos.y=550;
                   boy2.x=boy2.y=0;
                    
                   
                }
            }
        }
    }
    
    

    SDL_Delay(100);
    SDL_CloseAudioDevice(deviceId);
    Mix_FreeChunk(replay);
    SDL_FreeWAV(wavBuffer);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);

    SDL_Quit();
    return 0;
}

// #include <SDL2/SDL.h>
// #include <SDL2/SDL_image.h>
// #include <SDL2/SDL_timer.h>
// #include <stdio.h>

// #define WINDOW_WIDTH (1280)
// #define WINDOW_HEIGHT (720)
// #define SCROLL_SPEED (900)
// #define RECT_SPEED (5.0)
// void init();
// void error();
// float min(float x, float y)
// {
//     if (x < y)
//         return x;
//     return y;
// }
// float max(float x, float y)
// {
//     if (x > y)
//         return x;
//     return y;
// }

// int main(int agr, char *args[])
// {

//     init();
//     SDL_Window *win = SDL_CreateWindow("SDL Demonstration", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
     
//           if (!win)
//     {
//         printf("window: %s\n", SDL_GetError());
//         SDL_Quit();
//         return 1;
//     }
//     Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
//     SDL_Renderer *rend = SDL_CreateRenderer(win, -1, render_flags);
//     SDL_Surface *surface = IMG_Load("res/dip.jpg");
//     if (!surface)
//     {
//         printf("Redbar Surface Error: %s\n", IMG_GetError());
//         SDL_DestroyRenderer(rend);
//         SDL_DestroyWindow(win);
//         SDL_Quit();
//         return 1;
//     }

//     SDL_Texture *tex0 = SDL_CreateTextureFromSurface(rend, surface);
//     SDL_FreeSurface(surface);
//     if (!tex0)
//     {
//         printf("Redline Texture %s\n", SDL_GetError());
//         SDL_DestroyRenderer(rend);
//         SDL_DestroyWindow(win);
//         SDL_Quit();
//         return 1;
//     }
//     SDL_RenderClear(rend);
//     SDL_RenderCopy(rend, tex0, NULL, NULL);
//     SDL_RenderPresent(rend);
//     SDL_Delay(1000);
//     surface = IMG_Load("res/start.jpg");
//     if (!surface)
//     {
//         printf("Redbar Surface Error: %s\n", IMG_GetError());
//         SDL_DestroyRenderer(rend);
//         SDL_DestroyWindow(win);
//         SDL_Quit();
//         return 1;
//     }

//     SDL_Texture *tex3 = SDL_CreateTextureFromSurface(rend, surface);
//     SDL_FreeSurface(surface);
//     if (!tex3)
//     {
//         printf("Redline Texture %s\n", SDL_GetError());
//         SDL_DestroyRenderer(rend);
//         SDL_DestroyWindow(win);
//         SDL_Quit();
//         return 1;
//     }
//     SDL_Rect start_rect;
//     start_rect.w = 300;
//     start_rect.h = 150;
//     start_rect.x = (WINDOW_WIDTH - start_rect.w) / 2;
//     start_rect.y = (WINDOW_HEIGHT - start_rect.h) / 2 - 100;
    
   
//    SDL_SetRenderDrawColor(rend, 0xFF, 0xFF, 0xFF, 0xFF);
//  SDL_SetRenderDrawColor(rend, 0xFF, 0xFF, 0xFF, 0xFF);
//   SDL_SetRenderDrawColor(rend, 0xFF, 0xFF, 0xFF, 0xFF);
    

//     surface = IMG_Load("res/clipart3291119.png");
//     if (!surface)
//     {
//         printf("Redbar Surface Error: %s\n", IMG_GetError());
//         SDL_DestroyRenderer(rend);
//         SDL_DestroyWindow(win);
//         SDL_Quit();
//         return 1;
//     }

//     SDL_Texture *tex = SDL_CreateTextureFromSurface(rend, surface);
//     SDL_FreeSurface(surface);
//     if (!tex)
//     {
//         printf("Redline Texture %s\n", SDL_GetError());
//         SDL_DestroyRenderer(rend);
//         SDL_DestroyWindow(win);
//         SDL_Quit();
//         return 1;
//     }

//     SDL_Rect dest;
//     SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);
    
//     dest.x = 0;
//     dest.y = (int)WINDOW_HEIGHT - (WINDOW_HEIGHT * 0.6);
//     float x_pos = 0;
//     int direction = 1;

    

//     surface = IMG_Load("res/gameover.jpg");
//     if (!surface)
//     {
//         printf("Green rectangle Surface Error: %s\n", IMG_GetError());
//         SDL_DestroyRenderer(rend);
//         SDL_DestroyWindow(win);
//         SDL_Quit();
//         return 1;
//     }
//     SDL_Texture *gameover_tex = SDL_CreateTextureFromSurface(rend, surface);
//     SDL_FreeSurface(surface);
//     if (!tex)
//     {
//         printf("Green Rectangle Texture %s\n", SDL_GetError());
//         SDL_DestroyRenderer(rend);
//         SDL_DestroyWindow(win);
//         SDL_Quit();
//         return 1;
//     }

//     SDL_Rect gameover_rect;
//     gameover_rect.w = 400;
//     gameover_rect.h = 300;
//     gameover_rect.x = (WINDOW_WIDTH - gameover_rect.w) / 2;
//     gameover_rect.y = (WINDOW_HEIGHT - gameover_rect.h) / 2 - 150;

//     surface = IMG_Load("res/replay.png");
//     if (!surface)
//     {
//         printf("replay Surface Error: %s\n", IMG_GetError());
//         SDL_DestroyRenderer(rend);
//         SDL_DestroyWindow(win);
//         SDL_Quit();
//         return 1;
//     }
//     SDL_Texture *replay_tex = SDL_CreateTextureFromSurface(rend, surface);
//     SDL_FreeSurface(surface);
//     if (!tex)
//     {
//         printf("replayTexture %s\n", SDL_GetError());
//         SDL_DestroyRenderer(rend);
//         SDL_DestroyWindow(win);
//         SDL_Quit();
//         return 1;
//     }
//  SDL_Init(SDL_INIT_AUDIO);
//   SDL_AudioSpec wavSpec;
// Uint32 wavLength;
// Uint8 *wavBuffer;
 
// SDL_LoadWAV("res/background.wav", &wavSpec, &wavBuffer, &wavLength);
// SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
//  //   SDL_Rect dest;
//  //  SDL_QueryTexture(tex2, NULL, NULL, &dest.w, &dest.h);

// int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
// SDL_PauseAudioDevice(deviceId, 0);

// SDL_Delay(3000);
//     SDL_Rect replay_rect;
//     replay_rect.w = 300;
//     replay_rect.h = 150;
//     replay_rect.x = (WINDOW_WIDTH - replay_rect.w) / 2;
//     replay_rect.y = (WINDOW_HEIGHT - replay_rect.h) / 2 + 100;

//     int close = 0;
//     int gameover = 1;

//     while (!close)
//     {
//         SDL_Event event;
//         while (SDL_PollEvent(&event))
//         {
//             switch (event.type)
//             {
//             case SDL_QUIT:
//                 close = 1;
//                 break;
//             case SDL_KEYDOWN:
//                 switch (event.key.keysym.scancode)
//                 {
//                 case SDL_SCANCODE_LEFT:
//                     x_pos = max(0, x_pos - (SCROLL_SPEED / 60));
//                     break;
//                 case SDL_SCANCODE_RIGHT:
//                     x_pos = min(WINDOW_WIDTH - dest.w, x_pos + (SCROLL_SPEED / 60));
//                 }
//             }
//         }

      
        
    
//        if (gameover == 0)
//         {
//            dest.x = (int)x_pos;
//             SDL_SetRenderDrawColor(rend,0xFF,0xFF,0xFF,0xFF);
//             SDL_RenderClear(rend);
//             SDL_SetRenderDrawColor(rend,0x00,0x00,0x00,0x00);
//             SDL_RenderDrawLine(rend,1200,1100,900,300);
//           // SDL_RenderDrawLine();
//             SDL_RenderCopy(rend, tex, NULL, &dest);
//             SDL_RenderPresent(rend);
//             SDL_Delay(1000 / 60);
//             if(dest.x>=WINDOW_WIDTH*0.79)
//             {dest.x=WINDOW_WIDTH*0.79;
//             gameover=2;
//             }
//         }
//         else if(gameover==1)
//     {
//         SDL_RenderClear(rend);
//     SDL_RenderCopy(rend, tex3, NULL, &start_rect);
//     SDL_RenderPresent(rend);
//     //SDL_Delay(3000);
//         int mousx, mousy;
//             int button = SDL_GetMouseState(&mousx, &mousy);
//             printf("%d %d\n", mousx, mousy);

//             if (button & SDL_BUTTON(SDL_BUTTON_LEFT))
//             {
//                 if (mousx >= start_rect.x && mousx <= (start_rect.x + start_rect.w) && mousy >= start_rect.y && mousy <= (start_rect.y + start_rect.h))
//                 {
                  
//                     gameover = 0;
                   
//                 }
//             }
//     }
//         else if(gameover==2)
//         {

//             SDL_RenderClear(rend);
//             SDL_RenderCopy(rend, gameover_tex, NULL, &gameover_rect);
//             SDL_RenderCopy(rend, replay_tex, NULL, &replay_rect);
//             SDL_RenderPresent(rend);
//             int mousex, mousey;
//             int buttons = SDL_GetMouseState(&mousex, &mousey);
//             printf("%d %d\n", mousex, mousey);
//             if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
//             {
//                 if (mousex >= replay_rect.x && mousex <= (replay_rect.x + replay_rect.w) && mousey >= replay_rect.y && mousey <= (replay_rect.y + replay_rect.h))
//                 {
//                     gameover = 0;
//                     x_pos=0;
//                     dest.x=0;
//                     dest.y = (int)WINDOW_HEIGHT - (WINDOW_HEIGHT * 0.6);   
//                 }
//             }
//         }
//     }
    

//     SDL_Delay(1000);
//     SDL_CloseAudioDevice(deviceId);
// SDL_FreeWAV(wavBuffer);
//     SDL_DestroyRenderer(rend);
//     SDL_DestroyWindow(win);

//     SDL_Quit();
//     return 0;
// }
// void init(){
//          if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) > 0)
//     {
//         printf("video and timer: %s\n", SDL_GetError());
//     }
//     printf("Initialization Complete\n");

// }
