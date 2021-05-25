//
// Win
// Menu.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include <stdio.h>
#include "Canvas.hpp"
#include "Menu.hpp"
#include "WColor.hpp"

Menu::Menu() {
    start = false;
    load();
    loop();
}

Menu::~Menu() {
    exit();
}

void Menu::load() {
    font = LoadFontEx("resources/font.otf", 64, 0, NULL);
}

void Menu::input() {
    if (IsGamepadAvailable(0)) {
        if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)) {
            start = true;
        }
    }
}

void Menu::loop() {
    while (!start) {
        input();

        BeginDrawing();
            ClearBackground(WColor::getBlack());
            DrawTextEx(font, "Breakanoid", Vector2{Canvas::screenWidth/2 - 150, Canvas::screenHeight/2 - 158}, 72, 0, WColor::getOrange()); 
            DrawTextEx(font, "- Press A to start -", Vector2{Canvas::screenWidth/2 - 64, Canvas::screenHeight/2 + 64}, 16, 0, WColor::getGray());
        EndDrawing();
    }
    exit();
}

void Menu::exit() {
    UnloadFont(font);
}
