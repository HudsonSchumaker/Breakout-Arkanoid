//
// Paddle.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Paddle.hpp"
#include "Color.hpp"

void Paddle::move(int dx) {
    this->x += dx;
}

void Paddle::draw(SDL_Renderer* renderer) {
    SDL_Rect rect = { x, y, w, h };
    SDL_RenderCopy(renderer, sprite, NULL, &rect);
}

void Paddle::draw(float d) {
    //GRRLIB_DrawImg(x, y, sprite, d, 1, 1, Color::getWhite());
}
