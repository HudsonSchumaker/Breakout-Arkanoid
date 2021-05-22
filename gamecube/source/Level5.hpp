//
// NGC
// Level5.hpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#pragma once

#include "Canvas.hpp"
#include "Brick.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"

class Level5 final : public Canvas {
    public:
        const static int NUMBER_BRICK = 12;
        
        Level5();
        ~Level5();

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
        int moveBrick = 1;

        Paddle paddle;
        Brick bricks[NUMBER_BRICK];    
        Ball ball;

        GRRLIB_texImg* red_brick_img;
        GRRLIB_texImg* yellow_brick_img;

        GRRLIB_texImg* paddle_img;
        GRRLIB_texImg* ball_img;
        GRRLIB_texImg* back_img;
};