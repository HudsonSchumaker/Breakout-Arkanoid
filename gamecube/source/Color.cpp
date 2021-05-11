//
// Color.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Color.h"

Color::Color() : r(255), g(255), b(255), a(255) {}
Color::Color(int r, int g, int b, int a) : r(r), g(g), b(b), a(a) {}

unsigned long Color::createRGBA(int r, int g, int b, int a) {   
    return ((r & 0xff) << 24) 
        + ((g & 0xff) << 16) 
        + ((b & 0xff) << 8)
        + (a & 0xff);
}

unsigned long Color::getHex() {
    return createRGBA(this->r, this->g, this->b, this->a);
}

unsigned long Color::getRed() {
    return createRGBA(255, 0, 0, 255);
}

unsigned long Color::getGreen() {
    return createRGBA(0, 255, 0, 255);
}

unsigned long Color::getBlue() {
    return createRGBA(0, 0, 255, 255);
}

unsigned long Color::getWhite() {
    return createRGBA(255, 255, 255, 255);
}

unsigned long Color::getBlack() {
    return createRGBA(0, 0, 0, 255);
}

unsigned long Color::getGray() {
    return createRGBA(128, 128, 128, 255);
}

unsigned long Color::getOrange() {
    return createRGBA(255, 200, 0, 255);
}

unsigned long Color::getYellow() {
    return createRGBA(255, 255, 0, 255);
}

unsigned long Color::getPink() {
    return createRGBA(255, 175, 175, 255);
}