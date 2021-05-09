#ifndef CANVAS_H
#define CANVAS_H
class Canvas
{
    private:
        int w, h;

    public:
        Canvas();
        Canvas(int w, int h);
        void setWidth(int w) { this->w = w; };
	    int getWidth() const { return w; };

	    void setHeight(int h) { this->h = h; };
	    int getHeight() const { return h; };
};
#endif /* CANVAS_H */