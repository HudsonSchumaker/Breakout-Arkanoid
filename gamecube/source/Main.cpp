// 
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
#include "Level1.hpp"
#include "Level2.hpp"
#include "Level3.hpp"

void ini();
void end();

int main(void) {
    ini();
    
    Splash* splash = new Splash();

    Level3* lv1 = new Level3();
    delete splash;

    while(!lv1->loop()) {
        delete lv1;
        lv1 = new Level3();
    }
    delete lv1;
    Level2* lv2 = new Level2();

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
    //GRRLIB_FreeTTF(font);
    GRRLIB_Exit();
}

