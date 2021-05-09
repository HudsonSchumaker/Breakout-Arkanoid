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
GRRLIB_texImg *brick;

int main(void)
{
    ini();

    Brick bricks [64];
    font = GRRLIB_LoadTTF(font_ttf, font_ttf_size);
    brick = GRRLIB_LoadTexture(brick_png);
    
    int k = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            bricks[k] = Brick(j * brick->w + 30, i * brick->h + 50);
            bricks[k].setTexture(brick);
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

        for (unsigned int i = 0; i < sizeof bricks; i++) {
            bricks[i].draw();
        }                    

        //GRRLIB_PrintfTTF(screenWidth/2 - 146, screenHeight/2, font, "SchumakerTeam", 64, GRRLIB_WHITE);
        GRRLIB_Render();        
    }

    end();
    return 0;
}

void ini() {
    ASND_Init();
    PAD_Init();
    GRRLIB_Init();
}

void end() {
    GRRLIB_FreeTTF(font);
    GRRLIB_Exit();
  //  
}
