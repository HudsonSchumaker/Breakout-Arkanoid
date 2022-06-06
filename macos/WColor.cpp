//
// MacOS
// Color.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "WColor.hpp"

WColor::WColor() : r(255), g(255), b(255), a(255) {}
WColor::WColor(int r, int g, int b, int a) : r(r), g(g), b(b), a(a) {}

Color WColor::getRed() {
    Color red = { 255, 0, 0, 255 };
    return red;
}

Color WColor::getGreen() {
    Color green =  { 0, 255, 0, 255 };
    return green;
}

Color WColor::getBlue() {
    Color blue = { 0, 0, 255, 255 };
    return blue;
}

Color WColor::getWhite() {
    Color white = { 255, 255, 255, 255 };
    return white; 
}

Color WColor::getBlack() {
    Color black = { 0, 0, 0, 255 };
    return black; 
}

Color WColor::getGray() {
    Color gray = { 128, 128, 128, 255 };
    return gray;
}

Color WColor::getOrange() {
    Color orange = { 255, 88, 0, 255 };
    return orange;
}

Color WColor::getYellow() {
    Color yellow = { 255, 255, 0, 255 };
    return yellow;
}

Color WColor::getPink() {
    Color pink = { 255, 175, 175, 255 };
    return pink;
}
