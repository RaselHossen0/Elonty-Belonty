#pragma once
#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>

#define WINDOW_WIDTH (1280)
#define WINDOW_HEIGHT (720)
#define SCROLL_SPEED (900)
#define RECT_SPEED (5.0)


extern SDL_Window *win;
extern SDL_Renderer *rend;
extern SDL_Surface *surface;


void init();