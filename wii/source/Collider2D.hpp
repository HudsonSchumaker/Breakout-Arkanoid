//
// Wii
// Collider2D.hpp
// SchumakerTeam Lab. 
// Hudson Schumaker
//

#pragma once

#include "Point.hpp"
#include "Dimension.hpp"

using namespace std;
class Collider2D final {
	private:
		int x, y, w, h;

	public:
		Collider2D();
		Collider2D(int w, int h);
		Collider2D(int x, int y, int w, int h);
		Collider2D(Point p);
		Collider2D(Dimension d);
		Collider2D(Point p, Dimension d);

		Collider2D getBounds();
		Point getLocation();
		Dimension getSize();
		bool contains(Point p);
		bool contains(Collider2D r);
		bool contains(int x, int y);
		bool contains(int X, int Y, int W, int H);
		bool inside(int X, int Y);
		bool intersects(Collider2D r);

		void setX(int x) { this->x = x; };
		int getX() const { return x; };

		void setY(int y) { this->y = y; };
		int getY() const { return y; };

		void setWidth(int w) { this->w = w; };
		int getWidth() const { return w; };

		void setHeight(int h) { this->h = h; };
		int getHeight() const { return h; };
};