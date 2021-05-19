// 
// Switch
// Sprite.hpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#pragma once

#include <SDL2/SDL.h>
#include "Rectangle.hpp"

class Sprite {
protected:
    int x, y, w, h;
		
public:
	SDL_Texture* sprite;
	
	Sprite();
	Sprite(int x, int y);
    Sprite(int x, int y, int w, int h);
	Rectangle getBounds();
	virtual void draw(SDL_Renderer* renderer) = 0;
	
	void setTexture(SDL_Texture* spr) {
		SDL_Point size;
    	SDL_QueryTexture(spr, NULL, NULL, &size.x, &size.y);
		sprite = spr; w = size.x; h = size.y;
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
