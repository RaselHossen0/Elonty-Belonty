#include "init.h"
#include "audio.h"
#include "loadTex.h"
#include "loadRect.h"

struct rect
{
    int frmWid, frmHit;

    rect(int fW, int fH)
    {
        frmWid = fW;
        frmHit = fH;
    }
};

int main(int agr, char *args[])
{
    init();
    audio();
    texCreate();
    loadRect();

     SDL_RenderClear(rend);
    SDL_RenderCopy(rend, tex0, NULL, NULL);
    SDL_RenderPresent(rend);
   SDL_Delay(1000/2 );
   
     

   


    int frameWidth, frameHeight;
    int textureWidth, textureHeight;
    SDL_QueryTexture(tex, NULL, NULL, &textureWidth, &textureHeight);

    frameWidth = textureWidth / 9;
    frameHeight = textureHeight;

    playerRect.x = playerRect.y = 0;
    playerRect.w = frameWidth;
    playerRect.h = frameHeight;

    SDL_Rect  plarRect33;
    SDL_Rect boy2_pos; 
    boy2_pos.x = 750;
    boy2_pos.y = 550;
    boy2_pos.w = 150;
    boy2_pos.h = 150; 

    int txturWidth33,txturHeight33;
    SDL_QueryTexture(tex,NULL,NULL,&txturWidth33,&txturHeight33);

    
    struct rect r88(txturWidth33/9,txturHeight33);
    plarRect33.x=plarRect33.y=0;
    plarRect33.w=r88.frmWid;
    plarRect33.h=r88.frmHit;
    

    

    SDL_Rect playrRect;     // rect for a single frame of the sprite sheet
    SDL_Rect playrPosition; // rect for the whole sprite sheet
    playrPosition.x = 568;
    playrPosition.y = 30;
    playrPosition.w = 75;
    playrPosition.h = 75; // ei rec(square) er moddher kothao texture (runman) load hobe

    surface = IMG_Load("res/2883482.png");
    SDL_Texture *next_level = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect next;
    // SDL_QueryTexture(next_level,NULL,NULL,&next.w,&next.h);
    next.w = 180;
    next.h = 180;
    next.x = 490;
    next.y = 450;
    surface = IMG_Load("res/sprite-02.png");
    SDL_Texture *l2boy = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    int tx1W, tx1H, f1W, f1H;
    SDL_Rect src_l2b, dest_l2b;
    SDL_QueryTexture(l2boy, NULL, NULL, &tx1W, &tx1H);
    f1W = tx1W / 3;
    f1H = tx1H;
   // printf("%d %d", f1W, f1H);
    src_l2b.w = f1W;
    src_l2b.h = f1H;
    src_l2b.x = src_l2b.y = 0;
    dest_l2b.w = 450;
    dest_l2b.h = 450;
    dest_l2b.x = 500;
    dest_l2b.y = 100;
    int framWidth, framHeight;
    int texturWidth, texturHeight;
    SDL_QueryTexture(Putul_Tex, NULL, NULL, &texturWidth, &texturHeight);

    framWidth = texturWidth / 4;
    framHeight = texturHeight / 3;
    playrRect.x = playrRect.y = 0;
    playrRect.w = framWidth;
    playrRect.h = framHeight;
    struct rect r1(texturWidth / 4, texturHeight / 3);

    playrRect.x = playrRect.y = 0;
    playrRect.w = r1.frmWid;
    playrRect.h = r1.frmHit;

    surface = IMG_Load("res/fire.png");
    SDL_Texture *fire_Tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    SDL_Rect plarRect;     // rect for a single frame of the sprite sheet
    SDL_Rect plarPosition; // rect for the whole sprite sheet
    plarPosition.x = 390;
    plarPosition.y = 100;
    plarPosition.w = 130;
    plarPosition.h = 130; // ei rec(square) er moddher kothao texture (runman) load hobe

    int txturWidth, txturHeight;
    SDL_QueryTexture(fire_Tex, NULL, NULL, &txturWidth, &txturHeight);

    struct rect r3(txturWidth / 10, txturHeight);
    plarRect.x = plarRect.y = 0;
    plarRect.w = r3.frmWid;
    plarRect.h = r3.frmHit;

    SDL_Rect plarRect1;     // rect for a single frame of the sprite sheet
    SDL_Rect plarPosition1; // rect for the whole sprite sheet
    plarPosition1.x = 195;
    plarPosition1.y = 100;
    plarPosition1.w = 130;
    plarPosition1.h = 130; // ei rec(square) er moddher kothao texture (runman) load hobe

    int txturWidth1, txturHeight1;
    SDL_QueryTexture(fire_Tex, NULL, NULL, &txturWidth1, &txturHeight1);

    struct rect r2(txturWidth1 / 10, txturHeight1);
    plarRect1.x = plarRect1.y = 0;
    plarRect1.w = r2.frmWid;
    plarRect1.h = r2.frmHit;

    SDL_Rect plarRect2;     // rect for a single frame of the sprite sheet
    SDL_Rect plarPosition2; // rect for the whole sprite sheet
    plarPosition2.x = 20;
    plarPosition2.y = 100;
    plarPosition2.w = 130;
    plarPosition2.h = 130;

    int txturWidth2, txturHeight2;
    SDL_QueryTexture(fire_Tex, NULL, NULL, &txturWidth2, &txturHeight2);

    struct rect r5(txturWidth2 / 10, txturHeight2);
    plarRect2.x = plarRect2.y = 0;
    plarRect2.w = r5.frmWid;
    plarRect2.h = r5.frmHit;

    surface = IMG_Load("res/fire2.png");
    SDL_Texture *fire2_Tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    SDL_Rect plarRect22;     // rect for a single frame of the sprite sheet
    SDL_Rect plarPosition22; // rect for the whole sprite sheet
    plarPosition22.x = 690;
    plarPosition22.y = 100;
    plarPosition22.w = 130;
    plarPosition22.h = 130; // ei rec(square) er moddher kothao texture (runman) load hobe

    int txturWidth22, txturHeight22;
    SDL_QueryTexture(fire2_Tex, NULL, NULL, &txturWidth22, &txturHeight22);

    struct rect r6(txturWidth2 / 10, txturHeight2);
    plarRect22.x = plarRect22.y = 0;
    plarRect22.w = r6.frmWid;
    plarRect22.h = r6.frmHit;

    SDL_Rect plarRect3;     // rect for a single frame of the sprite sheet
    SDL_Rect plarPosition3; // rect for the whole sprite sheet
    plarPosition3.x = 890;
    plarPosition3.y = 100;
    plarPosition3.w = 130;
    plarPosition3.h = 130; // ei rec(square) er moddher kothao texture (runman) load hobe

    int txturWidth3, txturHeight3;
    SDL_QueryTexture(fire2_Tex, NULL, NULL, &txturWidth3, &txturHeight3);

    struct rect r7(txturWidth1 / 10, txturHeight1);
    plarRect3.x = plarRect3.y = 0;
    plarRect3.w = r7.frmWid;
    plarRect3.h = r7.frmHit;

    SDL_Rect plarRect4;     // rect for a single frame of the sprite sheet
    SDL_Rect plarPosition4; // rect for the whole sprite sheet
    plarPosition4.x = 1090;
    plarPosition4.y = 100;
    plarPosition4.w = 130;
    plarPosition4.h = 130;

    int txturWidth4, txturHeight4;
    SDL_QueryTexture(fire2_Tex, NULL, NULL, &txturWidth4, &txturHeight4);

    struct rect r8(txturWidth4 / 10, txturHeight4);
    plarRect4.x = plarRect4.y = 0;
    plarRect4.w = r8.frmWid;
    plarRect4.h = r8.frmHit;


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
    TTF_Font *gFont = TTF_OpenFont( "res/Oswald-DemiBold.ttf", 20);
	SDL_Color color = { 0,0, 255, 255 };
    
    SDL_Event ev,e;
    while (isRunning)
    {
         int goob=0,loob=0;

        while (SDL_PollEvent(&ev))
        {
            switch (ev.type)
            {
            case SDL_QUIT:
             Mix_PlayChannel(-1, mouse, 2);
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
            boy2_pos.y-=10;
            

            int time=SDL_GetTicks()/1000;
	            std::string i=std::to_string(time);
	            SDL_Surface *surface1=TTF_RenderText_Solid(gFont,i.c_str(),{0,0,255});
                SDL_Texture * texture = SDL_CreateTextureFromSurface(rend, surface1);
                SDL_FreeSurface(surface1);
                SDL_Rect dstrect = { 0, 0,50, 50 };
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

               
            frameTime++;
            if (FPS / frameTime == 1) // will be repeated 7 times a second
            {
                frameTime = 0; // repeat

                
                
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
            SDL_RenderCopy(rend,texture,NULL,&dstrect);
            SDL_RenderCopy(rend, tex, &playerRect, &playerPosition);
            SDL_RenderCopy(rend, tex, &plarRect33, &boy2_pos);
          
          
            SDL_RenderPresent(rend);
            SDL_RenderClear(rend);
            if(loob)
            {
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
            SDL_RenderCopy(rend,texture,NULL,&dstrect);
           // SDL_RenderCopy(rend, tex, &playerRect, &playerPosition);
               // dest_fir.y=playerPosition.y;
               // dest_fir.x=350;
               // SDL_RenderCopy(rend,fir,&src_fir,&playerPosition);
              //  SDL_RenderCopy(rend, tex, &playerRect, &playerPosition);
                //SDL_RenderPresent(rend);
                gameover=4;
                main_game=0;
            SDL_RenderPresent(rend);
          //  SDL_RenderClear(rend);
            }
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
            Mix_PlayChannel(-1,menu,0);
            SDL_RenderClear(rend);
          //  SDL_RenderCopy(rend, fontTex, NULL, &textRect);
            SDL_RenderCopy(rend, tex3, NULL, &start_rect);
            SDL_RenderPresent(rend);

            int mousx, mousy;
            int button = SDL_GetMouseState(&mousx, &mousy);
            // printf("%d %d\n", mousx, mousy);

            if (button & SDL_BUTTON(1))
            {
                if (mousx >= start_rect.x && mousx <= (start_rect.x + start_rect.w) && mousy >= start_rect.y && mousy <= (start_rect.y + start_rect.h))
                {
                    Mix_HaltChannel(-1);
                    Mix_PlayChannel(-1, mouse, 0);
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

            if (buttons & SDL_BUTTON(1))
            {
                if (mousex >= replay_rect.x && mousex <= (replay_rect.x + replay_rect.w) && mousey >= replay_rect.y && mousey <= (replay_rect.y + replay_rect.h))
                {
                    Mix_HaltChannel(-1);
                    Mix_PlayChannel(-1, mouse, 2);

                    boy2_pos.x = 750;
                    boy2_pos.y = 550;
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
                     Mix_PlayChannel(-1, mouse, 2);
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
                    Mix_PlayChannel(-1,mouse,0);
                    main_game=1;
                    gameover=0;
                    y_pos=550.0;
                    boy2_pos.x = 750;
                    boy2_pos.y = 550;
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
            if (FPS/frameTime==1)
            {
                frameTime = 0;
                src_l2b.x += f1W;
                if (src_l2b.x+f1W >= tx1W)
                    src_l2b.x = 0;
            }
          

             
                SDL_RenderClear(rend);
            SDL_SetRenderDrawColor(rend,0,255, 0x00, 0x00);
            SDL_RenderCopy(rend,bg222,NULL,NULL);
           SDL_RenderCopy(rend, cloud, NULL, &cloud_rect);
          // SDL_RenderCopy(rend,texture,NULL,&dstrect);
           SDL_RenderCopy(rend, l2boy, &src_l2b, &dest_l2b);
            SDL_RenderPresent(rend);
        }
        
    }
    Mix_FreeChunk(replay1);
    Mix_FreeChunk(rand1);
    Mix_FreeChunk(rand2);
    Mix_FreeChunk(rand3);
    Mix_FreeChunk(replay1);
     TTF_Quit();
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
 
    SDL_Quit();
  
    return 0;
}