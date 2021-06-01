// 
// Wii
// Sprite.hpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#pragma once
#include <grrlib.h>
#include "Rectangle.hpp"

class Sprite {
	protected:
    	int x, y, w, h;
		
	public:
		GRRLIB_texImg *sprite;
	
		Sprite();
		Sprite(int x, int y);
    	Sprite(int x, int y, int w, int h);
		Rectangle getBounds();
		virtual void draw() = 0;
	
		void setTexture(GRRLIB_texImg* spr) {
			sprite = spr; w = sprite->w; h = sprite->h;
		};
		
		int getX() const { return x; };
		void setX(int x) { this->x = x; };

    	int getY() const { return y; };
    	void setY(int y) { this->y = y; };

    	int getWidth() const { return w; };
    	void setWidth(int w) { this->w = w; };

		int getHeight() const { return h; };
   		void setHeight(int h) { this->h = h; };
};
