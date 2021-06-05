//
// Wii
// Level4.hpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#pragma once

#include "Canvas.hpp"
#include "Brick.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"

class Level4 final : public Canvas {
    public:
        const static int NUMBER_BRICK = 36;
        
        Level4();
        ~Level4();

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

        GRRLIB_texImg* red_brick_img;
        GRRLIB_texImg* green_brick_img;
        GRRLIB_texImg* yellow_brick_img;
        GRRLIB_texImg* blue_brick_img;
        GRRLIB_texImg* paddle_img;
        GRRLIB_texImg* ball_img;
        GRRLIB_texImg* back_img;
        GRRLIB_ttfFont *font;
};