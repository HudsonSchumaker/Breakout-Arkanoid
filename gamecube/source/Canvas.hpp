// 
// Canvas.h
// SchumakerTeam Lab.
// Hudson Schumaker
//

class Canvas {
    private:
        int w, h;

    public:
        Canvas();
        Canvas(int w, int h);

        virtual void ini();
        virtual void render();
        virtual void input(); 
        virtual void loop();

        void setWidth(int w) { this->w = w; };
	    int getWidth() const { return w; };

	    void setHeight(int h) { this->h = h; };
	    int getHeight() const { return h; };
};