// 
// Canvas.hpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#pragma once

class Canvas {
    private:
        int w, h;

    public:
        Canvas();
        Canvas(int w, int h);

        virtual void loop() = 0;
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