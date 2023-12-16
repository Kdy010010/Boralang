// consoleimg.h

#ifndef CONSOLEIMG_H
#define CONSOLEIMG_H

#include "CImg.h"

using namespace cimg_library;

// Function to display an image in the console
void displayImage(const char* filename) {
    CImg<unsigned char> image(filename);

    // Resize the image to fit within the console width
    int consoleWidth = 80;  // Adjust as needed
    double scale = (double)consoleWidth / image.width();
    image.resize(image.width() * scale, image.height() * scale);

    // Display the image
    CImgDisplay display(image, "Console Image Display");
    while (!display.is_closed()) {
        display.wait();
    }
}

#endif // CONSOLEIMG_H
