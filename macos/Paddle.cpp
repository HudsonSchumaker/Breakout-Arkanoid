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
    DrawTexture(sprite, x, y, WColor::getWhite());         
}

void Paddle::draw(float d) {
    BeginDrawing();
    {
        float fx = x;
        float fy = y;
        Vector2 pos = {fx, fy};
        DrawTextureEx(sprite, pos, d, 1.0f, WColor::getWhite());
    }
    EndDrawing();   
}
