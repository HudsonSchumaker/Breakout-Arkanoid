//
// NGC
// Paddle.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Paddle.hpp"
#include "Color.hpp"

void Paddle::move(int dx) {
    this->x += dx;
}

void Paddle::draw() {
    GRRLIB_DrawImg(x, y, sprite, 0, 1, 1, Color::getWhite());
}

void Paddle::draw(float d) {
    GRRLIB_DrawImg(x, y, sprite, d, 1, 1, Color::getWhite());
}
