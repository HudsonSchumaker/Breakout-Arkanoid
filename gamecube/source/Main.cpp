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

    font = GRRLIB_LoadTTF(font_ttf, font_ttf_size);
    Brick brick(0, 0, 64, 16); 
    brick.sprite = GRRLIB_LoadTexture(brick_png);

    for (;;)   
    {
        GRRLIB_FillScreen(GRRLIB_BLACK); 
        PAD_ScanPads();
        
        if(PAD_ButtonsDown(0) & PAD_BUTTON_START)
        {
            break;
        }                    

        brick.draw();
        GRRLIB_PrintfTTF(screenWidth/2 - 146, screenHeight/2, font, "SchumakerTeam", 64, GRRLIB_WHITE);
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
