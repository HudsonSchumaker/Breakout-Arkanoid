//
// Brick.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Brick.hpp"
#include "Color.hpp"

void Brick::draw(SDL_Renderer* renderer) {
    SDL_Rect rect = { x, y, w, h };
    SDL_RenderCopy(renderer, sprite, NULL, &rect);
}

void Brick::draw(float d) {
    //GRRLIB_DrawImg(x, y, sprite, d, 1, 1, Color::getWhite());
}


