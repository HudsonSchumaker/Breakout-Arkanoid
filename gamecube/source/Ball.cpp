//
// Ball.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Ball.h"
#include "Sprite.h"
#include "Color.h"



void Ball::draw() {
    GRRLIB_DrawImg(x, y, sprite, 0, 1, 1, Color::getWhite());
}

void Ball::draw(float d) {
    GRRLIB_DrawImg(x, y, sprite, d, 1, 1, Color::getWhite());
}