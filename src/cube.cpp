/*
This file is part of OpenGL-Cross-Platform-Benchmark which is released under the MIT License.
Copyright Stan Slupecki 2018
Go to https://misturdust319.github.io/OpenGL-Cross-Platform-Benchmark/ for full license details.
*/

#include <GLBenchmark/cube.h>

// CUBE OBJECT
Cube::Cube(const glm::vec3 origin)
	: Shape(origin) {

	// init vertices
	float vertices[] = {
	    -1.0, -1.0,  1.0,
	     1.0, -1.0,  1.0,
	     1.0,  1.0,  1.0,
	    -1.0,  1.0,  1.0,
	    -1.0, -1.0, -1.0,
	     1.0, -1.0, -1.0,
	     1.0,  1.0, -1.0,
	    -1.0,  1.0, -1.0,
	};

	Shape::setVertices(vertices, 24);
	// init indices
	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0,
		1, 5, 6,
		6, 2, 1,
		7, 6, 5,
		5, 4, 7,
		4, 0, 3,
		3, 7, 4,
		4, 5, 1,
		1, 0, 4,
		3, 2, 6,
		6, 7, 3,
	};

	Shape::setIndices(indices, 36);

}
