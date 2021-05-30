//
// Win
// Level1.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Level1.hpp"
#include "WColor.hpp"
#include "Point.hpp"
#include "stdio.h"

Level1::Level1() {
    load();
}

Level1::~Level1() {
    unload();
}

bool Level1::loop() {

    int timer = 0;
    while(timer < 60) {
        BeginDrawing();
            ClearBackground(WColor::getBlack());
            DrawTextEx(font, "Level 1", Vector2{Canvas::screenWidth/2 - 60.0f, Canvas::screenHeight/2 - 20.0f}, 32, 0, WColor::getOrange()); 
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

void Level1::input() {
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

void Level1::move() {
    ball.move();
}

void Level1::collision() {
    
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

void Level1::render() {
    BeginDrawing();
        ClearBackground(WColor::getBlack());
        DrawTexture(back_img, 0, 0, WColor::getWhite());     
        
        for (int i = 0; i < NUMBER_BRICK; i++) {
            if (!bricks[i].isDestroyed()) {
                bricks[i].draw();
            }
        }

        paddle.draw();
        ball.draw();		
    EndDrawing();  
}

void Level1::load() {
    brick_img = LoadTexture("resources/red_brick.png");
    paddle_img = LoadTexture("resources/paddle.png");
    ball_img = LoadTexture("resources/ball.png");
    font = LoadFontEx("resources/font.otf", 64, 0, NULL);
    beep = LoadSound("resources/beep.wav"); 
    back_img = LoadTexture("resources/background.png");

    int b = 0;
    for (int l = 0; l < 2; l++) {
        for (int c = 0; c < 12; c++) {
            bricks[b] = Brick(c * brick_img.width + 128, l * brick_img.height + 64);
            bricks[b].setTexture(brick_img);
            b++;
        }
    }

    paddle = Paddle(192, 462);
    paddle.setTexture(paddle_img);

    ball = Ball(200, 440);
    ball.setSpeed(4);
    ball.setTexture(ball_img);
}

void Level1::unload() {
    UnloadTexture(brick_img);
    UnloadTexture(paddle_img);
    UnloadTexture(ball_img);
    UnloadTexture(back_img);
    UnloadFont(font);
    UnloadSound(beep);
}