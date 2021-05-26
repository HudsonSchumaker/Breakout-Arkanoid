//
// NGC
// Menu.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include <ctime>
#include "Menu.hpp"
#include "Color.hpp"
#include "Canvas.hpp"
#include "font_ttf.h"

Menu::Menu() {
    start = false;
    load();
    loop();
}

Menu::~Menu() {
    exit();
}

void Menu::load() {
    font = GRRLIB_LoadTTF(font_ttf, font_ttf_size);
}

void Menu::input() {
    PAD_ScanPads();
    int buttonsDown = PAD_ButtonsDown(0);
		
	if(buttonsDown & PAD_BUTTON_A) {
		start = true;
	}
}

void Menu::loop() {
    while (!start) {
        input();
       
        GRRLIB_FillScreen(Color::getBlack()); 
        GRRLIB_PrintfTTF(Canvas::screenWidth/2 - 150, Canvas::screenHeight/2 - 158, font, "Breakanoid", 72, Color::getOrange());
        
        time_t currentTime;
	    time(&currentTime);
        if (currentTime % 2 == 0) {
            GRRLIB_PrintfTTF(Canvas::screenWidth/2 - 66, Canvas::screenHeight/2 + 64, font, "- Press A to start -", 16, Color::getGray());
        }
        
        GRRLIB_Render();
    }
    exit();
}

void Menu::exit() {
    GRRLIB_FreeTTF(font);
}
