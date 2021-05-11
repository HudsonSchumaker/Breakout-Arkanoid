//
//  Point.h
//  SchumakerTam Lab.
//
//  Hudson Schumaker
//

#ifndef POINT_H
#define POINT_H

class Point final {
private:
    int x, y;
    
public:
    Point();
    Point(int x, int y);
    
    void move(int x, int y);
	void translate(int d);
    void translate(int dx, int dy);
    
    void setX(int x) { this->x = x; };
    int getX() const { return x; };
    
    void setY(int y) { this->y = y; };
    int getY() const { return y; };
};
#endif /* POINT_H */
