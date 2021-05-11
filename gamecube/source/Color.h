//
// Color.h
// SchumakerTeam Lab.
// Hudson Schumaker
//

#ifndef COLOR_H
#define COLOR_H

class Color final {
public:
    int r, g, b, a;
    Color();
    Color(int r, int g, int b, int a);
    static unsigned long createRGBA(int r, int g, int b, int a);
    unsigned long getHex();
    static unsigned long getRed();
    static unsigned long getGreen();
    static unsigned long getBlue();
    static unsigned long getWhite();
    static unsigned long getBlack();
    static unsigned long getGray();
    static unsigned long getOrange();
    static unsigned long getYellow();
    static unsigned long getPink();

private:

};

#endif /* COLOR_H */