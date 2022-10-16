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
    SDL_Delay(1000);
    
    
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
    start_rect.y = (WINDOW_HEIGHT - start_rect.h) / 2;
    surface=IMG_Load("tree-png-6385.png");
   SDL_Texture *trees= SDL_CreateTextureFromSurface(rend,surface);
   SDL_FreeSurface(surface);
    SDL_Rect tree;
    tree.w = 100;
    tree.h = 100;
    tree.x = 800;
    tree.y = 0;
    surface=IMG_Load("tree-png-6385.png");
   
  
    SDL_Rect tree1;
    tree1.w = 50;
    tree1.h = 50;
    tree1.x = 900;
    tree1.y = 0;
    
   

    

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
    playerPosition.x=50;
    playerPosition.y=500;
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

    surface =IMG_Load("res/putul.png");
    SDL_Texture *Putul_Tex =SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
    SDL_Rect  playrRect;//rect for a single frame of the sprite sheet
    SDL_Rect playrPosition;
    SDL_Rect playrPosition1;//rect for the whole sprite sheet
    playrPosition.x=450;
    playrPosition.y=0;
    playrPosition.w=150;
    playrPosition.h=150;
    //
     playrPosition1.x=600;
    playrPosition1.y=0;
    playrPosition1.w=150;
    playrPosition1.h=150;
    //ei rec(square) er moddher kothao texture (runman) load hobe
    int framWidth,framHeight;
    int texturWidth,texturHeight;
    SDL_QueryTexture(Putul_Tex,NULL,NULL,&texturWidth,&texturHeight);

    framWidth=texturWidth/3;
    framHeight=texturHeight/4;
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
 SDL_Init(SDL_INIT_AUDIO);
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
    float y_pos1 = 650.0;
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
            case SDLK_a:
            {
                 y_pos1 =  y_pos1 - (900 / 60);
                    if(y_pos1>0)
                     playrPosition1.y= (int)y_pos1;
                    else
                       {y_pos1=0;
                        playrPosition1.y=0;}
                   playrRect.x+=frameWidth;
                      if(playrRect.x>=textureWidth-frameWidth)
                        playrRect.x=0;
            }
            case SDLK_w:
            {
                y_pos1 = y_pos1 + (900 / 60);
                      if(y_pos1<550)
                         playrPosition1.y= (int)y_pos;
                      else
                        {y_pos1=550;
                         playrPosition1.y =550;}

                      playerRect.x-=frameWidth;
                      if(playrRect.x<=0)
                        {playrRect.x=0;
                        playrRect.x=textureWidth-frameWidth;}
            }
            case SDL_KEYDOWN:
                switch (ev.key.keysym.scancode)
                {
            case SDL_SCANCODE_UP:
                  {
                    y_pos =  y_pos - (900 / 60);
                    if(y_pos>0)
                     playerPosition.y= (int)y_pos;
                    else
                       {y_pos=0;
                        playerPosition.y=0;}
                   playerRect.x+=frameWidth;
                      if(playerRect.x>=textureWidth-frameWidth)
                        playerRect.x=0;

                
                    }
                    
                    break;
            case SDL_SCANCODE_DOWN:
                 {
                         y_pos = y_pos + (900 / 60);
                      if(y_pos<550)
                         playerPosition.y= (int)y_pos;
                      else
                        {y_pos=550;
                         playerPosition.y =550;}

                      playerRect.x-=frameWidth;
                      if(playerRect.x<=0)
                        {playerRect.x=0;
                        playerRect.x=textureWidth-frameWidth;}
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
           playrRect.x+=framWidth;
           if(playrRect.x>=texturWidth-framWidth)
                        {playrRect.x=0;
                         playrRect.y+=framHeight;}
            if(playrRect.y>=texturHeight-framHeight)
                         playrRect.y=0;
          
          }
         // SDL_RenderClear(rend);
           SDL_RenderCopy(rend,Putul_Tex,&playrRect,&playrPosition);
            
       

             
              
           SDL_SetRenderDrawColor(rend,0xFF,0,0,0xFF);
            SDL_RenderClear(rend);
            SDL_SetRenderDrawColor(rend,0x00,0x00,0x00,0x00);
            for(int i=0;i<5;i++)
            SDL_RenderDrawLine(rend,135+i,135+i,1200+i,135+i);
            
            SDL_RenderCopy(rend,Putul_Tex,&playrRect,&playrPosition);
            SDL_RenderCopy(rend,trees,NULL,&tree);
            SDL_RenderCopy(rend,trees,NULL,&tree1);
            SDL_RenderCopy(rend,tex,&playerRect,&playerPosition);
            SDL_RenderCopy(rend,tex,&playerRect,&playrPosition1);
            SDL_RenderPresent(rend);

            
            
        
           
            if(playerPosition.y<=0)
            {
                SDL_Delay(1500);

            playerPosition.y=0;
            gameover=2;
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
                    y_pos=550.0;
                   playerPosition.x=400;
                   playerPosition.y=550;
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


// //http://www.youtube.com/user/thecplusplusguy
// //Thanks for the typed in code to Tapit85
// //you need an image called tree_animation.bmp, with 10 100x100 frames next to each other
// #include <SDL2/SDL.h>
// #include <stdio.h>
// #include <SDL2/SDL_image.h>
 
// void setrects(SDL_Rect* clip)
// {
//     for(int i = 0; i < 10; i += 1) {
//         clip[i].x = 0 + i*100;
//         clip[i].y = 0;
//         clip[i].w = 100;
//         clip[i].h = 100;
//     }
// }
 
// int main(int argc, char** argv)
// {
//     SDL_Init(SDL_INIT_EVERYTHING);
//     SDL_Surface *screen, *image;    // every surface except for screen needs to be freed
//     screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
// //  screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE|SDL_FULLSCREEN);
//     bool running = true;
//     const int FPS = 30;
//     Uint32 start;
//     bool b[4] = {0,0,0,0};
//     SDL_Rect rect;
//     float frame = 0;
//     rect.x = 10;
//     rect.y = 10;
//     rect.w = 20;
//     rect.h = 20;
//     Uint32 color = SDL_MapRGB(screen->format, 0xff,0xff,0xff);
//     Uint32 color2 = SDL_MapRGB(screen->format, 0,0,0);
//     image = SDL_DisplayFormat(SDL_LoadBMP("res/low.bmp"));   // better to check later if image is NULL
//     SDL_Rect rects[10];
//     setrects(rects);
//     SDL_SetColorKey(image, SDL_SRCCOLORKEY, SDL_MapRGB(screen->format, 0x00, 0xff, 0xff));
//     while(running) {
//         start = SDL_GetTicks();
//         SDL_Event event;
//         while(SDL_PollEvent(&event)) {
//             switch(event.type) {
//                 case SDL_QUIT:
//                     running = false;
//                     break;
//                 case SDL_KEYDOWN:
//                     switch(event.key.keysym.sym) {
//                         case SDLK_UP:
//                             b[0] = 1;
//                             break;
//                         case SDLK_LEFT:
//                             b[1] = 1;
//                             break;
//                         case SDLK_DOWN:
//                             b[2] = 1;
//                             break;
//                         case SDLK_RIGHT:
//                             b[3] = 1;
//                             break;
                    
//                     }
//                     break;
//                 case SDL_KEYUP:
//                     switch(event.key.keysym.sym) {
//                         case SDLK_UP:
//                             b[0] = 0;
//                             break;
//                         case SDLK_LEFT:
//                             b[1] = 0;
//                             break;
//                         case SDLK_DOWN:
//                             b[2] = 0;
//                             break;
//                         case SDLK_RIGHT:
//                             b[3] = 0;
//                             break;
                    
//                     }
//                     break;
//             }
//         }
 
//         //logic
//         if(b[0])
//             rect.y--; 
//         if(b[1])
//             rect.x--; 
//         if(b[2])
//             rect.y++; 
//         if(b[3])
//             rect.x++; 
 
//         //render
//         SDL_FillRect(screen, &screen->clip_rect, color);    // fill the screen white (maybe better outside while loop)
// //      SDL_FillRect(screen, &rect, color2);
// //      SDL_Rect rect;
//         rect.x = 200;
//         rect.y = 100;
 
//         SDL_BlitSurface(image, &rects[static_cast<int>(frame)], screen, &rect);
//         SDL_Flip(screen);
//         frame += 0.2;
//         if(frame > 10) {
//             frame = 0;
//         }
//         if(1000/FPS > SDL_GetTicks()-start) {
//             SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
//         }
//     }
//     SDL_FreeSurface(image);
//     SDL_Quit();
//     return 0;
// }




// // #include <stdio.h>
// // #include <SDL2/SDL.h>
// // #include <SDL2/SDL_image.h>
// // //#include <SDL2/SDL_mixer.h>
// // int main(int agr, char* args[])
// // {
// //   if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER)>0)
// //   {
// //     printf("Wrong Initialization:%s\n",SDL_GetError());
// //   }
// //   SDL_Window *win;
// //   win=SDL_CreateWindow("Elonti-Belonti",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,792,420,0);
// //   SDL_Renderer *rendr;
// //   rendr=SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
// //   SDL_Surface *bg=IMG_Load("res/bg.jpg");
// //   SDL_Texture* tex = SDL_CreateTextureFromSurface(rendr, bg);
// //    SDL_FreeSurface(bg);
// //   bg=IMG_Load("res/a.png");
// //   SDL_RenderClear(rendr);
// //    SDL_RenderCopy(rendr, tex, NULL, NULL);
// //    SDL_RenderPresent(rendr);
// //   SDL_Texture* tex2 = SDL_CreateTextureFromSurface(rendr, bg);
// //    SDL_Texture* tex3 =SDL_CreateTextureFromSurface(rendr,bg);
// //   SDL_Init(SDL_INIT_AUDIO);
// //   SDL_AudioSpec wavSpec;
// // Uint32 wavLength;
// // Uint8 *wavBuffer;
// // SDL_LoadWAV("res/background.wav", &wavSpec, &wavBuffer, &wavLength);
// // SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
// // SDL_Rect dest;
// // SDL_QueryTexture(tex2, NULL, NULL, &dest.w, &dest.h);
// // SDL_RenderCopy(rendr, tex, NULL, NULL);
// // SDL_RenderCopy(rendr, tex2, NULL, &dest);
// // SDL_RenderPresent(rendr);
// // int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
// // SDL_PauseAudioDevice(deviceId, 0);
// // SDL_Delay(3000);
// //    dest.w = (int) dest.w * 0.8;
// //    dest.h = (int) dest.h * 0.8;
// //    dest.x = 0;
// //    dest.y = (int)dest.h-280;
// //    float x_pos = 100;
// // SDL_Rect boy2;
// // SDL_QueryTexture(tex3, NULL, NULL, &boy2.w, &boy2.h);
// // boy2.w = (int) boy2.w * 0.8;
// //    boy2.h = (int) boy2.h * 0.8;
// //    boy2.x = 0;
// //    boy2.y = (int)dest.h-280;
// //    float x2_pos = 230;
// //     SDL_RenderCopy(rendr, tex, NULL, NULL);
// //     SDL_RenderCopy(rendr, tex3, NULL, &boy2);
// //     SDL_RenderPresent(rendr);
// //    int close=1;
// //    while(dest.x<=1000&&boy2.x<=1000)
// //    {
// //     SDL_Event e;
// //     while(close==1)
// //     {
// //     SDL_PollEvent(&e);
// //     if(e.type==SDL_KEYDOWN)
// //     {
// //  		switch(e.key.keysym.scancode){
// //  			case SDL_SCANCODE_LEFT:
// //         close=0;
// //         break;
// //     }
// //     }
// // }
// //     if(e.type==SDL_KEYDOWN)
// //     {
// //  	switch(e.key.keysym.scancode){
// //  		case SDL_SCANCODE_DOWN:
// //     dest.x = (int) x_pos;
// //     x_pos += (float) 150/60;
// //     SDL_Delay(1000/60);
// //         break;
// //     }
// //     }
// //     if(e.type==SDL_KEYDOWN)
// //     {
// //     switch(e.key.keysym.scancode){
// //  		case SDL_SCANCODE_RIGHT:
// //      boy2.x = (int) x2_pos;
// //      x2_pos += (float) 190/60;
// //      SDL_Delay(1000/60);
// //         break;
// //     }
// //     }
// //     SDL_PollEvent(&e);
// //     if (e.type == SDL_QUIT)
// //     {
// //     close=0;
// //         break;
// //     }
// //  }
// // SDL_CloseAudioDevice(deviceId);
// // SDL_FreeWAV(wavBuffer);
// // SDL_DestroyRenderer(rendr);
// // SDL_DestroyWindow(win);
// // SDL_Quit();
// // return 0;
// // }
