//
// MacOS
// Rectangle.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "WRectangle.hpp"

WRectangle::WRectangle() 
	: x(0), y(0), w(0), h(0) {}

WRectangle::WRectangle(int w, int h) 
	: x(0), y(0), w(w), h(h) {}

WRectangle::WRectangle(int x, int y, int w, int h) 
	: x(x), y(y), w(w), h(h) {}

WRectangle::WRectangle(Point p)
	: x(p.getX()), y(p.getY()), w(0), h(0) {}

WRectangle::WRectangle(Dimension d) 
	: x(0), y(0), w(d.getWidth()), h(d.getHeight()) {}

WRectangle::WRectangle(Point p, Dimension d) 
	: x(p.getX()), y(p.getY()), w(d.getWidth()), h(d.getHeight()) {}

WRectangle WRectangle::getBounds() {
	return WRectangle(this->x, this->y, this->w, this->h);
}

Point WRectangle::getLocation() {
	return Point(this->x, this->y);
}

Dimension WRectangle::getSize() {
	return Dimension(this->w, this->h);
}

bool WRectangle::contains(Point p) {
	return contains(p.getX(), p.getY());
}

bool WRectangle::contains(WRectangle r) {
	return contains(r.getX(), r.getY(), r.getWidth(), r.getHeight());
}

bool WRectangle::contains(int x, int y) {
	return inside(x, y);
}

bool WRectangle::contains(int X, int Y, int W, int H) {
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

bool WRectangle::inside(int X, int Y) {
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

bool WRectangle::intersects(WRectangle r) {
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