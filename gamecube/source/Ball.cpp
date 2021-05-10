//
// Ball.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Ball.hpp"
#include "Color.hpp"

void draw() {
    GRRLIB_DrawImg(x, y, sprite, 0, 1, 1, Color::getWhite());
}

void draw(float d) {
    GRRLIB_DrawImg(x, y, sprite, d, 1, 1, Color::getWhite());
}