#include "../include/Scene.h"

Scene::Scene() {

}


Scene::~Scene() {

	if(mCamera)
		delete mCamera;
}


void Scene::render() {

	std::cout << "\nRendering scene...\t";

    std::cout << "Done!" << std::endl;
}