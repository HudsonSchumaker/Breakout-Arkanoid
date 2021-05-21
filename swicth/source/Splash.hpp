//
// Switch
// Splash.hpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Splash final {
    public: 
        SDL_Renderer* renderer;
        SDL_Surface* logo_surf;
        SDL_Texture* logo;
        
        Splash(SDL_Renderer* renderer);
        ~Splash();

    private:
        double splashTimer;
        void load();
        void loop();
        void exit();
};