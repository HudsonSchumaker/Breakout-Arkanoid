// 
// NGC
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
#include "ReadWrite.hpp"
#include "Level1.hpp"
#include "Level2.hpp"
#include "Level3.hpp"
#include "Level4.hpp"
#include "Level5.hpp"

void ini();
void end();

int main(void) {
    ini();

    int level = 0;

    Splash splash = Splash();
    Menu menu = Menu(level);
    
    Level1* lv1 = new Level1();
    while(!lv1->loop()) {
        lv1 = new Level1();
    }
    delete lv1;
   

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

