//
// Ball.hpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Sprite.hpp"

class Ball : public Sprite {
public:
    Ball() : Sprite() {};
    Ball(int w, int h) : Sprite(w, h) {};
    Ball(int x, int y, int w, int h) : Sprite(x, y, w, h) {};
    void move();
    void draw();
    void draw(float d);

private:

};