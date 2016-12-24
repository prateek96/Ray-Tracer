//
//  main.cpp
//  traycer: The primary components of the Ray Tracer.
//

#include <memory>
#include <vector>
#include <random>

#include "geometry.hpp"
#include "object.hpp"

int main(void)
{
    // creating the scene (adding objects and lights)
    std::vector<std::unique_ptr<Object>> objects;

    // generate a scene made of random spheres
    size_t numSpheres = 32;
    gen.seed((unsigned int) time(nullptr));
    for (size_t i = 0; i < numSpheres; ++i) {
        Vec3f randPos((0.5 - dis(gen)) * 10, (0.5 - dis(gen)) * 10, (0.5 + dis(gen) * 10));
        float randRadius = (0.5 + dis(gen) * 0.5);
        objects.push_back(std::unique_ptr<Object>(new Sphere(randPos, randRadius)));
    }

    // setting up options
    Options options;
    options.width = 640;
    options.height = 480;
    options.fov = 51.52;
    options.cameraToWorld = Matrix44f(0.945519,  0.000000, -0.3255690,  0,
                                     -0.179534,  0.834209, -0.5214030,  0,
                                      0.271593,  0.551447,  0.7887600,  0,
                                      4.208271,  8.374532,  17.932925,  1);

    // finally, render
    render(options, objects);

    return 0;
}
