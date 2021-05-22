//
// NGC
// Menu.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Menu.hpp"
#include "Color.hpp"
#include "title_png.h"

Menu::Menu() {
    start = false;
    load();
    loop();
}

Menu::~Menu() {
    exit();
}

void Menu::load() {
    logo = GRRLIB_LoadTexture(title_png);
}

void Menu::input() {
    PAD_ScanPads();
    int buttonsDown = PAD_ButtonsDown(0);
		
	if(buttonsDown & PAD_BUTTON_A ) {
		start = true;
	}
}

void Menu::loop() {
    while (!start) {
        input();

        GRRLIB_FillScreen(Color::getBlack()); 
        GRRLIB_DrawImg(100, 180, logo, 0, 1, 1, Color::getWhite());
        GRRLIB_Render();
    }
    exit();
}

void Menu::exit() {
    GRRLIB_FreeTexture(logo);
}
