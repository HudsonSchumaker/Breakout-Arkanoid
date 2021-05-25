//
// Win
// Menu.hpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#pragma once
#include "raylib.h"

class Menu final {
    public: 
        Font font;
        
        Menu();
        ~Menu();

    private:
        bool start;
        void load();
        void input();
        void loop();
        void exit();
};