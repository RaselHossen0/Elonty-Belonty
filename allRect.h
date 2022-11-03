#pragma once
#include "header.h"

SDL_Rect start_rect;
 SDL_Rect playerRect;    
    SDL_Rect playerPosition;
 SDL_Rect plarRect3;     // rect for a single frame of the sprite sheet
    SDL_Rect plarPosition3;
    SDL_Rect plarRect22;     // rect for a single frame of the sprite sheet
    SDL_Rect plarPosition22; 
    SDL_Rect plarRect2;     // rect for a single frame of the sprite sheet
    SDL_Rect plarPosition2;
    SDL_Rect gameover_rect;
    SDL_Rect boy2;    
    SDL_Rect boy2_pos;
      SDL_Rect playrRect;     // rect for a single frame of the sprite sheet
    SDL_Rect playrPosition;
        SDL_Rect next;
         SDL_Rect src_l2b, dest_l2b;
          SDL_Rect plarRect4;     // rect for a single frame of the sprite sheet
    SDL_Rect plarPosition4;
       SDL_Rect plarRect;     // rect for a single frame of the sprite sheet
    SDL_Rect plarPosition;

    SDL_Rect plarRect1;     // rect for a single frame of the sprite sheet
    SDL_Rect plarPosition1;

    SDL_Rect cloud_rect;
      SDL_Rect replay_rect;

     SDL_Rect src_fir,dest_fir;

     
  int frameWidth, frameHeight;
    int textureWidth, textureHeight;

    int tx1W, tx1H, f1W, f1H;

     int framWidth, framHeight;
    int texturWidth, texturHeight;
    int txturWidth2, txturHeight2;
      int tfW,tfH,fw,fh;
      int txturWidth4, txturHeight4,txturHeight;
      int txturWidth22,txturHeight22,txturWidth3,txturHeight3,txturWidth1,txturWidth,txturHeight1;
         struct rect r2(txturWidth1 / 10, txturHeight1);
         struct rect r8(txturWidth4 / 10, txturHeight4);
 struct rect r5(txturWidth2 / 10, txturHeight2);
    struct rect r3(txturWidth / 10, txturHeight);
      struct rect r1(texturWidth / 4, texturHeight / 3);
    struct rect r6(txturWidth2 / 10, txturHeight2);
          struct rect r7(txturWidth1 / 10, txturHeight1);
void rect3(){
    start_rect.w = 300;
    start_rect.h = 150;
    start_rect.x = (WINDOW_WIDTH - start_rect.w) / 2;
    start_rect.y = (WINDOW_HEIGHT - start_rect.h) / 2;
    // rect for the whole sprite sheet
    playerPosition.x = 350;
    playerPosition.y = 550;
    playerPosition.w = 150;
    playerPosition.h = 150; // ei rec(square) er moddher kothao texture (runman) load hobe

  
    SDL_QueryTexture(tex, NULL, NULL, &textureWidth, &textureHeight);

    frameWidth = textureWidth / 9;
    frameHeight = textureHeight;
    // printf("%d %d",frameHeight,frameWidth);
    playerRect.x = playerRect.y = 0;
    playerRect.w = frameWidth;
    playerRect.h = frameHeight;
     // rect for the whole sprite sheet
    boy2_pos.x = 750;
    boy2_pos.y = 550;
    boy2_pos.w = 150;
    boy2_pos.h = 150; // ei rec(square) er moddher kothao texture (runman) load hobe

    boy2.x = 400;
    boy2.y = 50;
    boy2.w = frameWidth;
    boy2.h = frameHeight;
    // SDL_SetRenderDrawColor(rend,0xFF,0,0,0xFF);

    

    gameover_rect.w = 400;
    gameover_rect.h = 300;
    gameover_rect.x = (WINDOW_WIDTH - gameover_rect.w) / 2;
    gameover_rect.y = (WINDOW_HEIGHT - gameover_rect.h) / 2 - 250;
      // rect for the whole sprite sheet
    playrPosition.x = 568;
    playrPosition.y = 30;
    playrPosition.w = 75;
    playrPosition.h = 75; // ei rec(square) er moddher kothao texture (runman) load hobe

    

    // SDL_QueryTexture(next_level,NULL,NULL,&next.w,&next.h);
    next.w = 180;
    next.h = 180;
    next.x = 490;
    next.y = 450;
    

    
   
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
   
    SDL_QueryTexture(Putul_Tex, NULL, NULL, &texturWidth, &texturHeight);

    framWidth = texturWidth / 4;
    framHeight = texturHeight / 3;
    playrRect.x = playrRect.y = 0;
    playrRect.w = framWidth;
    playrRect.h = framHeight;


    playrRect.x = playrRect.y = 0;
    playrRect.w = r1.frmWid;
    playrRect.h = r1.frmHit;

   // rect for the whole sprite sheet
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
 // rect for the whole sprite sheet
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
 // rect for the whole sprite sheet
    plarPosition2.x = 20;
    plarPosition2.y = 100;
    plarPosition2.w = 130;
    plarPosition2.h = 130;

    
    SDL_QueryTexture(fire_Tex, NULL, NULL, &txturWidth2, &txturHeight2);

    struct rect r5(txturWidth2 / 10, txturHeight2);
    plarRect2.x = plarRect2.y = 0;
    plarRect2.w = r5.frmWid;
    plarRect2.h = r5.frmHit;

    
// rect for the whole sprite sheet
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

    // rect for the whole sprite sheet
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

    // rect for the whole sprite sheet
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

    
  
    replay_rect.w = 200;
    replay_rect.h = 100;
    replay_rect.x = (WINDOW_WIDTH - replay_rect.w) / 2;
    replay_rect.y = (WINDOW_HEIGHT - replay_rect.h) / 2;

   

    
    SDL_QueryTexture(cloud, NULL, NULL, &cloud_rect.w, &cloud_rect.h);
    cloud_rect.w /= 8;
    cloud_rect.h /= 8;
    cloud_rect.x = 0;
    cloud_rect.y = 0;

  
    SDL_QueryTexture(fir,NULL,NULL,&tfW,&tfH);
    fw=tfW/8;
    fh=tfH/4;
    src_fir.w=fw;
    src_fir.h=fh;
    src_fir.x=0;
    src_fir.y=0;
    dest_fir.w=playerPosition.w*2;
    dest_fir.h=playerPosition.h*2;
    dest_fir.x=dest_fir.y=0;
}