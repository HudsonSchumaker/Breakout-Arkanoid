//
// NGC
// Splash.hpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#pragma once
#include "raylib.h"

class Splash final {
    public: 
        Texture2D logo;
        
        Splash();
        ~Splash();

    private:
        double splashTimer;
        void load();
        void loop();
        void exit();
};