//
// Brick.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Brick.h"
#include "Sprite.h"
#define GRRLIB_WHITE   0xFFFFFFFF

void Brick::draw() {
    GRRLIB_DrawImg(x, y, sprite, 0, 1, 1, GRRLIB_WHITE);
}