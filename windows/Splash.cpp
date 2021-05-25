//
// Win
// Splash.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Splash.hpp"

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
            ClearBackground(ColorFromNormalized((Vector4){1.0, 1.0, 1.0, 1.0}));
            DrawTexture(logo, 100, 180, WHITE);         
        EndDrawing();

        splashTimer++;
    }
    exit();
}

void Splash::exit() {
    UnloadTexture(logo);
}
