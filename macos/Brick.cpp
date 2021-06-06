//
// macOS
// Brick.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Brick.hpp"
#include "WColor.hpp"

void Brick::draw() {
    DrawTexture(sprite, x, y, WColor::getWhite());        
}

void Brick::draw(float d) {
    float fx = x;
    float fy = y;
    Vector2 pos = {fx, fy};
    DrawTextureEx(sprite, pos, d, 1.0f, WColor::getWhite());  
}