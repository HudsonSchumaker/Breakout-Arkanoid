// 
// Sprite.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Sprite.h"
#include "Rectangle.h"

Sprite::Sprite() {}

Sprite::Sprite(int x, int y) {
	this->x = x;
	this->y = y;
}

Sprite::Sprite(int x, int y, int w, int h) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

Rectangle Sprite::getBounds() {
	return Rectangle(this->x, this->y, this->w, this->h);
}