//
// Brick.hpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#pragma once
#include "Sprite.hpp"

class Brick final: public Sprite {
private:
    bool destroyed;

public:
    Brick() : Sprite(0, 0), destroyed(false) {};
    Brick(int x, int y) : Sprite(x, y), destroyed(false) {};
    Brick(int x, int y, int w, int h) : Sprite(x, y, w, h), destroyed(false) {};
    Brick(int x, int y, int w, int h, bool d) : Sprite(x, y, w, h), destroyed(d) {};
    
    void draw() override;
    void draw(float d);

    bool isDestroyed() const { return destroyed; };
    void setDestroyed(bool d) { this->destroyed = d; };
};