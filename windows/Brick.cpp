//
// Win
// Brick.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Brick.hpp"
#include "WColor.hpp"

void Brick::draw() {
    BeginDrawing();
    {
        DrawTexture(sprite, x, y, WColor::getWhite());         
    }    
    EndDrawing();
}

void Brick::draw(float d) {
    BeginDrawing();
    {
        DrawTextureEx(sprite, Vector2 {(float)x, (float)y}, d, 1.0f, WColor::getWhite());
    }
    EndDrawing();   
}