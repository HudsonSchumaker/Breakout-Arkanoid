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

#include "Level1.hpp"

void ini();
void end();

int main(void) {
    ini();
    
    Level1* lv1 = new Level1();

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

