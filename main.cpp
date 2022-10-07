#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
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
	SDL_Surface *bg=IMG_Load("/home/student/Documents/elonti-belonti/res/replay.png");
	if(!bg)
	{
		printf("Failed to load image:%s",SDL_GetError());
		SDL_DestroyRenderer(rendr);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return 1;
	}
	//Apply the image
			SDL_BlitSurface(bg,NULL,bg,NULL);
			
			//Update the surface
			SDL_UpdateWindowSurface(win);
	// SDL_Texture* tex = SDL_CreateTextureFromSurface(rendr, bg);
 	// //SDL_FreeSurface(bg);
 	// if(!tex){
 	// 	printf("Redline Texture %s\n",SDL_GetError());
 	// 	SDL_DestroyRenderer(rendr);
 	// 	SDL_DestroyWindow(win);
 	// 	SDL_Quit();
	// 	return 1;
 	// }
	SDL_Delay(6000);
 	SDL_DestroyRenderer(rendr);
 	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;

    
}