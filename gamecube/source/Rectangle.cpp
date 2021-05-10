//
//  Rectangle.cpp
//  SchumakerTeam Lab.
//  Hudson Schumaker
//

#include "Rectangle.hpp"

Rectangle::Rectangle() {
	this->x = 0;
	this->y = 0;
	this->w = 0;
	this->h = 0;
}

Rectangle::Rectangle(int w, int h) {
	this->x = 0;
	this->y = 0;
	this->w = w;
	this->h = h;
}

Rectangle::Rectangle(int x, int y, int w, int h) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

Rectangle::Rectangle(Point p) {
	this->x = p.getX();
	this->y = p.getY();
	this->w = 0;
	this->h = 0;
}

Rectangle::Rectangle(Dimension d) {
	this->x = 0;
	this->y = 0;
	this->w = d.getWidth();
	this->h = d.getHeight();
}

Rectangle::Rectangle(Point p, Dimension d) {
	this->x = p.getX();
	this->y = p.getY();
	this->w = d.getWidth();
	this->h = d.getHeight();
}

Rectangle Rectangle::getBounds() {
	return Rectangle(this->x, this->y, this->w, this->h);
}

Point Rectangle::getLocation() {
	return Point(this->x, this->y);
}

Dimension Rectangle::getSize() {
	return Dimension(this->w, this->h);
}

bool Rectangle::contains(Point p) {
	return contains(p.getX(), p.getY());
}

bool Rectangle::contains(Rectangle r) {
	return contains(r.getX(), r.getY(), r.getWidth(), r.getHeight());
}

bool Rectangle::contains(int x, int y) {
	return inside(x, y);
}

bool Rectangle::contains(int X, int Y, int W, int H) {
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

bool Rectangle::inside(int X, int Y) {
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

bool Rectangle::intersects(Rectangle r) {
	int tw = this->w;
	int th = this->h;
	int rw = r.getWidth();
	int rh = r.getHeight();
	if (rw <= 0 || rh <= 0 || tw <= 0 || th <= 0) {
		return false;
	}
	int tx = this->x;
	int ty = this->y;
	int rx = r.getX();
	int ry = r.getY();
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