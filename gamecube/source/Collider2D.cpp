//
// NGC
// Rectangle.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Collider2D.hpp"

Collider2D::Collider2D(): x(0), y(0), w(0), h(0) {}

Collider2D::Collider2D(int w, int h): x(0), y(0), w(w), h(h) {}

Collider2D::Collider2D(int x, int y, int w, int h): x(x), y(y), w(w), h(h) {}

Collider2D::Collider2D(Point p): x(p.getX()), y(p.getY()), w(0), h(0) {}

Collider2D::Collider2D(Dimension d): x(0), y(0), w(d.getWidth()), h(d.getHeight()) {}

Collider2D::Collider2D(Point p, Dimension d): x(p.getX()), y(p.getY()), w(d.getWidth()), h(d.getHeight()) {}

Collider2D Collider2D::getBounds() {
	return Collider2D(this->x, this->y, this->w, this->h);
}

Point Collider2D::getLocation() {
	return Point(this->x, this->y);
}

Dimension Collider2D::getSize() {
	return Dimension(this->w, this->h);
}

bool Collider2D::contains(Point p) {
	return contains(p.getX(), p.getY());
}

bool Collider2D::contains(Collider2D c) {
	return contains(c.getX(), c.getY(), c.getWidth(), c.getHeight());
}

bool Collider2D::contains(int x, int y) {
	return inside(x, y);
}

bool Collider2D::contains(int X, int Y, int W, int H) {
	int w_ = this->w;
	int h_ = this->h;
	if ((w_ | h_ | W | H) < 0) {
		return false;
	}
	
	int x_ = this->x;
	int y_ = this->y;
	if (X < x_ || Y < y_) {
		return false;
	}

	w_ += x_;
	W += X;
	
	if (W <= X) {
		if (w_ >= x_ || W > w_) return false;
	}
	else {
		if (w_ >= x_ && W > w_) return false;
	}
	
	h_ += y_;
	H += Y;
	
	if (H <= Y) {
		if (h_ >= y_ || H > h_) return false;
	}
	else {
		if (h_ >= y && H > h_) return false;
	}
	
	return true;
}

bool Collider2D::inside(int X, int Y) {
	int w_ = this->w;
	int h_ = this->h;
	if ((w_ | h_) < 0) {
		return false;
	}

	int x_ = this->x;
	int y_ = this->y;
	if (X < x_ || Y < y_) {
		return false;
	}
	w_ += x_;
	h_ += y_;

	// overflow || intersect
	return ((w_ < x_ || w_ > X) && (h_ < y_ || h_ > Y));
}

bool Collider2D::intersects(Collider2D c) {
	int tw = this->w;
	int th = this->h;
	int rw = c.getWidth();
	int rh = c.getHeight();
	if (rw <= 0 || rh <= 0 || tw <= 0 || th <= 0) {
		return false;
	}
	int tx = this->x;
	int ty = this->y;
	int rx = c.getX();
	int ry = c.getY();
	rw += rx;
	rh += ry;
	tw += tx;
	th += ty;

	// overflow || intersect
	return ((rw < rx || rw > tx) &&
		(rh < ry || rh > ty) &&
		(tw < tx || tw > rx) &&
		(th < ty || th > ry));
}