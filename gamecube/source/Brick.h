//
// Brick.h
// SchumakerTeam Lab.
// Hudson Schumaker
//

#ifndef BRICK_H
#define BRICK_H

#include "Sprite.h"

class Brick : public Sprite {
public:
    Brick() : Sprite() {};
    Brick(int x, int y) : Sprite(x, y) {};
    Brick(int x, int y, int w, int h) : Sprite(x, y, w, h) {};
    void draw();
    void draw(float d);
private:
    
};
#endif /* BRICK_H */