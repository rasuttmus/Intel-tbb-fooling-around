#ifndef CAMERA_H
#define CAMERA_H

#include "Pixel.h"

class Camera {

public:
    
    Camera(unsigned int, unsigned int);
    
    ~Camera();

    void createPixels();

    void debugPixelPositions();

private:
    
    unsigned int mResolutionX;
    
    unsigned int mResolutionY;

    float mImagePlaneSize;

    tbb::concurrent_vector<Pixel *>mPixels;
};

#endif // CAMERA_H