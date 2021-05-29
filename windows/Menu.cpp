//
// Win
// Menu.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include "Menu.hpp"
#include "Canvas.hpp"
#include "WColor.hpp"

Menu::Menu() {
    start = false;
    load();
    loop();
}

Menu::~Menu() {
    close();
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
        if (WindowShouldClose()) {
            close();
            exit(0);
        }
        input();

        time_t currentTime;
        time(&currentTime);
        BeginDrawing();
        {
            ClearBackground(WColor::getBlack());
            DrawTextEx(font, "Breakanoid", Vector2{Canvas::screenWidth/2 - 150, Canvas::screenHeight/2 - 158}, 72, 0, WColor::getOrange()); 
            
            if (currentTime % 2 == 0) {
                DrawTextEx(font, "- Press A to start -", Vector2{Canvas::screenWidth/2 - 64, Canvas::screenHeight/2 + 64}, 18, 0, WColor::getGray());
            }
        }    
        EndDrawing();
    }
    close();
}

void Menu::close() {
    UnloadFont(font);
}
