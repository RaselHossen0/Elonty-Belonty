#include "header.h"

int main(int agr, char *args[])
{

    init();
    loadMedia();
    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, tex0, NULL, NULL);
    SDL_RenderPresent(rend);
    SDL_Delay(2000);
    Mix_PlayChannel(-1,menu,0);
    audio();

    TTF_Font *font = TTF_OpenFont("res/font/Oswald-Bold.ttf", 40);
    surface = TTF_RenderText_Solid(font, "Elonti-Belonti", {0, 0, 0});

    SDL_Texture *fontTex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_Rect textRect = {40, 40, 500, 50};
    SDL_FreeSurface(surface);

    rect3();

    bool isRunning = true;
    float y_pos = 550.0;
    float y_pos1 = 450.0;
    int gameover = 0;
    int start = 1;
    int main_game = 0;  int goob=0;
    int next_lvl = 0;
    int frameTime = 0, FPS = 60;
    int scroll = 0;
    int var=1;
    SDL_Event ev,e;
    while (isRunning)
    {
         int goob=0,loob=0;

        while (SDL_PollEvent(&ev))
        {
            switch (ev.type)
            {
            case SDL_QUIT:
                isRunning = false;
                break;
            case SDL_KEYDOWN:
                switch (ev.key.keysym.scancode)
                {

                case SDL_SCANCODE_UP:
                {
                    y_pos = y_pos - (500 / 60);
                    if (y_pos > 0)
                        playerPosition.y = (int)y_pos;
                    else
                    {
                        y_pos = 0;
                        playerPosition.y = 0;
                    }
                    goob=1;
                    playerRect.x += frameWidth;
                    if (playerRect.x >= textureWidth - frameWidth)
                        playerRect.x = 0;
                    break;
                }

                case SDL_SCANCODE_DOWN:
                {
                    goob=1;
                    y_pos = y_pos + (500 / 60);
                    if (y_pos < 550)
                        playerPosition.y = (int)y_pos;
                    else
                    {
                        y_pos = 550;
                        playerPosition.y = 550;
                    }

                    playerRect.x -= frameWidth;
                    if (playerRect.x <= 0)
                    {
                        playerRect.x = 0;
                        playerRect.x = textureWidth - frameWidth;
                    }
                }
                }
            }
        }

        if (main_game)
        {
            double initTime=0;
            double startTime = SDL_GetTicks() / 1000.0;
        
            if (startTime  >= 2*var&&startTime<=10*var)
            {
                Mix_PlayChannel(-1,rand1,0);
            }
              else if (startTime  >= 10.1*var&&startTime<=12.0*var)
            {
                if(goob)
                loob=1;
            }
            
            
          else  if (startTime  >= 12.0*var&&startTime<=18.0*var)
            {
                Mix_PlayChannel(-1,rand2,0);
            }
            else  if (startTime  >= 18*var&&startTime<=21*var)
            {
                if(goob)
                loob=1;
            }
            
            else  if (startTime  >= 21.0*var&&startTime<=25*var)
            {
                
                Mix_PlayChannel(-1,rand3,0);
            }     
            else  if (startTime  >= 25*var&&startTime<=28*var)
            {
                if(goob)
                loob=1;
            }
            
            else  if (startTime  >= 28*var&&startTime<=34*var)
            {
                
                Mix_PlayChannel(-1,rand3,0);
            } 
            cloud_rect.x += 1;
            if (cloud_rect.x >= WINDOW_WIDTH)
                cloud_rect.x = 0;

                src_fir.x+=fw;
                if(src_fir.x+fw>=tfW){
                    src_fir.x=0;
            frameTime++;
            if (FPS / frameTime == 1) // will be repeated 7 times a second
            {
                frameTime = 0; // repeat
                
                }
                playrRect.x += r1.frmWid;
                if (playrRect.x >= texturWidth - r1.frmWid)
                {
                    playrRect.x = 0;
                    playrRect.y += r1.frmHit;
                }
                if (playrRect.y >= texturHeight - r1.frmHit)
                    playrRect.y = 0;

                plarRect.x += r3.frmWid;
                if (plarRect.x >= txturWidth - r3.frmWid)
                    plarRect.x = 0;
                plarRect1.x += r2.frmWid;
                if (plarRect1.x >= txturWidth1 - r2.frmWid)
                    plarRect1.x = 0;

                plarRect2.x += r5.frmWid;
                if (plarRect2.x >= txturWidth2 - r5.frmWid)
                    plarRect2.x = 0;

                plarRect3.x += r7.frmWid;
                if (plarRect3.x >= txturWidth3 - r7.frmWid)
                    plarRect3.x = 0;
                plarRect4.x += r8.frmWid;
                if (plarRect4.x >= txturWidth4 - r8.frmWid)
                    plarRect4.x = 0;

                plarRect22.x += r6.frmWid;
                if (plarRect22.x >= txturWidth22 - r6.frmWid)
                    plarRect22.x = 0;
            }
            SDL_RenderClear(rend);
            SDL_RenderCopy(rend, tex0, NULL, NULL);
            SDL_RenderCopy(rend, bg_Tex, NULL, NULL);
            SDL_RenderCopy(rend, cloud, NULL, &cloud_rect);
            SDL_RenderCopy(rend, Putul_Tex, &playrRect, &playrPosition);
            SDL_RenderCopy(rend, fire_Tex, &plarRect, &plarPosition);
            SDL_RenderCopy(rend, fire_Tex, &plarRect1, &plarPosition1);
            SDL_RenderCopy(rend, fire_Tex, &plarRect2, &plarPosition2);
            SDL_RenderCopy(rend, fire2_Tex, &plarRect22, &plarPosition22);
            SDL_RenderCopy(rend, fire2_Tex, &plarRect3, &plarPosition3);
            SDL_RenderCopy(rend, fire2_Tex, &plarRect4, &plarPosition4);
            SDL_RenderCopy(rend, tex, &playerRect, &playerPosition);

            if(loob)
            {
                dest_fir.y=playerPosition.y;
                dest_fir.x=350;
                SDL_RenderCopy(rend,fir,&src_fir,&playerPosition);
              //  SDL_RenderCopy(rend, tex, &playerRect, &playerPosition);
                //SDL_RenderPresent(rend);
                gameover=4;
                
            }
            SDL_RenderPresent(rend);
            SDL_RenderClear(rend);

            if (playerPosition.y <= 100)
            {
                gameover = 1;
                var++;
                main_game = 0;
                 
              
            }
           
            start = 0;
        }
        else if (start)
        {
            // Mix_PlayChannel( -1, replay, 0 );
            // Mix_PlayChannel(-1,menu,0);
            SDL_RenderClear(rend);
            SDL_RenderCopy(rend, fontTex, NULL, &textRect);
            SDL_RenderCopy(rend, tex3, NULL, &start_rect);
            SDL_RenderPresent(rend);

            int mousx, mousy;
            int button = SDL_GetMouseState(&mousx, &mousy);
            // printf("%d %d\n", mousx, mousy);

            if (button & SDL_BUTTON(1))
            {
                if (mousx >= start_rect.x && mousx <= (start_rect.x + start_rect.w) && mousy >= start_rect.y && mousy <= (start_rect.y + start_rect.h))
                {
                    Mix_PlayChannel(-1, mouse, 4);
                    // SDL_Delay(2000);
                    main_game = 1;
                }
            }
        }
        else if (gameover == 1)
        {
            Mix_PlayChannel(-1, replay1, 0);
            SDL_RenderClear(rend);
            SDL_RenderCopy(rend, gameover_tex, NULL, &gameover_rect);
            SDL_RenderCopy(rend, replay_tex, NULL, &replay_rect);
            SDL_RenderCopy(rend, next_level, NULL, &next);
            SDL_RenderPresent(rend);

            int mousex, mousey;
            int buttons = SDL_GetMouseState(&mousex, &mousey);
            // printf("%d %d",mousex,mousey);

            if (buttons & SDL_BUTTON(1))
            {
                if (mousex >= replay_rect.x && mousex <= (replay_rect.x + replay_rect.w) && mousey >= replay_rect.y && mousey <= (replay_rect.y + replay_rect.h))
                {
                    Mix_PlayChannel(-1, mouse, 0);
                    y_pos = 550.0;
                    playerPosition.x = 400;
                    playerPosition.y = 550;
                    playerRect.x = playerRect.y = 0;
                    main_game = 1;
                }

                if (mousex >= next.x && mousex <= (next.x + next.w) && mousey >= next.y && mousey <= (next.y + next.h))
                {

                    next_lvl = 1;
                    main_game = 0;
                    gameover = 0;
                }
            }
        }
         else if(gameover==4)
         {
            SDL_RenderClear(rend);
            SDL_RenderCopy(rend,againTex,NULL,NULL);
             SDL_RenderPresent(rend);

            int mousex, mousey;
            int buttons = SDL_GetMouseState(&mousex, &mousey);
           

            if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
            {
                if (mousex >= WINDOW_WIDTH/2.5 && mousex <= WINDOW_WIDTH/1.5 && mousey >= WINDOW_HEIGHT/2.5&& mousey <= WINDOW_HEIGHT/1.5)
                {
                    gameover = 0;
                    y_pos=550.0;
                    //count = 0;
                   playerPosition.x=400;
                   playerPosition.y=550;
                   playerRect.x=playerRect.y=0;
                    
                   
                }
            }
        }
        else if (next_lvl == 1)
        {
            cloud_rect.x += 1;
            if (cloud_rect.x >= WINDOW_WIDTH)
                cloud_rect.x = 0;
            frameTime++;
            if (FPS / frameTime == 1)
            {
                frameTime = 0;
                src_l2b.x += f1W;
                if (src_l2b.x+f1W >= tx1W)
                    src_l2b.x = 0;
            }
            SDL_RenderClear(rend);
            SDL_SetRenderDrawColor(rend,0,255, 0x00, 0x00);
            SDL_RenderCopy(rend, cloud, NULL, &cloud_rect);
            SDL_RenderCopy(rend, l2boy, &src_l2b, &dest_l2b);
            SDL_RenderCopy(rend,fontTex,NULL,&textRect);
            SDL_RenderPresent(rend);
        }
    }
    Mix_FreeChunk(replay1);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);

    SDL_Quit();
    return 0;
}
