//
// Win
// Color.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "WColor.hpp"

WColor::WColor() : r(255), g(255), b(255), a(255) {}
WColor::WColor(int r, int g, int b, int a) : r(r), g(g), b(b), a(a) {}

Color WColor::getRed() {
    return Color { 255, 0, 0, 255 };
}

Color WColor::getGreen() {
    return Color { 0, 255, 0, 255 };
}

Color WColor::getBlue() {
    return Color { 0, 0, 255, 255 };
}

Color WColor::getWhite() {
    return Color { 255, 255, 255, 255 };
}

Color WColor::getBlack() {
    return Color { 0, 0, 0, 255 };
}

Color WColor::getGray() {
    return Color { 128, 128, 128, 255 };
}

Color WColor::getOrange() {
    return Color { 255, 88, 0, 255 };
}

Color WColor::getYellow() {
    return Color { 255, 255, 0, 255 };
}

Color WColor::getPink() {
    return Color { 255, 175, 175, 255 };
}
