// 
// Main.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include <gccore.h>
#include <fat.h>
#include <grrlib.h>
#include <asndlib.h>

#include "Sprite.h"
#include "Brick.h"
#include "Paddle.h"
#include "Color.h"

#include "font_ttf.h"
#include "brick_png.h"
#include "paddle_png.h"

const int screenWidth = 640;
const int screenHeight = 480;
void ini();
void input();
void end();

GRRLIB_ttfFont *font;
GRRLIB_texImg *brick_img;
GRRLIB_texImg *paddle_img;

Paddle paddle(192, 462);

int main(void) {
    ini();
    Brick bricks [16];
   
    font = GRRLIB_LoadTTF(font_ttf, font_ttf_size);
    brick_img = GRRLIB_LoadTexture(brick_png);
    paddle_img = GRRLIB_LoadTexture(paddle_png);

    
    paddle.setTexture(paddle_img);

    int k = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            bricks[k] = Brick(j * brick_img->w + 192, i * brick_img->h + 64);
            bricks[k].setTexture(brick_img);
            k++;
        }
    }

    for (;;) {
        GRRLIB_FillScreen(Color::getBlack()); 
        PAD_ScanPads();
        
        if (PAD_ButtonsDown(0) & PAD_BUTTON_START) { break; }
        input();

        for (unsigned int i = 0; i < sizeof bricks; i++) {
            bricks[i].draw();
        }

        paddle.draw();
        

        //GRRLIB_PrintfTTF(screenWidth/2 - 146, screenHeight/2, font, "SchumakerTeam", 64, GRRLIB_WHITE);
        GRRLIB_Render();        
    }

    end();
    return 0;
}

void input() {
 
    int dx =  PAD_StickX(0);
    if (dx > 18) {
        paddle.move(4);
        return;
    } 
    if (dx < -18) {
        paddle.move(-4);
        return;
    }
}

void ini() {
    ASND_Init();
    PAD_Init();
    GRRLIB_Init();
}

void end() {
    GRRLIB_FreeTTF(font);
    GRRLIB_Exit();
  //  
}


