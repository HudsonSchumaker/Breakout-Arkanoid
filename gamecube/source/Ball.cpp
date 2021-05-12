//
// Ball.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Ball.h"
#include "Color.h"

void Ball::move() {
    x += dx * s;
    y += dy * s;
    
    if (x <= 0) { setDX(1); }
    if (x > 640) { setDX(-1); }
    if (y <= 0) { setDY(1); }
}

void Ball::draw() {
    GRRLIB_DrawImg(x, y, sprite, 0, 1, 1, Color::getWhite());
}

void Ball::draw(float d) {
    GRRLIB_DrawImg(x, y, sprite, d, 1, 1, Color::getWhite());
}