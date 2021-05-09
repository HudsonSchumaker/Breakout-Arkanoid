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
    Brick(int x, int y, int w, int h) : Sprite(x, y, w, h) {};
    void draw();
    GRRLIB_texImg *sprite;
    
private:
    
};
#endif /* BRICK_H */