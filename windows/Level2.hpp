//
// Win
// Level2.hpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#pragma once
#include "Canvas.hpp"
#include "Brick.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"
#include "raylib.h"

class Level2 final : public Canvas {
    public:
        const static int NUMBER_BRICK = 24;
        
        Level2();
        ~Level2();

        bool loop() override;
        void input() override; 
        void move() override;
        void collision() override;
        void render() override;
        void load() override;
        void unload() override;

    private:
        bool levelOver = false;
        bool levelWon = false;

        Paddle paddle;
        Brick bricks[NUMBER_BRICK];    
        Ball ball;

        Texture2D red_brick_img;
        Texture2D green_brick_img;
        Texture2D paddle_img;
        Texture2D ball_img;
        Texture2D back_img;        
        Font font;
        Sound beep;
};