//
//  Dimension.h
//  SchumakerTeam Lab.
//
// Hudson Schumaker
//

#pragma once

class Dimension final {
private:
	int w, h;

public:
	Dimension();
	Dimension(int w, int h);

	void setDimension(Dimension d);
	Dimension getSize();

	void setWidth(int w) { this->w = w; };
	int getWidth() const { return w; };

	void setHeight(int h) { this->h = h; };
	int getHeight() const { return h; };
};
