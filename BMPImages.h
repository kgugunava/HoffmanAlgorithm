// for 24-bits images only

#ifndef BMPIMAGES_H
#define BMPIMAGES_H
#include <cstdint>
#include <string>

class Image {
public:
    void imageProcessing(const char* filename);
    Image() {
        size = 0;
        bitsPerPixel = 0;
        pixelsStartAddress = 0;
        width = 0;
        height = 0;
    }
    // setters
    void setSize(int size);
    void setBitsPerPixel(int bitsPerPixel);
    void setPixelsStartAddress(int pixelsStartAdress);
    void setWidth(int width);
    void setHeight(int height);

    // getters
    int getSize();
    int getBitsPerPixel();
    int getPixelsStartAddress();
    int getWidth();
    int getHeight();
private:
    int size;
    int bitsPerPixel;
    int pixelsStartAddress;
    int width;
    int height;
};

class Pixel { // RGB
public:
    // setters
    void setR(int  r);
    void setG(int g);
    void setB(int b);

    //getters
    int getR();
    int getG();
    int getB();
private:
    int r;
    int g;
    int b;
};

#endif //BMPIMAGES_H
