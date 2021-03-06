//
// NGC
// Level4.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Level4.hpp"
#include "Color.hpp"
#include "Point.hpp"
#include <mp3player.h>

#include "ball_png.h"
#include "red_brick_png.h"
#include "green_brick_png.h"
#include "yellow_brick_png.h"
#include "blue_brick_png.h"
#include "paddle_png.h"
#include "background_png.h"
#include "beep_mp3.h"
#include "font_ttf.h"

Level4::Level4() {
    load();
}

Level4::~Level4() {
    unload();
}

bool Level4::loop() {
    int timer = 0;
    while(timer < 60) {
        GRRLIB_FillScreen(Color::getBlack()); 
        GRRLIB_PrintfTTF(Canvas::screenWidth/2 - 60, Canvas::screenHeight/2 -20, font, "Level 4", 32, Color::getOrange());
        GRRLIB_Render();
        timer++;
    }

    while(!levelOver && !levelWon) {
        input(); 
        move();
        collision();
        render(); 
    }
    return levelWon;
}

void Level4::input() {
    PAD_ScanPads();
    int dx = PAD_StickX(0);
    if (dx > 18) {
        paddle.move(5);
        return;
    } 
    if (dx < -18) {
        paddle.move(-5);
        return;
    }
}

void Level4::move() {
    ball.move();
}

void Level4::collision() {
    
    if (ball.getBounds().getY() > screenHeight) {
        levelOver = true;
    }

    for (int i = 0, j = 0; i < NUMBER_BRICK; i++) {
        if (bricks[i].isDestroyed()) {
            j++;
        }
        if (j > 35) {
            levelWon = true;
        }
    }    
    for (int i = 0; i < NUMBER_BRICK; i++) {
        if ((ball.getBounds()).intersects(bricks[i].getBounds())) {
            if(bricks[i].isDestroyed()) {
                return;
            }

            bricks[i].setDestroyed(true);
            MP3Player_PlayBuffer(beep_mp3, beep_mp3_size, NULL);

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
}

void Level4::render() {
    GRRLIB_FillScreen(Color::getBlack()); 
    GRRLIB_DrawImg(128, 0, back_img, 0, 1, 1, Color::getWhite());

    for (int i = 0; i < NUMBER_BRICK; i++) {
        if (!bricks[i].isDestroyed()) {
            bricks[i].draw();
        }
    }

    paddle.draw();
    ball.draw();

    GRRLIB_Render();           
}

void Level4::load() {
    red_brick_img = GRRLIB_LoadTexture(red_brick_png);
    green_brick_img = GRRLIB_LoadTexture(green_brick_png);
    yellow_brick_img = GRRLIB_LoadTexture(yellow_brick_png);
    blue_brick_img = GRRLIB_LoadTexture(blue_brick_png);
    paddle_img = GRRLIB_LoadTexture(paddle_png);
    ball_img = GRRLIB_LoadTexture(ball_png);
    back_img = GRRLIB_LoadTexture(background_png);
    font = GRRLIB_LoadTTF(font_ttf, font_ttf_size);

    int b = 0;
    for (int l = 0; l < 3; l++) {
        for (int c = 0; c < 12; c++) {
            bricks[b] = Brick(c * red_brick_img->w + 128, l * red_brick_img->h + 64);
            if (c % 2 == 0) {
                if (c % 4 == 0) {
                    bricks[b].setTexture(yellow_brick_img);
                } else {
                    bricks[b].setTexture(red_brick_img);
                }
            } else {
                if (c% 3 == 0) {
                    bricks[b].setTexture(green_brick_img);
                } else {
                     bricks[b].setTexture(blue_brick_img);
                }
            }
            b++;
        }
    }

    paddle = Paddle(240, 462);
    paddle.setTexture(paddle_img);

    ball = Ball(244, 440);
    ball.setSpeed(4);
    ball.setTexture(ball_img);
}

void Level4::unload() {
    GRRLIB_FreeTexture(red_brick_img);
    GRRLIB_FreeTexture(green_brick_img);
    GRRLIB_FreeTexture(yellow_brick_img);
    GRRLIB_FreeTexture(blue_brick_img);
    GRRLIB_FreeTexture(paddle_img);
    GRRLIB_FreeTexture(ball_img);
    GRRLIB_FreeTexture(back_img);
    GRRLIB_FreeTTF(font);
}