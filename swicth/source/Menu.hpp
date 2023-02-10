//
// Switch
// Menu.hpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#pragma once
#include <SDL.h>
#include <SDL_ttf.h>

class Menu final {
    public: 
        
        Menu();
        ~Menu();

    private:
        bool start;
        void load();
        void input();
        void loop();
        void draw(SDL_Renderer* renderer);
        void exit();
};