//
// Switch 
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

void Ball::draw(SDL_Renderer* renderer, double d) {
    SDL_Rect rect = { x, y, w, h };
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    SDL_RenderCopyEx(renderer, sprite, NULL, &rect, d, NULL, flip);
}
