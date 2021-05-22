//
// NGC
// Splash.hpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#pragma once
#include <grrlib.h>

class Splash final {
    public: 
        GRRLIB_texImg* logo;
        
        Splash();
        ~Splash();

    private:
        double splashTimer;
        void load();
        void loop();
        void exit();
};