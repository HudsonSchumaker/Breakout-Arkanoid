// 
// NGC
// Main.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "raylib.h"
#include "Splash.hpp"
#include "Canvas.hpp"


void ini();
void end();

int main(void) {
    ini();
    
    Splash splash = Splash();
    
    end();
    return 0;
}

void ini() {
    Image brick = LoadImage("resources/green_brick.png");
    InitWindow(Canvas::screenWidth, Canvas::screenHeight, "Breakanoid");
    SetWindowIcon(brick);
    InitAudioDevice();
    SetMasterVolume(0.3f);
}

void end() {
    CloseAudioDevice();
    CloseWindow();        
}

