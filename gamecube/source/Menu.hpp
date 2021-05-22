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
        GRRLIB_ttfFont *font;
        
        Menu();
        ~Menu();

    private:
        bool start;
        void load();
        void input();
        void loop();
        void exit();
};