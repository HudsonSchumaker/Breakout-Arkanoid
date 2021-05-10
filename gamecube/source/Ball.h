//
// Ball.h
// SchumakerTeam Lab.
// Hudson Schumaker
//

#ifndef BALL_H
#define BALL_H

#include "Sprite.h"

class Ball : public Sprite {
public:
    Ball() : Sprite() {};
    Ball(int w, int h) : Sprite(w, h) {};
    Ball(int x, int y, int w, int h) : Sprite(x, y, w, h) {};
    void draw();
    void draw(float d);

private:

};
#endif /* BALL_H */