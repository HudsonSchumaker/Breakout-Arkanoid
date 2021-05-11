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
    void move();
    void reset(int x, int y);
    void draw() override;
    void draw(float d);

    int getDX() const { return dx; };
	void setDX(int dx) { this->dx = dx; };

    int getDY() const { return dy; };
    void setDY(int dy) { this->dy = dy; };

private:
    int dx, dy;
};