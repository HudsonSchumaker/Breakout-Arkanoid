//
// Win
// Splash.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Splash.hpp"
#include "WColor.hpp"

Splash::Splash() {
    load();
    loop();
}

Splash::~Splash() {
    exit();
}

void Splash::load() {
    logo = LoadTexture("resources/logo.png");
}

void Splash::loop() {
    while (splashTimer < 120) {
        BeginDrawing();
            ClearBackground(WColor::getWhite());
            DrawTexture(logo, Canvas::screenWidth()/2 - logo.width/2, Canvas::screenHeight()/2 - logo.height/2, WColor::getWhite());         
        EndDrawing();
        splashTimer++;
    }
    exit();
}

void Splash::exit() {
    UnloadTexture(logo);
}
