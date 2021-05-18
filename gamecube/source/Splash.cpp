//
// Splash.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Splash.hpp"
#include "Color.hpp"
#include "logo_png.h"

Splash::Splash() {
    load();
    loop();
}

Splash::~Splash() {
    exit();
}

void Splash::load() {
    logo = GRRLIB_LoadTexture(logo_png);
}

void Splash::loop() {
    while (splashTimer < 120) {
        GRRLIB_FillScreen(Color::getWhite()); 
        GRRLIB_DrawImg(100, 180, logo, 0, 1, 1, Color::getWhite());
        GRRLIB_Render();
        splashTimer++;
    }
    exit();
}

void Splash::exit() {
    GRRLIB_FreeTexture(logo);
}
