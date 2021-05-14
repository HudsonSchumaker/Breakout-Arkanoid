//
// Paddle.hpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#pragma once

#include "Sprite.hpp"

class Paddle final : public Sprite {
public:
    Paddle() : Sprite() {};
    Paddle(int x, int y) : Sprite(x, y) {};
    Paddle(int x, int y, int w, int h) : Sprite(x, y, w, h) {};
    void move(int dx);
    void draw() override;
    void draw(float d);
};