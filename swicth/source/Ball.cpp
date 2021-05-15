//
// Ball.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Ball.hpp"
#include "Color.hpp"

void Ball::move() {
    x += dx * s;
    y += dy * s;
    
    if (x <= 128) { setDX(1); }
    if (x >= 501) { setDX(-1); }
    if (y <= 0) { setDY(1); }
}

void Ball::draw(SDL_Renderer* renderer) {
    SDL_Rect rect = { x, y, w, h };
    SDL_RenderCopy(renderer, sprite, NULL, &rect);
}

void Ball::draw(double d) {
    //GRRLIB_DrawImg(x, y, sprite, d, 1, 1, Color::getWhite());
}