//
// Paddle.hpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Sprite.hpp"

class Paddle : public Sprite {
public:
    Paddle() : Sprite() {};
    Paddle(int x, int y) : Sprite(x, y) {};
    Paddle(int x, int y, int w, int h) : Sprite(x, y, w, h) {};
    void move(int dx);
    void draw();
    void draw(float d);
    
private:
  
};