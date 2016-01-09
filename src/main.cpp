#include <ctime>
#include <cmath>
#include <chrono>

#include "../include/Scene.h"

// Functions

void cleanUp();


// Variables

tbb::concurrent_vector<float>list;

Scene *scene = nullptr;

Camera *camera = nullptr;


void addElement(float i) {
    list.push_back(i);
}


int main(int argc, char **argv) {

    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    



    scene = new Scene();

    camera = new Camera(4, 3);

    camera->debugPixelPositions();

    scene->setCamera(camera);



    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();

    std::cout << "Duration in milliseconds:" << duration << std::endl << std::endl << std::endl;

    cleanUp();

    return 0;
}


void cleanUp() {

    std::cout << "\nCleaning up...\n";

    if(scene)
        delete scene;

    std::cout << "\nClean-up done!\n";
}
