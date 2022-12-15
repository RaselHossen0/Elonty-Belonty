#include "init.h"
Mix_Chunk *replay, *replay1, *run1, *run2, *menu, *mouse,*rand1,*rand2,*rand3;
Mix_Chunk *tia,*shalik,*akash,*manush,*gari;
void audio(void)
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
    }
    rand1=Mix_LoadWAV("res/aud.mp3");
    rand2=Mix_LoadWAV("res/aud.mp3");
    rand3=Mix_LoadWAV("res/aud.mp3");
    replay = Mix_LoadWAV("res/music.wav");
    replay1 = Mix_LoadWAV("res/game_over.wav");
    menu = Mix_LoadWAV("res/menusound.mp3");
    mouse = Mix_LoadWAV("res/mouseclick.mp3");
    tia =Mix_LoadWAV("res/tia.mp3");
    manush=Mix_LoadWAV("res/manush.mp3");
    shalik=Mix_LoadWAV("res/shalik.mp3");
    gari=Mix_LoadWAV("res/gari.mp3");
    // run1 = Mix_LoadWAV("");
    // run2 = Mix_LoadWAV("");
}