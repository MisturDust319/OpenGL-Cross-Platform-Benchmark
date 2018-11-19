/*
This file is part of OpenGL-Cross-Platform-Benchmark which is released under the MIT License.
Copyright Stan Slupecki 2018
Go to https://misturdust319.github.io/OpenGL-Cross-Platform-Benchmark/ for full license details.
*/

#ifndef CUBES_H
#define CUBES_H

#include <glm/glm.hpp>

#include <GLBenchmark/shapes.h>

class Cube : public Shape {
public:
	// CONSTRUCTOR
	Cube(int, glm::vec3);
};

#endif

