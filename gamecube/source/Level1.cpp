//
// Level1.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Level1.hpp"
#include "Color.hpp"

#include "ball_png.h"
#include "brick_png.h"
#include "paddle_png.h"
#include "background_png.h"

Level1::Level1() {
    load();
    loop();
}

Level1::~Level1() {
    unload();
}

void Level1::loop() {
    for(;;) {
        input(); 
        move();
        collision();
        render();
    }
}

void Level1::input() {
    PAD_ScanPads();
    int dx = PAD_StickX(0);
    if (dx > 18) {
        paddle.move(4);
        return;
    } 
    if (dx < -18) {
        paddle.move(-4);
        return;
    }
}

void Level1::move() {

}

void Level1::collision() {

}

void Level1::render() {
    GRRLIB_FillScreen(Color::getBlack()); 
    GRRLIB_DrawImg(128, 0, back_img, 0, 1, 1, Color::getWhite());

    for (unsigned int i = 0; i < sizeof bricks; i++) {
        if (!bricks[i].isDestroyed()) {
            bricks[i].draw();
        }
    }

    paddle.draw();
    ball.draw();
    
    GRRLIB_Render();           
}

void Level1::load() {
    brick_img = GRRLIB_LoadTexture(brick_png);
    paddle_img = GRRLIB_LoadTexture(paddle_png);
    ball_img = GRRLIB_LoadTexture(ball_png);
    back_img = GRRLIB_LoadTexture(background_png);

    int b = 0;
    for (int l = 0; l < 2; l++) {
        for (int c = 0; c < 12; c++) {
            bricks[b] = Brick(c * brick_img->w + 128, l * brick_img->h + 64);
            bricks[b].setTexture(brick_img);
            b++;
        }
    }

    paddle = Paddle(192, 462);
    paddle.setTexture(paddle_img);

    ball = Ball(200, 440);
    ball.setTexture(ball_img);
    ball.setS(3);
}

void Level1::unload() {
    GRRLIB_FreeTexture(brick_img);
    GRRLIB_FreeTexture(paddle_img);
    GRRLIB_FreeTexture(ball_img);
    GRRLIB_FreeTexture(back_img);
}