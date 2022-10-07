#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h>

#define WINDOW_WIDTH (1280)
#define WINDOW_HEIGHT (960)
#define SCROLL_SPEED (700)
#define RECT_SPEED (2.0)

float min(float x, float y){
	if(x<y)
		return x;
	return y;
}
float max(float x, float y){
	if(x>y)
		return x;
	return y;
}




int main(int agr, char* args[]){

	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER)>0){
		printf("video and timer: %s\n",SDL_GetError());
	}
	/*if (!(IMG_Init(IMG_INIT_PNG|IMG_INIT_JPG)))
		printf("image: %s\n",SDL_GetError());*/

	printf("Initialization Complete\n");

	SDL_Window* win = SDL_CreateWindow("SDL Demonstration",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

 	if (!win){
 		printf("window: %s\n",SDL_GetError());
 		SDL_Quit();
		return 1;
 	}

 	Uint32 render_flags = SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC;
 	SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);

 	if (!rend){
 		printf("renderer: %s\n",SDL_GetError());
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return 1;
 	}

 	SDL_Surface* surface = IMG_Load("/home/student/Documents/elonti-belonti/res/redline.jpg");
 	if (!surface){
 		printf("Redbar Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return 1;
 	}

 
 	SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);
 	SDL_FreeSurface(surface);
 	if(!tex){
 		printf("Redline Texture %s\n",SDL_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return 1;
 	}

 	
 	SDL_Rect dest;
 	SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);
 	//printf("%d\n", dest.w);
 	dest.w = 300;//(int) dest.w * 0.1;
 	dest.h = 10;//(int) dest.h * 0.1;
 	//printf("%d\n", dest.w);
 	dest.x = 0;
 	dest.y = (int) WINDOW_HEIGHT - (WINDOW_HEIGHT*0.05);
 	float x_pos = 0;
 	int direction = 1;


 	//load rectangle
 	surface = IMG_Load("/home/student/Documents/elonti-belonti/res/greenrectangle.png");
 	if (!surface){
 		printf("Green rectangle Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return 1;
 	}
 	SDL_Texture* tex2 = SDL_CreateTextureFromSurface(rend, surface);
 	SDL_FreeSurface(surface);
 	if(!tex){
 		printf("Green Rectangle Texture %s\n",SDL_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return 1;
 	}
 	SDL_Rect gr;
 	gr.w=30;
 	gr.h =30;
 	gr.x = (WINDOW_WIDTH-gr.w)/2;
 	gr.y = (WINDOW_HEIGHT-gr.h)/2;
 	float x_vel = RECT_SPEED;
 	float y_vel = RECT_SPEED*-1;
 	float rect_x = gr.x;
 	float rect_y = gr.y;




 	surface = IMG_Load("/home/student/Documents/elonti-belonti/res/gameover.jpeg");
 	if (!surface){
 		printf("Green rectangle Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return 1;
 	}
 	SDL_Texture* gameover_tex = SDL_CreateTextureFromSurface(rend, surface);
 	SDL_FreeSurface(surface);
 	if(!tex){
 		printf("Green Rectangle Texture %s\n",SDL_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return 1;
 	}
 	
 	SDL_Rect gameover_rect;
 	gameover_rect.w = 400;
 	gameover_rect.h = 300;
 	gameover_rect.x = (WINDOW_WIDTH-gameover_rect.w)/2;
 	gameover_rect.y = (WINDOW_HEIGHT-gameover_rect.h)/2-150;



 	surface = IMG_Load("/home/student/Documents/elonti-belonti/res/replay.png");
 	if (!surface){
 		printf("replay Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return 1;
 	}
 	SDL_Texture* replay_tex = SDL_CreateTextureFromSurface(rend, surface);
 	SDL_FreeSurface(surface);
 	if(!tex){
 		printf("replayTexture %s\n",SDL_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return 1;
 	}

 	SDL_Rect replay_rect;
 	replay_rect.w = 300;
 	replay_rect.h = 150;
 	replay_rect.x = (WINDOW_WIDTH-replay_rect.w)/2;
 	replay_rect.y = (WINDOW_HEIGHT-replay_rect.h)/2+100;


 	int close = 0;
 	int gameover = 0;

 	while(!close){
 		SDL_Event event;
 		while(SDL_PollEvent(&event)){
 			switch(event.type){
 				case SDL_QUIT:
 					close = 1;
 					break;
 				case SDL_KEYDOWN:
 					switch(event.key.keysym.scancode){
 						case SDL_SCANCODE_LEFT:
 							x_pos = max(0,x_pos-(SCROLL_SPEED/60));
 							break;
 						case SDL_SCANCODE_RIGHT:
 							x_pos = min(WINDOW_WIDTH-dest.w,x_pos+(SCROLL_SPEED/60));
 								
 					}
 			}
 		}

 		


 		if(gameover == 0){
 			dest.x = (int) x_pos;
	 		gr.x = (int) rect_x;
	 		gr.y = (int) rect_y;

	 		//if(gr.y)

	 		if(rect_x<=0){
	 			rect_x = 0;
	 			x_vel = -x_vel;
	 		}
	 		if(rect_y<=0){
	 			rect_y = 0;
	 			y_vel = -y_vel;
	 		}
	 		if(rect_x>=(WINDOW_WIDTH-gr.w)){
	 			rect_x = WINDOW_WIDTH-gr.w;
	 			x_vel = -x_vel;
	 		}

	 		//collision with redline


	 		if(rect_y>=(WINDOW_HEIGHT-gr.h)){
	 			rect_y = WINDOW_HEIGHT-gr.h;
	 			y_vel = 0;
	 			x_vel = 0;
	 			gameover = 1;
	 		}

	 		if( rect_y >= (dest.y-gr.h) && rect_x>=(dest.x-gr.w) && rect_x<=(dest.x+dest.w)){
	 			rect_y = dest.y-gr.h;
	 			y_vel = -y_vel;
	 		}

	 		
	 		

	 		SDL_RenderClear(rend);
	 		SDL_RenderCopy(rend, tex2, NULL, &gr);
	 		SDL_RenderCopy(rend, tex, NULL, &dest);
	 		SDL_RenderPresent(rend);

	 		//x_pos += (float) direction*(SCROLL_SPEED/60);
	 		//if(x_pos==0||x_pos==(WINDOW_WIDTH-dest.w))
	 		//	direction *= -1;

	 		rect_x += x_vel;
	 		rect_y += y_vel;

	 		SDL_Delay(1000/60);

 		}else{
 			
 			SDL_RenderClear(rend);
 			 
 			//Draq a white point on the screen
 			//For regular geometric shape you can use SDL2_gfx library
 			
 			SDL_SetRenderDrawColor(rend, 0xFF, 0xFF, 0xFF, 0xFF);
        	SDL_RenderDrawPoint(rend, 10, 20);
        	SDL_SetRenderDrawColor(rend, 0x00, 0x00, 0x00, 0xFF);
			


	 		SDL_RenderCopy(rend, gameover_tex, NULL, &gameover_rect);
	 		SDL_RenderCopy(rend, replay_tex, NULL, &replay_rect);

	 		//Render part of the texture?
	 		
	 		SDL_Rect imgPartRect, loc;
	 		SDL_QueryTexture(replay_tex, NULL, NULL, &imgPartRect.w, &imgPartRect.h);
			imgPartRect.x = 0;
			imgPartRect.y = 0;
			imgPartRect.w = imgPartRect.w/2;
			imgPartRect.h = imgPartRect.h/2;

			loc.w=100;
			loc.h=100;
			loc.x=300;
			loc.y=300;;
			SDL_RenderCopy( rend, replay_tex, &imgPartRect, &loc );
			


	 		SDL_RenderPresent(rend);

	 		int mousex, mousey;
 			int buttons = SDL_GetMouseState(&mousex, &mousey);
 			printf("%d %d\n",mousex,mousey);

 			if(buttons & SDL_BUTTON(SDL_BUTTON_LEFT)){
 				//printf("%d %d\n",mousex,mousey);
 				if(mousex>=replay_rect.x && mousex<=(replay_rect.x+replay_rect.w) && mousey>=replay_rect.y && mousey<=(replay_rect.y+replay_rect.h)){
 					gameover = 0;
 					rect_x = (WINDOW_WIDTH-gr.w)/2;
 					rect_y = (WINDOW_HEIGHT-gr.h)/2;
 					x_vel = RECT_SPEED;
 					y_vel = RECT_SPEED*-1;

 				}
 			}
 		}
 		
 	}



 	SDL_Delay(1000);
 	SDL_DestroyRenderer(rend);
 	SDL_DestroyWindow(win);

	SDL_Quit();
	return 0;
}

