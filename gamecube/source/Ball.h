//
// Ball.h
// SchumakerTeam Lab.
// Hudson Schumaker
//

#pragma once
#include "Sprite.h"

class Ball final: public Sprite {
public:
    Ball() : Sprite() {};
    Ball(int x, int y) : Sprite(x, y) {};
    Ball(int x, int y, int w, int h) : Sprite(x, y, w, h) {};
    void draw() override;
    void draw(float d);

private:

};