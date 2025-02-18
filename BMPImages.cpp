#include <iostream>
#include <fstream>
#include "BMPImages.h"
#include <vector>
#include <string>

using namespace std;

vector<Pixel> pixels;

void Image::imageProcessing(const char *filename) {
    int size, height, width, pixels_adress, bits_per_pixel;
    // обработка файла с изображением bmp
    ifstream file(filename, ios::in | ios::binary);

    // считываем размер файла
    file.seekg( 2, ios::beg);
    file.read ((char*)&size, sizeof(int));

    // считываем адрес начала массива пикселей
    file.seekg( 10, ios::beg);
    file.read ((char*)&pixels_adress, sizeof(int));

    // считываем ширину и высоту изображения (в пикселях)
    file.seekg( 18, ios::beg);
    file.read ((char*)&width, sizeof(int));
    file.read ((char*)&height, sizeof(int));

    // считываем кол-во битов на пиксель
    file.seekg( 28, ios::beg);
    file.read ((char*)&bits_per_pixel, sizeof(short int));

    this->size = size;
    this->pixelsStartAddress = pixels_adress;
    this->bitsPerPixel = bits_per_pixel;
    this->width = width;
    this->height = height;

    file.seekg(pixelsStartAddress, ios::beg); // сместились к началу битов с изображения
    int shift = 0;
    int is3 = 0;
    Pixel currentPixel;
    while(file.seekg(pixelsStartAddress + shift, ios::beg)) {
        is3++;
        char curBit;
        file.read((char*)&curBit, 1);
        shift++;
        if (is3 == 1) { // r
            currentPixel.setR(curBit);
        }
        if (is3 == 2) { // g
            currentPixel.setG(curBit);
        }
        if (is3 == 3) { // b
            currentPixel.setB(curBit);
            is3 = 0;
            pixels.push_back(currentPixel);
        }
    }
    int i = 1;
    for (auto x : pixels) { // 101 108 102
        cout << i << " ";
        cout << x.getR() << " " << x.getG() << " " << x.getB() << "\n";
        i++;
    }
}

//setters for Pixel
void Pixel::setR(int r) {
    this->r = r;
}

void Pixel::setG(int g) {
    this->g = g;
}

void Pixel::setB(int b) {
    this->b = b;
}

//getters for Pixel
int Pixel::getR() {
    return this->r;
}

int Pixel::getG() {
    return this->g;
}

int Pixel::getB() {
    return this->b;
}

//setters for Image
void Image::setHeight(int height) {
    this->height = height;
}

void Image::setWidth(int width) {
    this->width = width;
}

void Image::setSize(int size) {
    this->size = size;
}

void Image::setBitsPerPixel(int bitsPerPixel) {
    this->bitsPerPixel = bitsPerPixel;
}

void Image::setPixelsStartAddress(int pixelsStartAddress) {
    this->pixelsStartAddress = pixelsStartAddress;
}

//getters for Image
int Image::getPixelsStartAddress() {
    return pixelsStartAddress;
}

int Image::getBitsPerPixel() {
    return bitsPerPixel;
}

int Image::getWidth() {
    return width;
}

int Image::getHeight() {
    return height;
}

int Image::getSize() {
    return size;
}
