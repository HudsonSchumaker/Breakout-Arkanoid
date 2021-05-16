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

const int screenWidth = 640;
const int screenHeight = 480;
void ini();
void input();
void collision();
void render();
void end();
void play();

GRRLIB_ttfFont* font;
GRRLIB_texImg* brick_img;
GRRLIB_texImg* paddle_img;
GRRLIB_texImg* ball_img;
GRRLIB_texImg* back_img;

Paddle paddle(192, 462);
Brick bricks [24];    
Ball ball(200, 440);

int main(void) {
    ini();
    
    ball.setS(3);
    
    font = GRRLIB_LoadTTF(font_ttf, font_ttf_size);
    brick_img = GRRLIB_LoadTexture(brick_png);
    paddle_img = GRRLIB_LoadTexture(paddle_png);
    ball_img = GRRLIB_LoadTexture(ball_png);
    back_img = GRRLIB_LoadTexture(background_png);
    
    paddle.setTexture(paddle_img);
    ball.setTexture(ball_img);

    int b = 0;
    for (int l = 0; l < 2; l++) {
        for (int c = 0; c < 12; c++) {
            bricks[b] = Brick(c * brick_img->w + 128, l * brick_img->h + 64);
            bricks[b].setTexture(brick_img);
            b++;
        }
    }

    for (;;) {
        GRRLIB_FillScreen(Color::getBlack()); 
        GRRLIB_DrawImg(128, 0, back_img, 0, 1, 1, Color::getWhite());
        PAD_ScanPads();
        
        if (PAD_ButtonsDown(0) & PAD_BUTTON_START) { break; }
        input();
        ball.move();
        collision();
        render(); 
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

    for (unsigned int i = 0, j = 0; i < sizeof bricks; i++) {
        if (bricks[i].isDestroyed()) {
            j++;
        }
        if (j == 16) {
            //message = "Victory";
            //GRRLIB_PrintfTTF(screenWidth/2 - 146, screenHeight/2, font,"Victory", 64, Color::getBlack());
            
            // exit(0);
        }
    }

    if ((ball.getBounds()).intersects(paddle.getBounds())) {
        int paddleLPos = paddle.getBounds().getX();
        int ballLPos = ball.getBounds().getX();
        int first  = paddleLPos + 8;
        int second = paddleLPos + 16;
        int third  = paddleLPos + 24;
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
            ball.setDY(-1);
        }
    }

    for (unsigned int i = 0; i < sizeof bricks; i++) {
        if ((ball.getBounds()).intersects(bricks[i].getBounds())) {

            if(bricks[i].isDestroyed()) {
                return;
            }

            bricks[i].setDestroyed(true);
            
            int ballLeft   = ball.getBounds().getX();
            int ballHeight = ball.getBounds().getHeight();
            int ballWidth  = ball.getBounds().getWidth();
            int ballTop    = ball.getBounds().getY();

            Point pointRight(ballLeft + ballWidth + 1, ballTop);
            Point pointLeft(ballLeft - 1, ballTop);
            Point pointTop(ballLeft, ballTop - 1);
            Point pointBottom(ballLeft, ballTop + ballHeight + 1);

            if (bricks[i].getBounds().contains(pointRight)) {
                ball.setDX(-1);
            }
            else if (bricks[i].getBounds().contains(pointLeft)) {
                ball.setDX(1);
            }
            if (bricks[i].getBounds().contains(pointTop)) {
                ball.setDY(1);
            }
            else if (bricks[i].getBounds().contains(pointBottom)) {
                ball.setDY(-1);
            }
            
            play();
        }
    }
}

void render() {
    for (unsigned int i = 0; i < sizeof bricks; i++) {
        if (!bricks[i].isDestroyed()) {
            bricks[i].draw();
        }
    }
    paddle.draw();
    ball.draw();

    //GRRLIB_PrintfTTF(screenWidth/2 - 146, screenHeight/2, font, "SchumakerTeam", 64, GRRLIB_WHITE);
    GRRLIB_Render();       
}

void ini() {
    ASND_Init();
    MP3Player_Init();
    PAD_Init();
    GRRLIB_Init();
}

void end() {
    GRRLIB_FreeTTF(font);
    GRRLIB_Exit();
}

void play() {
    MP3Player_PlayBuffer(beep_mp3, beep_mp3_size, NULL);
}