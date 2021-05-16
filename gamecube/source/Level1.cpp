//
// Level1.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Level1.hpp"

Level1::Level1() {
    load();
}

Level1::~Level1() {
    unload();
}

void Level1::loop() {

}

void Level1::input() {

}

void Level1::move() {

}

void Level1::collision() {

}

void Level1::render() {

}

void Level1::load() {
    brick_img = GRRLIB_LoadTexture(brick_png);
    paddle_img = GRRLIB_LoadTexture(paddle_png);
    ball_img = GRRLIB_LoadTexture(ball_png);
    back_img = GRRLIB_LoadTexture(background_png);
}

void Level1::unload() {
    GRRLIB_FreeTexture(brick_img);
    GRRLIB_FreeTexture(paddle_img);
    GRRLIB_FreeTexture(ball_img);
    GRRLIB_FreeTexture(back_img);
}