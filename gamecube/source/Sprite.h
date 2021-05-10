// 
// Sprite.h
// SchumakerTeam Lab.
// Hudson Schumaker
//

#ifndef SPRITE_H
#define SPRITE_H

#include <grrlib.h>
#include "Rectangle.h"

class Sprite {
protected:
        int x, y, w, h;
		
public:
	Sprite();
	Sprite(int x, int y);
    	Sprite(int x, int y, int w, int h);
	Rectangle getBounds();
	GRRLIB_texImg *sprite;
	void setTexture(GRRLIB_texImg *spr) {
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
#endif /* SPRITE_H */
