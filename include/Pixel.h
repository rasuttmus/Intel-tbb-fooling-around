#ifndef PIXEL_H
#define PIXEL_H

#include <stdlib.h>
#include <iostream>
#include <vector>

#include "tbb/tbb.h"
#include "glm/glm.hpp"

class Pixel {

public:

    Pixel(float, float);
    
    ~Pixel() { }

    void debugPixelPosition() { std::cout << "image pos: (" << mPixelPositionX << ", " << mPixelPositionY << ")\n"; }

private:

    float mPixelPositionX;
    
    float mPixelPositionY;
};

#endif // PIXEL_H