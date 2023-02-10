//
// Switch
// Level1.hpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#pragma once

#include <SDL_image.h>
#include "Canvas.hpp"
#include "Brick.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"

class Level1 final : public Canvas {
    public:
        const static int NUMBER_BRICK = 24;
        

        Level1() : Canvas() {};
        Level1(SDL_Renderer* renderer);
        ~Level1();

        bool loop() override;
        void input(SDL_Event& e) override; 
        void move() override;
        void collision() override;
        void render() override;
        void load() override;
        void unload() override;

    private:
        bool levelOver = false;
        bool levelWon = false;

        Paddle paddle;
        Brick bricks[NUMBER_BRICK];    
        Ball ball;

        SDL_Renderer* renderer;

        SDL_Surface* paddle_surf;
        SDL_Surface* brick_surf;
        SDL_Surface* ball_surf;
        SDL_Surface* background_surf;

        SDL_Texture* paddleSprite;
        SDL_Texture* brickSprite;      //= SDL_CreateTextureFromSurface(renderer, lavaSprite_surf);
        SDL_Texture* ballSprite;       //= SDL_CreateTextureFromSurface(renderer, platformSprite_surf);
        SDL_Texture* backgroundSprite; //= SDL_CreateTextureFromSurface(renderer, coinSprite_surf);
};