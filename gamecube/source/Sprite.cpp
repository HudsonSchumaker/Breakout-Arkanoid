// 
// Sprite.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Sprite.h"

Sprite::Sprite() {
    this->x = 0;
	this->y = 0;
	this->w = 0;
	this->h = 0;
}

Sprite::Sprite(int w , int h) {
    this->x = 0;
	this->y = 0;
	this->w = w;
	this->h = h;
}

Sprite::Sprite(int x, int y,  int w , int h) {
    this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}