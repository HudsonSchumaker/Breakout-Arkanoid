//
// Brick.h
// SchumakerTeam Lab.
// Hudson Schumaker
//

#pragma once
#include "Sprite.hpp"

class Brick final: public Sprite {
public:
    Brick() : Sprite() {};
    Brick(int x, int y) : Sprite(x, y) {};
    Brick(int x, int y, int w, int h) : Sprite(x, y, w, h) {};
    void draw() override;
    void draw(float d);
};