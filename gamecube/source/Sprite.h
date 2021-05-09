// 
// Sprite.h
// SchumakerTeam Lab.
// Hudson Schumaker
//

#ifndef SPRITE_H
#define SPRITE_H

class Sprite {
    private:
        int x, y , w, h;

    public:
		Sprite();
		Sprite(int w, int h);
		Sprite(int x, int y, int w, int h);

		virtual void draw();

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