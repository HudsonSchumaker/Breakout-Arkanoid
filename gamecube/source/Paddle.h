//
// Paddle.h
// SchumakerTeam Lab.
// Hudson Schumaker
//

#ifndef PADDLE_H
#define PADDLE_H

#include "Sprite.h"

class Paddle : public Sprite {
public:
    Paddle() : Sprite() {};
    Paddle(int x, int y) : Sprite(x, y) {};
    Paddle(int x, int y, int w, int h) : Sprite(x, y, w, h) {};
    void move(int dx);
    void draw() override;
    void draw(float d);
    
private:
  
};
#endif /* PADDLE_H */