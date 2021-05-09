// 
// Main.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include <gccore.h>
#include <fat.h>
#include <grrlib.h>
#include <asndlib.h>

#include "Brick.h"
#include "Sprite.h"
#include "font_ttf.h"
#include "brick_png.h"

#define GRRLIB_BLACK 0x000000FF
#define GRRLIB_WHITE 0xFFFFFFFF

const int screenWidth = 640;
const int screenHeight = 480;
void ini();
void end();

GRRLIB_ttfFont *font;
int main(void)
{
    ini();

    Brick bricks [30];
    font = GRRLIB_LoadTTF(font_ttf, font_ttf_size);
    
    int k = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            bricks[k] = Brick(j * 64 + 30, i * 15 + 50);
            bricks[k].setTexture(GRRLIB_LoadTexture(brick_png));
            k++;
        }
    }

    for (;;) {
        GRRLIB_FillScreen(GRRLIB_BLACK); 
        PAD_ScanPads();
        
        if(PAD_ButtonsDown(0) & PAD_BUTTON_START)
        {
            break;
        }

        for (int i = 0; i < 30; i++) {
            bricks[i].draw();
        }                    

        //GRRLIB_PrintfTTF(screenWidth/2 - 146, screenHeight/2, font, "SchumakerTeam", 64, GRRLIB_WHITE);
        GRRLIB_Render();        
    }

    end();
}

void ini() {
    ASND_Init();
    PAD_Init();
    GRRLIB_Init();
}

void end() {
    GRRLIB_FreeTTF(font);
    GRRLIB_Exit();
  //  return 0;
}
