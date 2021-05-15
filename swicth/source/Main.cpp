// 
// Main.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//
 
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <switch.h>

#include "Brick.hpp"
#include "Paddle.hpp"
#include "Ball.hpp"
#include "Color.hpp"
#include "Point.hpp"

// some switch buttons
#define JOY_A     0
#define JOY_B     1
#define JOY_X     2
#define JOY_Y     3
#define JOY_PLUS  10
#define JOY_MINUS 11
#define JOY_LEFT  12
#define JOY_UP    13
#define JOY_RIGHT 14
#define JOY_DOWN  15

const int screenWidth = 800;
const int screenHeight = 450;

void ini();
void input(SDL_Event& e);
void collision();
void render();
void end();

SDL_Surface* paddle_surf;
SDL_Surface* brick_surf;
SDL_Surface* ball_surf;
SDL_Surface* background_surf;

SDL_Texture* paddleSprite;
SDL_Texture* brickSprite; //= SDL_CreateTextureFromSurface(renderer, lavaSprite_surf);
SDL_Texture* ballSprite; //= SDL_CreateTextureFromSurface(renderer, platformSprite_surf);
SDL_Texture* backgroundSprite; // = SDL_CreateTextureFromSurface(renderer, coinSprite_surf);

Paddle paddle(192, 432);
Brick bricks [24];    
Ball ball(200, 425);

SDL_Renderer* renderer;

int main(void) {
    ini();
    
    ball.setS(1);
    
    paddle_surf = IMG_Load("resources/paddle.png");
    brick_surf = IMG_Load("resources/brick.png");
    ball_surf = IMG_Load("resources/ball.png");
    background_surf = IMG_Load("resources/backgrund.png");

    paddleSprite = SDL_CreateTextureFromSurface(renderer, paddle_surf);
    brickSprite = SDL_CreateTextureFromSurface(renderer, brick_surf);
    ballSprite = SDL_CreateTextureFromSurface(renderer, ball_surf);
    backgroundSprite = SDL_CreateTextureFromSurface(renderer, background_surf);

    paddle.setTexture(paddleSprite);
    ball.setTexture(ballSprite);

    int b = 0;
    SDL_Point size;
    SDL_QueryTexture(brickSprite, NULL, NULL, &size.x, &size.y);
    for (int l = 0; l < 2; l++) {
        for (int c = 0; c < 12; c++) {
            bricks[b] = Brick(c * size.x + 128, l * size.y + 64);
            bricks[b].setTexture(brickSprite);
            b++;
        }
    }

    for (;;) {
        SDL_Event e;
        input(e);
        ball.move();
        collision();
        render(); 
    }

    end();
    return 0;
}

void input(SDL_Event& e) {
    int dx = 0;
    while(SDL_PollEvent(&e)) {
        switch(e.type) {
            case SDL_QUIT: {
                bool quit = true;
            } break;
            case SDL_JOYAXISMOTION: {
                dx = e.jaxis.value;
            } break;
        }
    }

    if (dx > 0) {
        paddle.move(4);
        return;
    } 
    if (dx < 0) {
        paddle.move(-4);
        return;
    }
}

void collision() {
    if (ball.getBounds().getY() > screenHeight) {
        exit(1);
    }

    for (unsigned int i = 0, j = 0; i < sizeof bricks; i++) {
        if (bricks[i].isDestroyed()) {
            j++;
        }
        if (j == 16) {
            //message = "Victory";
            //GRRLIB_PrintfTTF(screenWidth/2 - 146, screenHeight/2, font,"Victory", 64, Color::getBlack());
            
            // exit(0);
        }
    }

    if ((ball.getBounds()).intersects(paddle.getBounds())) {
        int paddleLPos = paddle.getBounds().getX();
        int ballLPos = ball.getBounds().getX();
        int first  = paddleLPos + 8;
        int second = paddleLPos + 16;
        int third  = paddleLPos + 24;
        int fourth = paddleLPos + 32;

        if (ballLPos < first) {
            ball.setDX(-1);
            ball.setDY(-1);
        }
        if (ballLPos >= first && ballLPos < second) {
            ball.setDX(-1);
            ball.setDY(-1 * ball.getDY());
        }
        if (ballLPos >= second && ballLPos < third) {
            ball.setDX(0);
            ball.setDY(-1);
        }
        if (ballLPos >= third && ballLPos < fourth) {
            ball.setDX(1);
            ball.setDY(-1 * ball.getDY());
        }
        if (ballLPos > fourth) {
            ball.setDX(1);
            ball.setDY(-1);
        }
    }

    for (unsigned int i = 0; i < sizeof bricks; i++) {
        if ((ball.getBounds()).intersects(bricks[i].getBounds())) {

            if(bricks[i].isDestroyed()) {
                return;
            }

            bricks[i].setDestroyed(true);
            
            int ballLeft   = ball.getBounds().getX();
            int ballHeight = ball.getBounds().getHeight();
            int ballWidth  = ball.getBounds().getWidth();
            int ballTop    = ball.getBounds().getY();

            Point pointRight(ballLeft + ballWidth + 1, ballTop);
            Point pointLeft(ballLeft - 1, ballTop);
            Point pointTop(ballLeft, ballTop - 1);
            Point pointBottom(ballLeft, ballTop + ballHeight + 1);

            if (bricks[i].getBounds().contains(pointRight)) {
                ball.setDX(-1);
            }
            else if (bricks[i].getBounds().contains(pointLeft)) {
                ball.setDX(1);
            }
            if (bricks[i].getBounds().contains(pointTop)) {
                ball.setDY(1);
            }
            else if (bricks[i].getBounds().contains(pointBottom)) {
                ball.setDY(-1);
            }


            
            //PlayOgg(beep_ogg, beep_ogg_size, 0, OGG_ONE_TIME);
        }
    }
}

void render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    for (unsigned int i = 0; i < sizeof bricks; i++) {
        if (!bricks[i].isDestroyed()) {
            bricks[i].draw(renderer, 45.0);
        }
    }
    paddle.draw(renderer);
    ball.draw(renderer);
    //SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);     
}

void ini() {
    romfsInit();
    chdir("romfs:/");

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    
    SDL_Window *window = SDL_CreateWindow(
        "Breakanoide",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        screenWidth, screenHeight,
        SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
    );
    
    renderer = SDL_CreateRenderer(window, -1, 0);
    
    Mix_AllocateChannels(5);
    Mix_OpenAudio(48000, AUDIO_S16, 2, 4096);
    
    SDL_InitSubSystem(SDL_INIT_JOYSTICK);
    SDL_JoystickEventState(SDL_ENABLE);
    SDL_JoystickOpen(0);
}

void end() {
    Mix_CloseAudio();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();      
    romfsExit();
}
