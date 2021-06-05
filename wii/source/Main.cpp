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
#include "Level1.hpp"

void ini();
void end();

int main(void) {
    ini();
    
    Splash splash = Splash();
    Menu menu = Menu();

    Level1* lv1 = new Level1();
    while(!lv1->loop()) {
        delete lv1;
        lv1 = new Level1();
    }
    delete lv1;
    rw.save(1);
    
    Level2* lv2 = new Level2();
    while(!lv2->loop()) {
        delete lv2;
        lv2 = new Level2();
    }
    delete lv2;
    rw.save(2);

    Level3* lv3 = new Level3();
    while(!lv3->loop()) {
        delete lv3;
        lv3 = new Level3();
    }
    delete lv3;
    rw.save(3);

    Level4* lv4 = new Level4();
    while(!lv4->loop()) {
        delete lv4;
        lv4 = new Level4();
    }
    delete lv4;
    
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

