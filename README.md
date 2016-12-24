# traycer

A simple WIP ray tracer in C++.

## Compiling and Running

A sample code for the ray tracer is contained in the `main.cpp` file. Compile (and run) it using the following command

> `make`

> `./main` or `make run`

## Features

The program currently implements a simple rendering model using non-recursive ray tracing on Spheres. A lot of work is to be done.

### API

    // Declare the objects vector
    std::vector<std::unique_ptr<Object>> objects;
    // Add objects
    objects.push_back(std::unique_ptr<Object>(new Sphere(pos, radius)));
    // Setup options
    Options options;
    options.width = 640;
    options.height = 480;
    options.fov = 51.52;
    options.cameraToWorld = Matrix44f(0.945519,  0,        -0.325569,  0,
                                     -0.179534,  0.834209, -0.521403,  0,
                                      0.271593,  0.551447,  0.78876,   0,
                                      4.208271,  8.374532,  17.932925, 1);
    // Finally Render
    render(options, objects);
