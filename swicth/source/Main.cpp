// 
// Switch
// Main.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//
 
#include <unistd.h>
#include <sys/stat.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <switch.h>

#include "Level1.hpp"
#include "Splash.hpp"

// some switch buttons
#define JOY_A     0
#define JOY_B     1
#define JOY_X     2
#define JOY_Y     3
#define JOY_PLUS  10
#define JOY_MINUS 11
#define JOY_LEFT  12
#define JOY_UP    13
#define JOY_RIGHT 14
#define JOY_DOWN  15

const int screenWidth = 1280;
const int screenHeight = 720;

void ini();
void end();

SDL_Renderer* renderer;

int main(void) {
    ini();
    
    Splash* splash = new Splash(renderer);

    Level1* lv1 = new Level1(renderer);
    while(!lv1->loop()) {
        delete lv1;
        lv1 = new Level1();
    }
    delete lv1;
    end();
    return 0;
}

void ini() {
    romfsInit();
    chdir("romfs:/");

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    
    SDL_Window *window = SDL_CreateWindow(
        "Breakanoide",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        screenWidth, screenHeight,
        SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
    );
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    
    Mix_AllocateChannels(5);
    Mix_OpenAudio(48000, AUDIO_S16, 2, 4096);
    
    SDL_InitSubSystem(SDL_INIT_JOYSTICK);
    SDL_JoystickEventState(SDL_ENABLE);
    SDL_JoystickOpen(0);
}

void end() {
    IMG_Quit();
    Mix_CloseAudio();
    TTF_Quit();
    Mix_Quit();
    SDL_Quit();      
    romfsExit();
}

