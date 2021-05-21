//
// Switch
// Splash.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Splash.hpp"

Splash::Splash(SDL_Renderer* renderer) {
    this->renderer = renderer;
    load();
    loop();
}

Splash::~Splash() {
    exit();
}

void Splash::load() {
    logo_surf = IMG_Load("resources/logo.png");
    logo = SDL_CreateTextureFromSurface(renderer, logo_surf);
}

void Splash::loop() {
    while (splashTimer < 600) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_Point size;
        SDL_QueryTexture(logo, NULL, NULL, &size.x, &size.y);
        SDL_Rect rect = { 100, 180, 100, 100 };
        SDL_RenderCopy(renderer, logo, NULL, &rect);

        SDL_RenderPresent(renderer);   
        splashTimer++;
    }
    exit();
}

void Splash::exit() {
    SDL_DestroyTexture(logo);
    SDL_FreeSurface(logo_surf);
}