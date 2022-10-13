//http://www.youtube.com/user/thecplusplusguy
//Thanks for the typed in code to Tapit85
//you need an image called tree_animation.bmp, with 10 100x100 frames next to each other
#include <SDL2/SDL.h>
#include <stdio.h>
#include <SDL2/SDL_image.h>
 
void setrects(SDL_Rect* clip)
{
    for(int i = 0; i < 10; i += 1) {
        clip[i].x = 0 + i*100;
        clip[i].y = 0;
        clip[i].w = 100;
        clip[i].h = 100;
    }
}
 
int main(int argc, char** argv)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Surface *screen, *image;    // every surface except for screen needs to be freed
    screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
//  screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE|SDL_FULLSCREEN);
    bool running = true;
    const int FPS = 30;
    Uint32 start;
    bool b[4] = {0,0,0,0};
    SDL_Rect rect;
    float frame = 0;
    rect.x = 10;
    rect.y = 10;
    rect.w = 20;
    rect.h = 20;
    Uint32 color = SDL_MapRGB(screen->format, 0xff,0xff,0xff);
    Uint32 color2 = SDL_MapRGB(screen->format, 0,0,0);
    image = SDL_DisplayFormat(SDL_LoadBMP("res/low.bmp"));   // better to check later if image is NULL
    SDL_Rect rects[10];
    setrects(rects);
    SDL_SetColorKey(image, SDL_SRCCOLORKEY, SDL_MapRGB(screen->format, 0x00, 0xff, 0xff));
    while(running) {
        start = SDL_GetTicks();
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym) {
                        case SDLK_UP:
                            b[0] = 1;
                            break;
                        case SDLK_LEFT:
                            b[1] = 1;
                            break;
                        case SDLK_DOWN:
                            b[2] = 1;
                            break;
                        case SDLK_RIGHT:
                            b[3] = 1;
                            break;
                    
                    }
                    break;
                case SDL_KEYUP:
                    switch(event.key.keysym.sym) {
                        case SDLK_UP:
                            b[0] = 0;
                            break;
                        case SDLK_LEFT:
                            b[1] = 0;
                            break;
                        case SDLK_DOWN:
                            b[2] = 0;
                            break;
                        case SDLK_RIGHT:
                            b[3] = 0;
                            break;
                    
                    }
                    break;
            }
        }
 
        //logic
        if(b[0])
            rect.y--; 
        if(b[1])
            rect.x--; 
        if(b[2])
            rect.y++; 
        if(b[3])
            rect.x++; 
 
        //render
        SDL_FillRect(screen, &screen->clip_rect, color);    // fill the screen white (maybe better outside while loop)
//      SDL_FillRect(screen, &rect, color2);
//      SDL_Rect rect;
        rect.x = 200;
        rect.y = 100;
 
        SDL_BlitSurface(image, &rects[static_cast<int>(frame)], screen, &rect);
        SDL_Flip(screen);
        frame += 0.2;
        if(frame > 10) {
            frame = 0;
        }
        if(1000/FPS > SDL_GetTicks()-start) {
            SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
        }
    }
    SDL_FreeSurface(image);
    SDL_Quit();
    return 0;
}




// #include <stdio.h>
// #include <SDL2/SDL.h>
// #include <SDL2/SDL_image.h>
// //#include <SDL2/SDL_mixer.h>
// int main(int agr, char* args[])
// {
//   if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER)>0)
//   {
//     printf("Wrong Initialization:%s\n",SDL_GetError());
//   }
//   SDL_Window *win;
//   win=SDL_CreateWindow("Elonti-Belonti",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,792,420,0);
//   SDL_Renderer *rendr;
//   rendr=SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
//   SDL_Surface *bg=IMG_Load("res/bg.jpg");
//   SDL_Texture* tex = SDL_CreateTextureFromSurface(rendr, bg);
//    SDL_FreeSurface(bg);
//   bg=IMG_Load("res/a.png");
//   SDL_RenderClear(rendr);
//    SDL_RenderCopy(rendr, tex, NULL, NULL);
//    SDL_RenderPresent(rendr);
//   SDL_Texture* tex2 = SDL_CreateTextureFromSurface(rendr, bg);
//    SDL_Texture* tex3 =SDL_CreateTextureFromSurface(rendr,bg);
//   SDL_Init(SDL_INIT_AUDIO);
//   SDL_AudioSpec wavSpec;
// Uint32 wavLength;
// Uint8 *wavBuffer;
// SDL_LoadWAV("res/background.wav", &wavSpec, &wavBuffer, &wavLength);
// SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
// SDL_Rect dest;
// SDL_QueryTexture(tex2, NULL, NULL, &dest.w, &dest.h);
// SDL_RenderCopy(rendr, tex, NULL, NULL);
// SDL_RenderCopy(rendr, tex2, NULL, &dest);
// SDL_RenderPresent(rendr);
// int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
// SDL_PauseAudioDevice(deviceId, 0);
// SDL_Delay(3000);
//    dest.w = (int) dest.w * 0.8;
//    dest.h = (int) dest.h * 0.8;
//    dest.x = 0;
//    dest.y = (int)dest.h-280;
//    float x_pos = 100;
// SDL_Rect boy2;
// SDL_QueryTexture(tex3, NULL, NULL, &boy2.w, &boy2.h);
// boy2.w = (int) boy2.w * 0.8;
//    boy2.h = (int) boy2.h * 0.8;
//    boy2.x = 0;
//    boy2.y = (int)dest.h-280;
//    float x2_pos = 230;
//     SDL_RenderCopy(rendr, tex, NULL, NULL);
//     SDL_RenderCopy(rendr, tex3, NULL, &boy2);
//     SDL_RenderPresent(rendr);
//    int close=1;
//    while(dest.x<=1000&&boy2.x<=1000)
//    {
//     SDL_Event e;
//     while(close==1)
//     {
//     SDL_PollEvent(&e);
//     if(e.type==SDL_KEYDOWN)
//     {
//  		switch(e.key.keysym.scancode){
//  			case SDL_SCANCODE_LEFT:
//         close=0;
//         break;
//     }
//     }
// }
//     if(e.type==SDL_KEYDOWN)
//     {
//  	switch(e.key.keysym.scancode){
//  		case SDL_SCANCODE_DOWN:
//     dest.x = (int) x_pos;
//     x_pos += (float) 150/60;
//     SDL_Delay(1000/60);
//         break;
//     }
//     }
//     if(e.type==SDL_KEYDOWN)
//     {
//     switch(e.key.keysym.scancode){
//  		case SDL_SCANCODE_RIGHT:
//      boy2.x = (int) x2_pos;
//      x2_pos += (float) 190/60;
//      SDL_Delay(1000/60);
//         break;
//     }
//     }
//     SDL_PollEvent(&e);
//     if (e.type == SDL_QUIT)
//     {
//     close=0;
//         break;
//     }
//  }
// SDL_CloseAudioDevice(deviceId);
// SDL_FreeWAV(wavBuffer);
// SDL_DestroyRenderer(rendr);
// SDL_DestroyWindow(win);
// SDL_Quit();
// return 0;
// }