//
// macOS 
// Ball.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Ball.hpp"
#include "WColor.hpp"

void Ball::move() {
    x += dx * s;
    y += dy * s;
    
    if (x <= 128) { setDX(1); }
    if (x >= 501) { setDX(-1);}
    if (y <= 0)   { setDY(1); }
}

void Ball::draw() {
    DrawTexture(sprite, x, y, WColor::getWhite());             
}

void Ball::draw(float d) {
    float fx = x;
    float fy = y;
    Vector2 pos = {fx, fy};
    DrawTextureEx(sprite, pos, d, 1.0f, WColor::getWhite()); 
}
