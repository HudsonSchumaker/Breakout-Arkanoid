//
//  Dimension.h
//  hello
//
//  Created by Hudson Luiz Sales Schumaker on 06.05.21.
//

#ifndef DIMENSION_H
#define DIMENSION_H

using namespace std;

class Dimension {
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
#endif /* DIMENSION_H */
