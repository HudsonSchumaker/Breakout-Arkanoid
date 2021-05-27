//
// Win
// Paddle.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Paddle.hpp"
#include "Color.hpp"
#include "raylib.h"

void Paddle::move(int dx) {
    this->x += dx;
}

void Paddle::draw() {
    BeginDrawing();
        ClearBackground(WColor::getWhite());
        DrawTexture(sprite, x, y, WColor::getWhite());         
    EndDrawing();
}

void Paddle::draw(float d) {
    BeginDrawing();
        DrawTextureEx(sprite, Vector2 {x, y}, d, 1.0f, WColor::getWhite());
    EndDrawing();   
}
