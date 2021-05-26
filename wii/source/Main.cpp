// 
// Wii
// Main.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include <fat.h>
#include <gccore.h>
#include <grrlib.h>
#include <asndlib.h>
#include <mp3player.h>
#include "Splash.hpp"
#include "Menu.hpp"

void ini();
void end();

int main(void) {
    ini();
    
    Splash splash = Splash();
    Menu menu = Menu();
    
    end();
    return 0;
}

void ini() {
    ASND_Init();
    MP3Player_Init();
    PAD_Init();
    GRRLIB_Init();
}

void end() {
    GRRLIB_Exit();
}

