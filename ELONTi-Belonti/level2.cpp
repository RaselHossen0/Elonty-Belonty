#include "init.h"
#include "loadTex.h"
#include "loadRect.h"
extern int f1W,tx1W;
extern SDL_Rect src_l2b,cloud_rect;
extern SDL_Texture *cloud;
int frametime=0;


void level2(){
    extern void loadRect();
    extern void texCreate();
         cloud_rect.x += 1;
            if (cloud_rect.x >= WINDOW_WIDTH)
                cloud_rect.x = 0;
            frametime++;
            if (frametime==10)
            {
                frametime = 0;
                src_l2b.x += f1W;
                if (src_l2b.x+f1W >= tx1W)
                    src_l2b.x = 0;
            }
}