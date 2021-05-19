// 
// NGC
// Canvas.hpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#pragma once

class Canvas {
    private:
        int w, h;

    public:
        const int screenWidth = 640;
        const int screenHeight = 480;
        
        Canvas();
        Canvas(int w, int h);

        virtual bool loop() = 0;
        virtual void input() = 0; 
        virtual void move() = 0;
        virtual void collision() = 0;
        virtual void render() = 0;
        virtual void load() = 0;
        virtual void unload() = 0;
        
        void setWidth(int w) { this->w = w; };
	    int getWidth() const { return w; };

	    void setHeight(int h) { this->h = h; };
	    int getHeight() const { return h; };
};