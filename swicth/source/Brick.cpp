//
// Brick.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Brick.hpp"

void Brick::draw(SDL_Renderer* renderer) {
    SDL_Rect rect = { x, y, w, h };
    SDL_RenderCopy(renderer, sprite, NULL, &rect);
}

void Brick::draw(SDL_Renderer* renderer, double d) {
    SDL_Rect rect = { x, y, w, h };
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    SDL_RenderCopyEx(renderer, sprite, NULL, &rect, d, NULL, flip);
}