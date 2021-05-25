//
// NGC
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
        static Vector4 getRed();
        static Vector4 getGreen();
        static Vector4 getBlue();
        static Vector4 getWhite();
        static Color getBlack();
        static Color getGray();
        static Color getOrange();
        static Vector4 getYellow();
        static Vector4 getPink();
};