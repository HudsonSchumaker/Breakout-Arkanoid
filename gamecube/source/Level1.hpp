//
// Level1.hpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#pragma once
#include "Canvas.hpp"

class Level1 final : public Canvas {
public:
    Level1();
    ~Level1();

    void loop() override;
    void input() override; 
    void move() override;
    void collision() override;
    void render() override;
    void load() override;
    void unload() override;
};