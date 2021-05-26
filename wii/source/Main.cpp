// 
// Wii
// Main.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include <gccore.h>
#include <asndlib.h>
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
    PAD_Init();
    GRRLIB_Init();
}

void end() {
    GRRLIB_Exit();
}

