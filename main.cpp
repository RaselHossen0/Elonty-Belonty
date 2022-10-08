#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
int main(int agr, char* args[])
{
	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER)>0)
	{
		printf("Wrong Initialization:%s\n",SDL_GetError());
	}
	printf("successful Initialization\n");
	SDL_Window *win;
	win=SDL_CreateWindow("Elonti-Belonti",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,792,420,0);
	if(!win)
	{
		printf("Failed to create window:%s",SDL_GetError());
		SDL_Quit();
		return 1;
	}
	SDL_Renderer *rendr;
	rendr=SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	if(!rendr)
	{
		printf("Failed to create renderer:%s",SDL_GetError());
		SDL_DestroyWindow(win);
		SDL_Quit();
		return 1;
	}
	SDL_Surface *bg=IMG_Load("res/bg.jpg");
	if(!bg)
	{ 
		printf("Failed to load image:%s",SDL_GetError());
		SDL_DestroyRenderer(rendr);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return 1;
	}
	SDL_Texture* tex = SDL_CreateTextureFromSurface(rendr, bg);
 	SDL_FreeSurface(bg);
 	if(!tex){
 		printf("Redline Texture %s\n",SDL_GetError());
 		SDL_DestroyRenderer(rendr);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return 1;
 	}
	bg=IMG_Load("res/boyr.png");
	if(!bg)
	{
		printf("Failed to load image:%s",SDL_GetError());
		SDL_DestroyRenderer(rendr);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return 1;
	}
	SDL_RenderClear(rendr);
 	SDL_RenderCopy(rendr, tex, NULL, NULL);
 	SDL_RenderPresent(rendr);
	// //Apply the image
	// 		SDL_BlitSurface(bg,NULL,bg,NULL);
			
	// 		//Update the surface
	// 		SDL_UpdateWindowSurface(win);
	
	SDL_Texture* tex2 = SDL_CreateTextureFromSurface(rendr, bg);
 	if(!tex2){
 		printf("Redline Texture %s\n",SDL_GetError());
 		SDL_DestroyRenderer(rendr);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return 1;
 	}
		SDL_Rect dest;
 	SDL_QueryTexture(tex2, NULL, NULL, &dest.w, &dest.h);

 	dest.w = (int) dest.w * 0.1;
 	dest.h = (int) dest.h * 0.1;
 	dest.x = 0;
 	dest.y = (int)dest.h;
 	float x_pos = 100;

 	
int close=1;
 	while(dest.x<=1000){
 		SDL_Event e;
while(close==1) {
    SDL_PollEvent(&e);
    if (e.type == SDL_QUIT) {
        //SDL_Log("Program quit after %i ticks", e.quit.timestamp);
		close=0;
        break;
    }
}
		SDL_RenderClear(rendr);
 		dest.x = (int) x_pos;
 		SDL_RenderCopy(rendr, tex2, NULL, &dest);
 		SDL_RenderPresent(rendr);
 		x_pos += (float) 1200/60;
 		SDL_Delay(1000/60);

 	}


	//SDL_QueryTexture(tex2,NULL,)
	//SDL_RenderClear(rendr);
	//SDL_RenderCopy(rendr, tex2, NULL, NULL);
 	//SDL_RenderCopy(rendr, tex, NULL, NULL);
 	//SDL_RenderPresent(rendr);
	//SDL_RenderClear(rendr);
 	
 //	SDL_RenderPresent(rendr);
	
	//SDL_MixAudio *audio=Mix_LoadWAV("sound/coinsound.mp3");

	SDL_Delay(3000);
 	SDL_DestroyRenderer(rendr);
 	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;

    
}