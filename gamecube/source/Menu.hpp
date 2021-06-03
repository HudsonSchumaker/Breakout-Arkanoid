//
// NGC
// Menu.hpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#pragma once
#include <grrlib.h>

class Menu final {
    public: 
        int best = 0;
        GRRLIB_ttfFont *font;
        
        Menu(int level);
        ~Menu();

    private:
        bool start;
        void load();
        void input();
        void loop();
        void exit();
};