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

Uint32 getTicks();
bool isStarted();
bool isPaused();
Uint32 mStartTicks;
Uint32 mPausedTicks;
bool mPaused;
bool mStarted;



            


int main(int agr, char *args[])
{
    mStartTicks=0;
    mPausedTicks=0;
    mPaused=false;
    mStarted=false;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) > 0)
    {

        
        printf("video and timer: %s\n", SDL_GetError());
    }
    /*if (!(IMG_Init(IMG_INIT_PNG|IMG_INIT_JPG)))
        printf("image: %s\n",SDL_GetError());*/
    if(TTF_Init()==-1){
        std::cout<<"error";
    }
    else
    std::cout<<"success";
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

    TTF_Font* ff=TTF_OpenFont( "res/fonts/Oswald-Bold.ttf", 28 );
    SDL_Surface* surface=TTF_RenderText_Solid(ff,"hello boy",{255,255,255});
    SDL_Texture* tex=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
    SDL_Rect rect;
    rect.x=10;
    rect.y=10;
    rect.w=400;
    rect.h=100;
    Uint32 getTicks()
{
	//The actual timer time
	Uint32 time = 0;

    //If the timer is running
    if( mStarted )
    {
        //If the timer is paused
        if( mPaused )
        {
            //Return the number of ticks when the timer was paused
            time = mPausedTicks;
        }
        else
        {
            //Return the current time minus the start time
            time = SDL_GetTicks() - mStartTicks;
        }
    }

    return time;
}

bool isStarted()
{
	//Timer is running and paused or unpaused
    return mStarted;
}

bool isPaused()
{
	//Timer is running and paused
    return mPaused && mStarted;
}

    bool running =true;
    
        while( running)
			{
				//Handle events on queue
				 SDL_Event e;
               while(SDL_PollEvent(&e)){
                if(e.type==SDL_QUIT){
                running=false;
                 }
					//Reset start time on return keypress
					else if( e.type == SDL_KEYDOWN )
					{
						//Start/stop
						if( e.key.keysym.sym == SDLK_s )
						{
							if( timer.isStarted() )
							{
								//timer.stop();
								//Stop the timer
							mStarted = false;

							//Unpause the timer
							mPaused = false;

							//Clear tick variables
							mStartTicks = 0;
							mPausedTicks = 0;


							}
							else
							{
								//timer.start();
								mStarted=true;
								mPaused=false;
							}
						}
						//Pause/unpause
						else if( e.key.keysym.sym == SDLK_p )
						{
							if( timer.isPaused() )
							{
								//timer.unpause();
								 if( mStarted && mPaused )
								{
									//Unpause the timer
									mPaused = false;

									//Reset the starting ticks
									mStartTicks = SDL_GetTicks() - mPausedTicks;

									//Reset the paused ticks
									mPausedTicks = 0;
								}
							}
							else
							{
								//timer.pause();
								 //If the timer is running and isn't already paused
								if( mStarted && !mPaused )
								{
									//Pause the timer
									mPaused = true;

									//Calculate the paused ticks
									mPausedTicks = SDL_GetTicks() - mStartTicks;
									mStartTicks = 0;
								}
							}
						}
					}
				}

				
				
				SDL_SetRenderDrawColor( rend, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear(rend);


				SDL_RenderPresent( rend );
			}
        SDL_SetRenderDrawColor(rend,0,0,0xFF,SDL_ALPHA_OPAQUE);
        SDL_RenderClear(rend);
        SDL_RenderCopy(rend,tex,NULL,&rect);
        SDL_RenderPresent(rend);
    }

    
    

    //SDL_Delay(100);
    
   
    SDL_DestroyTexture(tex);
    SDL_DestroyWindow(win);
    TTF_CloseFont(ff);

    SDL_Quit();
    return 0;
}

