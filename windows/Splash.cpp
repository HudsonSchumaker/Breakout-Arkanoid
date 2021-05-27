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
            DrawTexture(logo, 100, 180, WColor::getWhite());         
        EndDrawing();
        splashTimer++;
    }
    exit();
}

void Splash::exit() {
    UnloadTexture(logo);
}
