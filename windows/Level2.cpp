//
// Win
// Level2.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Level2.hpp"
#include "Point.hpp"
#include "WColor.hpp"
#include <stdio.h>
#include <stdlib.h>

Level2::Level2() {
    load();
}

Level2::~Level2() {
    unload();
}

bool Level2::loop() {

    int timer = 0;
    while(timer < 60) {
        BeginDrawing();
            ClearBackground(WColor::getBlack());
            DrawTextEx(font, "Level 2", Vector2{Canvas::screenWidth/2 - 60.0f, Canvas::screenHeight/2 - 20.0f}, 32, 0, WColor::getOrange()); 
        EndDrawing();
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

void Level2::input() {
    if (WindowShouldClose()) {
        unload();
        exit(0);
    }
    
    if (IsGamepadAvailable(0)) {
        if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) {
            paddle.move(5);
            return;
        }

        if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) {
            paddle.move(-5);
            return;
        }
    }
}

void Level2::move() {
    ball.move();
}

void Level2::collision() {
    
    if (ball.getBounds().getY() > screenHeight) {
        levelOver = true;
    }

    for (int i = 0, j = 0; i < NUMBER_BRICK; i++) {
        if (bricks[i].isDestroyed()) {
            j++;
        }
        if (j > 23) {
            levelWon = true;
        }
    }    
    for (int i = 0; i < NUMBER_BRICK; i++) {
        if ((ball.getBounds()).intersects(bricks[i].getBounds())) {
            if(bricks[i].isDestroyed()) {
                return;
            }

            bricks[i].setDestroyed(true);
            PlaySound(beep);

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

void Level2::render() {
    while(!levelOver && !levelWon) { 
        input(); 
        move();
        collision();
        render(); 
    } 
}

void Level2::load() {
    green_brick_img = LoadTexture("resources/green_brick.png");
    red_brick_img = LoadTexture("resources/red_brick.png");
    paddle_img = LoadTexture("resources/paddle.png");
    ball_img = LoadTexture("resources/ball.png");
    font = LoadFontEx("resources/font.otf", 64, 0, NULL);
    beep = LoadSound("resources/beep.wav"); 
    back_img = LoadTexture("resources/background.png");

    int b = 0;
    for (int l = 0; l < 2; l++) {
        for (int c = 0; c < 12; c++) {
            bricks[b] = Brick(c * red_brick_img.width + 128, l * red_brick_img.height + 64);
            if (c % 2 == 0) {
                bricks[b].setTexture(red_brick_img);
            } else {
                bricks[b].setTexture(green_brick_img);
            }
            b++;
        }
    }

    paddle = Paddle(192, 462);
    paddle.setTexture(paddle_img);

    ball = Ball(200, 440);
    ball.setSpeed(4);
    ball.setTexture(ball_img);
}

void Level2::unload() {
    UnloadTexture(green_brick_img);
    UnloadTexture(red_brick_img);
    UnloadTexture(paddle_img);
    UnloadTexture(ball_img);
    UnloadTexture(back_img);
    UnloadFont(font);
    UnloadSound(beep);
}