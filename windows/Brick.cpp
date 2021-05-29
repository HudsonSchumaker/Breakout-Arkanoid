//
// Win
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
    DrawTextureEx(sprite, Vector2 {(float)x, (float)y}, d, 1.0f, WColor::getWhite());  
}