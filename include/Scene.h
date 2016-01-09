#ifndef SCENE_H
#define SCENE_H

#include "Camera.h"
#include "Geometry.h"

class Scene {

public:

    Scene();
    
    ~Scene();

    void render();

    void setCamera(Camera *c) { mCamera = c; }

private:

	Camera *mCamera = nullptr;

};

#endif // SCENE_H