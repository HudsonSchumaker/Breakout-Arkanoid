// 
// Switch
// Sprite.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Sprite.hpp"

Sprite::Sprite() {}
Sprite::Sprite(int x, int y) : x(x), y(y) {}
Sprite::Sprite(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}

Rectangle Sprite::getBounds() {
	return Rectangle(this->x, this->y, this->w, this->h);
}