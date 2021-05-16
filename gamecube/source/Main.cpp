// 
// Main.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include <fat.h>
#include <thread>  
#include <fstream>
#include <gccore.h>
#include <grrlib.h>
#include <asndlib.h>
#include <mp3player.h>

#include "Brick.hpp"
#include "Paddle.hpp"
#include "Ball.hpp"
#include "Color.hpp"
#include "Point.hpp"

#include "font_ttf.h"
#include "brick_png.h"
#include "paddle_png.h"
#include "ball_png.h"
#include "background_png.h"

#include "beep_mp3.h"
#include "Level1.hpp"

const int screenWidth = 640;
const int screenHeight = 480;
void ini();
void input();
void collision();
void render();
void end();
void play();





int main(void) {
    ini();
    
    Level1* lv1 = new Level1();

    end();
    return 0;
}

void input() {
 
  
}

void collision() {
    
}

void render() {
 
}

void ini() {
    ASND_Init();
    MP3Player_Init();
    PAD_Init();
    GRRLIB_Init();
}

void end() {
    //GRRLIB_FreeTTF(font);
    GRRLIB_Exit();
}

void play() {
    MP3Player_PlayBuffer(beep_mp3, beep_mp3_size, NULL);
}