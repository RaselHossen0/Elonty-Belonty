#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <bits/stdc++.h>
using namespace std;





SDL_Texture *LoadTexture(std:: string  filepath,SDL_Renderer *renderTarget){
    SDL_Texture *texture=nullptr;
    SDL_Surface *surface =IMG_Load(filepath.c_str());
    texture=SDL_CreateTextureFromSurface(renderTarget,surface);
    SDL_FreeSurface (surface);
    return texture;
}

int main(int argc, char *argv[])
{
    const int FPS =60;
    int frameTime=0;

   
    SDL_Window *window =nullptr;
    SDL_Texture *currentImage =nullptr;
    SDL_Renderer *renderTarget=nullptr;
    SDL_Rect  playerRect;
    SDL_Rect playerPosition;
    playerPosition.x=0;
    playerPosition.y=400;
    playerPosition.w=playerPosition.h=320;

    int frameWidth,frameHeight;
    int textureWidth,textureHeight;
    SDL_Init(SDL_INIT_VIDEO);
    int imgFlags=IMG_INIT_PNG|IMG_INIT_JPG;
    window=SDL_CreateWindow("elonti-belonti",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1280,700,0);
    renderTarget=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    currentImage=LoadTexture("res/runman.png",renderTarget);                                                                                                                                        
    SDL_QueryTexture(currentImage,NULL,NULL,&textureWidth,&textureHeight);
    frameWidth=textureWidth/4;
    frameHeight=textureHeight/2;
    playerRect.x=playerRect.y=0;
    playerRect.w=frameWidth;
    playerRect.h=frameHeight;
    SDL_SetRenderDrawColor(renderTarget,0xFF,0,0,0xFF);

    bool isRunning =true;
    SDL_Event ev;
    while(isRunning){
        /*while(SDL_PollEvent(&ev)!=0){
            if(ev.type==SDL_QUIT)
            isRunning=false;
        }
        */
        
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
                    frameTime--;
                    break;
                case SDL_SCANCODE_RIGHT:
                    frameTime++;
                }
            }
        }
        frameTime++;
        if(FPS/frameTime==1)//will be repeated 7 times a second
        {
            frameTime=0;//repeat
            playerRect.x+=frameWidth;
            if(playerRect.x>=textureWidth)
            {playerRect.x=0;
            playerRect.y+=frameHeight;}
            if(playerRect.y>=textureHeight)
            playerRect.y=0;
        }
        SDL_RenderClear(renderTarget);
        SDL_RenderCopy(renderTarget,currentImage,&playerRect,&playerPosition);
        SDL_RenderPresent(renderTarget);

    }
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(currentImage);
    SDL_DestroyRenderer(renderTarget);
    window=nullptr;
    currentImage=nullptr;
    renderTarget=nullptr;
    SDL_Quit();
    return 0;


}