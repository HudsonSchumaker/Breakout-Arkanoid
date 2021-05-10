//
// Brick.hpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Sprite.hpp"

class Brick : public Sprite {
public:
    Brick() : Sprite() {};
    Brick(int x, int y) : Sprite(x, y) {};
    Brick(int x, int y, int w, int h) : Sprite(x, y, w, h) {};
    void draw();
    void draw(float d);
private:
    
};