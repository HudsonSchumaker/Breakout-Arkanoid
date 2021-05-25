//
// Win
// Color.hpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#pragma once
#include "raylib.h"

class WColor final {
    public:
        int r, g, b, a;
        WColor();
        WColor(int r, int g, int b, int a);
        static Color getRed();
        static Color getGreen();
        static Color getBlue();
        static Color getWhite();
        static Color getBlack();
        static Color getGray();
        static Color getOrange();
        static Color getYellow();
        static Color getPink();
};