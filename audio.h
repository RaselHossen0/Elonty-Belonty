#pragma once
#include "init.h"
Mix_Chunk *replay, *replay1, *run1, *run2, *menu, *mouse,*rand1,*rand2,*rand3;
void audio(void)
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
    }
    rand1=Mix_LoadWAV("res/home-logo-13486.mp3");
    rand2=Mix_LoadWAV("res/stomp-logo-3-13783.mp3");
    rand3=Mix_LoadWAV("res/motivational-ident-main-9923.mp3");
    replay = Mix_LoadWAV("res/music.wav");
    replay1 = Mix_LoadWAV("res/game_over.wav");
    menu = Mix_LoadWAV("res/menusound.mp3");
    mouse = Mix_LoadWAV("res/mouseclick");
    run1 = Mix_LoadWAV("");
    run2 = Mix_LoadWAV("");
}
