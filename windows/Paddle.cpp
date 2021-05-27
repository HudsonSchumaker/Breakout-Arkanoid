//
// Win
// Paddle.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Paddle.hpp"
#include "WColor.hpp"

void Paddle::move(int dx) {
    this->x += dx;
}

void Paddle::draw() {
    BeginDrawing();
    {
        DrawTexture(sprite, x, y, WColor::getWhite());         
    }    
    EndDrawing();
}

void Paddle::draw(float d) {
    BeginDrawing();
    {
        DrawTextureEx(sprite, Vector2 {(float)x, (float)y}, d, 1.0f, WColor::getWhite());
    }
    EndDrawing();   
}
