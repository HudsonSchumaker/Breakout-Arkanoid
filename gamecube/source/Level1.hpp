//
// Level1.hpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#pragma once

#include "Canvas.hpp"
#include "Brick.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"

class Level1 final : public Canvas {
public:
    const static int NUMBER_BRICK = 24;
    Paddle paddle;
    Brick bricks[NUMBER_BRICK];    
    Ball ball;

    GRRLIB_texImg* brick_img;
    GRRLIB_texImg* paddle_img;
    GRRLIB_texImg* ball_img;
    GRRLIB_texImg* back_img;

    Level1();
    ~Level1();

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
};