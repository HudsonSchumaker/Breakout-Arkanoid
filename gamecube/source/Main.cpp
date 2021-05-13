// 
// Main.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include <fat.h>
#include <gccore.h>
#include <stdlib.h>
#include <grrlib.h>
#include <asndlib.h>

#include "Brick.hpp"
#include "Paddle.hpp"
#include "Ball.hpp"
#include "Color.hpp"

#include "font_ttf.h"
#include "brick_png.h"
#include "paddle_png.h"
#include "ball_png.h"

const int screenWidth = 640;
const int screenHeight = 480;
void ini();
void input();
void collision();
void end();

GRRLIB_ttfFont* font;
GRRLIB_texImg* brick_img;
GRRLIB_texImg* paddle_img;
GRRLIB_texImg* ball_img;

Paddle paddle(192, 462);
Brick bricks [16];    
Ball ball(200, 440);

int main(void) {
    ini();
    
    ball.setS(2);
    
    font = GRRLIB_LoadTTF(font_ttf, font_ttf_size);
    brick_img = GRRLIB_LoadTexture(brick_png);
    paddle_img = GRRLIB_LoadTexture(paddle_png);
    ball_img = GRRLIB_LoadTexture(ball_png);
    
    paddle.setTexture(paddle_img);
    ball.setTexture(ball_img);

    int b = 0;
    for (int l = 0; l < 4; l++) {
        for (int c = 0; c < 4; c++) {
            bricks[b] = Brick(c * brick_img->w + 192, l * brick_img->h + 64);
            bricks[b].setTexture(brick_img);
            b++;
        }
    }

    for (;;) {
        GRRLIB_FillScreen(Color::getBlack()); 
        PAD_ScanPads();
        
        if (PAD_ButtonsDown(0) & PAD_BUTTON_START) { break; }
        input();
        ball.move();
        collision();
        
        for (unsigned int i = 0; i < sizeof bricks; i++) {
            bricks[i].draw();
        }
        paddle.draw();
        ball.draw();

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

void collision() {
    if (ball.getBounds().getY() > screenHeight) {
        exit(1);
    }
    
    for (int i = 0, j = 0; i < 16; i++) {
        if (bricks[i].isDestroyed()) {
            j++;
        }
        if (j == 16) {
            //message = "Victory";
            exit(0);
        }
    }

    if ((ball.getBounds()).intersects(paddle.getBounds())) {
        int paddleLPos = paddle.getBounds().getX();
        int ballLPos = ball.getBounds().getX();
        int first = paddleLPos + 8;
        int second = paddleLPos + 16;
        int third = paddleLPos + 24;
        int fourth = paddleLPos + 32;

        if (ballLPos < first) {
            ball.setDX(-1);
            ball.setDY(-1);
        }
        if (ballLPos >= first && ballLPos < second) {
            ball.setDX(-1);
            ball.setDY(-1 * ball.getDY());
        }
        if (ballLPos >= second && ballLPos < third) {
            ball.setDX(0);
            ball.setDY(-1);
        }
        if (ballLPos >= third && ballLPos < fourth) {
            ball.setDX(1);
            ball.setDY(-1 * ball.getDY());
        }
        if (ballLPos > fourth) {
            ball.setDX(1);
            ball.setDY(-1);clear
        }
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
}


