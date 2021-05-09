//
// Brick.h
// SchumakerTeam Lab.
// Hudson Schumaker
//

#ifndef BRICK_H
#define BRICK_H

#include <grrlib.h>
#include "Sprite.h"

class Brick : public Sprite {
public:
    Brick() : Sprite() {};
    Brick(int w, int h) : Sprite(w, h) {};
    Brick(int x, int y, int w, int h) : Sprite(x, y, w, h) {};
    void draw();
private:
    
};
#endif /* BRICK_H */