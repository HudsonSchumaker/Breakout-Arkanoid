//
// Brick.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Brick.h"
#include "Sprite.h"
#define GRRLIB_WHITE 0xFFFFFFFF

void Brick::draw() {
    GRRLIB_DrawImg(x, y, sprite, 0, 1, 1, GRRLIB_WHITE);
}

void Brick::draw(float d) {
    GRRLIB_DrawImg(x, y, sprite, d, 1, 1, GRRLIB_WHITE);
}

/*
GRRLIB GRRLIB_DrawImg method params
xpos	Specifies the x-coordinate of the upper-left corner.
ypos	Specifies the y-coordinate of the upper-left corner.
tex	    The texture to draw.
degrees	Angle of rotation.
scaleX	Specifies the x-coordinate scale. -1 could be used for flipping the texture horizontally.
scaleY	Specifies the y-coordinate scale. -1 could be used for flipping the texture vertically.
color	Color in RGBA format.
*/