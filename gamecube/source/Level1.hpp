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

    GRRLIB_texImg* brick_img;
    GRRLIB_texImg* paddle_img;
    GRRLIB_texImg* ball_img;
    GRRLIB_texImg* back_img;

    Paddle paddle;
    Brick bricks[24];    
    Ball ball;

    Level1();
    ~Level1();

    void loop() override;
    void input() override; 
    void move() override;
    void collision() override;
    void render() override;
    void load() override;
    void unload() override;
};