//
// Switch
// Level1.cpp 
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Level1.hpp"
#include "Color.hpp"
#include "Point.hpp"

Level1::Level1(SDL_Renderer* renderer) {
    this->renderer = renderer;
    load();
}

Level1::~Level1() {
    unload();
}

bool Level1::loop() {
    while(!levelOver && !levelWon) {
        input(); 
        move();
        collision();
        render(); 
    }
    return levelWon;
}

void Level1::input() {
    
}

void Level1::move() {
    ball.move();
}

void Level1::collision() {
    
    if (ball.getBounds().getY() > screenHeight) {
        levelOver = true;
    }

    for (int i = 0, j = 0; i < NUMBER_BRICK; i++) {
        if (bricks[i].isDestroyed()) {
            j++;
        }
        if (j > 23) {
            levelWon = true;
        }
    }   

    for (int i = 0; i < NUMBER_BRICK; i++) {
        if ((ball.getBounds()).intersects(bricks[i].getBounds())) {
            if(bricks[i].isDestroyed()) {
                return;
            }

            bricks[i].setDestroyed(true);
            MP3Player_PlayBuffer(beep_mp3, beep_mp3_size, NULL);

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
}

void Level1::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (int i = 0; i < NUMBER_BRICK; i++) {
        if (!bricks[i].isDestroyed()) {
            bricks[i].draw();
          
        }
    }

    paddle.draw();
    ball.draw();
}

void Level1::load() {
    paddle_surf = IMG_Load("resources/paddle.png");
    brick_surf = IMG_Load("resources/brick.png");
    ball_surf = IMG_Load("resources/ball.png");
    background_surf = IMG_Load("resources/backgrund.png");

    paddleSprite = SDL_CreateTextureFromSurface(renderer, paddle_surf);
    brickSprite = SDL_CreateTextureFromSurface(renderer, brick_surf);
    ballSprite = SDL_CreateTextureFromSurface(renderer, ball_surf);
    backgroundSprite = SDL_CreateTextureFromSurface(renderer, background_surf);

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

    paddle = Paddle(192, 462);
    paddle.setTexture(paddleSprite);

    ball = Ball(200, 440);
    ball.setS(4);
    ball.setTexture(ballSprite);
}

void Level1::unload() {
    SDL_DestroyTexture(paddle_surf);
    SDL_DestroyTexture(brick_surf);
    SDL_DestroyTexture(ball_surf);
    SDL_DestroyTexture(background_surf);
    
    SDL_FreeSurface(paddleSprite);
    SDL_FreeSurface(brickSprite);
    SDL_FreeSurface(ballSprite);
    SDL_FreeSurface(backgroundSprite);
}