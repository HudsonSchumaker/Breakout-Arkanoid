//
//  Point.h
//  SchumakerTam Lab.
//
//  Hudson Schumaker
//

#ifndef POINT_H
#define POINT_H

#include <string>
#include <iostream>

using namespace std;

class Point {
private:
    int x;
    int y;
    
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
    
    string toString() { return "Point[" + to_string(x) + ", " + to_string(y) + "]"; };
};
#endif /* POINT_H */
