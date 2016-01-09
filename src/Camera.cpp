#include "../include/Camera.h"

Camera::Camera(unsigned int xRes, unsigned int yRes)
    : mResolutionX(xRes), mResolutionY(yRes) { 

    mImagePlaneSize = 1.0f;

    createPixels();
}


Camera::~Camera() {

    for(unsigned int i = 0; i < mPixels.size(); i++)
        delete mPixels[i];

    // Clear and destroy vector
    mPixels.~concurrent_vector();

    std::cout << "\nCamera deleted!\n";
}


void Camera::createPixels() {

    float pixelSize = mImagePlaneSize / static_cast<float>(mResolutionX);

    std::cout << "i start: " << -static_cast<float>(mResolutionY)/2.0f <<std::endl;
    std::cout << "j start: " << -static_cast<float>(mResolutionX)/2.0f <<std::endl;

    float i = -(static_cast<float>(mResolutionY) / (2.0f * static_cast<float>(mResolutionX))) + (pixelSize/ 2.0f);
    float iMax = static_cast<float>(mResolutionY) / (2.0f * static_cast<float>(mResolutionX));

    for ( ; i < iMax; i+=pixelSize) {
        for (float j = -(mImagePlaneSize/2.0f) + (pixelSize / 2.0f) ; j < mImagePlaneSize/2.0f; j+=pixelSize) {
            mPixels.push_back(new Pixel(j, i));
        }
    }
}


void Camera::debugPixelPositions() {

    for (int i = 0; i < mPixels.size(); i++) {
        mPixels[i]->debugPixelPosition();
    }

    std::cout << "\nSIZE: " << mPixels.size() << std::endl;
}