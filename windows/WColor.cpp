//
// NGC
// Color.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "WColor.hpp"

WColor::WColor() : r(255), g(255), b(255), a(255) {}
WColor::WColor(int r, int g, int b, int a) : r(r), g(g), b(b), a(a) {}

Vector4 WColor::getRed() {
    return Vector4 { 255, 0, 0, 255 };
}

Vector4 WColor::getGreen() {
    return Vector4 { 0, 255, 0, 255 };
}

Vector4 WColor::getBlue() {
    return Vector4 { 0, 0, 255, 255 };
}

Vector4 WColor::getWhite() {
    return Vector4 { 255, 255, 255, 255 };
}

Color WColor::getBlack() {
    return Color { 0, 0, 0, 255 };
}

Color WColor::getGray() {
    return Color { 128, 128, 128, 255 };
}

Color WColor::getOrange() {
    return Color { 255, 200, 0, 255 };
}

Vector4 WColor::getYellow() {
    return Vector4 { 255, 255, 0, 255 };
}

Vector4 WColor::getPink() {
    return Vector4 { 255, 175, 175, 255 };
}