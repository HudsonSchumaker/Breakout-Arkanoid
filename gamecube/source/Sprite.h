// 
// Sprite.h
// SchumakerTeam Lab.
// Hudson Schumaker
//

#ifndef SPRITE_H
#define SPRITE_H

#include "Rectangle.h"

class Sprite {
    protected:
        int x, y, w, h;

    public:
	    Sprite(int x, int y, int w, int h);
		Rectangle getBounds();
		void draw();

        void setX(int x) { this->x = x; };
	    int getX() const { return x; };

	    void setY(int y) { this->y = y; };
	    int getY() const { return y; };

	    void setWidth(int w) { this->w = w; };
	    int getWidth() const { return w; };

	    void setHeight(int h) { this->h = h; };
	    int getHeight() const { return h; };
};

#endif /* SPRITE_H */