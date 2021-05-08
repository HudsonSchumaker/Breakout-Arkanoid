// 
// Main.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include <gccore.h>
#include <fat.h>
#include <grrlib.h>
#include <asndlib.h>

#include "font_ttf.h"

#define GRRLIB_BLACK 0x000000FF
#define GRRLIB_WHITE 0xFFFFFFFF

const int screenWidth = 640;
const int screenHeight = 480;

int main(void)
{
    ASND_Init();
    PAD_Init();
    GRRLIB_Init();

    GRRLIB_ttfFont *font = GRRLIB_LoadTTF(font_ttf, font_ttf_size);
       
    for (;;)   
    {
        GRRLIB_FillScreen(GRRLIB_BLACK); 
        PAD_ScanPads();
        
        if(PAD_ButtonsDown(0) & PAD_BUTTON_START)
        {
            break;
        }                    

        GRRLIB_PrintfTTF(screenWidth/2 - 146, screenHeight/2, font, "SchumakerTeam", 64, GRRLIB_WHITE);
        GRRLIB_Render();        
    }

    GRRLIB_FreeTTF(font);
    GRRLIB_Exit();
    return 0;
}

