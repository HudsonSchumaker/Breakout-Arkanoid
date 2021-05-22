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
#include "Level1.hpp"
#include "Level2.hpp"
#include "Level3.hpp"
#include "Level4.hpp"
#include "Level5.hpp"

void ini();
void end();

int main(void) {
    ini();
    
    Splash* splash = new Splash();

    Menu* menu = new Menu();

    Level1* lv1 = new Level1();
    delete splash;

    while(!lv1->loop()) {
        delete lv1;
        lv1 = new Level1();
    }
    delete lv1;
    
    Level2* lv2 = new Level2();
    while(!lv2->loop()) {
        delete lv2;
        lv2 = new Level2();
    }
    delete lv2;

    Level3* lv3 = new Level3();
    while(!lv3->loop()) {
        delete lv3;
        lv3 = new Level3();
    }
    delete lv3;

    Level4* lv4 = new Level4();
    while(!lv4->loop()) {
        delete lv4;
        lv4 = new Level4();
    }
    delete lv4;

    Level5* lv5 = new Level5();
    while(!lv5->loop()) {
        delete lv5;
        lv5 = new Level5();
    }
    delete lv5;

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

