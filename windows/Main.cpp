// 
// Win
// Main.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "raylib.h"
#include "Splash.hpp"
#include "Canvas.hpp"
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
    
    end();
    return 0;
}

void ini() {
    Image brick = LoadImage("resources/green_brick.png");
    InitWindow(Canvas::screenWidth, Canvas::screenHeight, "Breakanoid");
    SetWindowIcon(brick);
    InitAudioDevice();
    SetMasterVolume(0.3f);
    SetTargetFPS(60);  
}

void end() {
    CloseAudioDevice();
    CloseWindow();        
}

