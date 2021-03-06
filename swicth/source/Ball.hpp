//
// Switch
// Ball.hpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#pragma once
#include "Sprite.hpp"

class Ball final : public Sprite {
public:
    Ball() : Sprite(), dx(1), dy(-1), s(1) {};
    Ball(int x, int y) : Sprite(x, y), dx(1), dy(-1), s(0) {};
    Ball(int x, int y, int w, int h) : Sprite(x, y, w, h), dx(1), dy(-1), s(0) {};
    
    void move();
    void reset(int x, int y);
    void draw(SDL_Renderer* renderer) override;
    void draw(SDL_Renderer* renderer, double d);

    void setS(int s) { this->s = s; }; 
    int getDX() const { return dx; };
	void setDX(int dx) { this->dx = dx; };
    int getDY() const { return dy; };
    void setDY(int dy) { this->dy = dy; };

private:
    int dx, dy;
    int s;
};