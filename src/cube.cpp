/*
This file is part of OpenGL-Cross-Platform-Benchmark which is released under the MIT License.
Copyright Stan Slupecki 2018
Go to https://misturdust319.github.io/OpenGL-Cross-Platform-Benchmark/ for full license details.
*/

#include <GLBenchmark/cube.h>

// CUBE OBJECT
Cube::Cube(int ID, glm::vec3 origin)
	: Shape(ID, origin) {

	// init vertices
	// float vertices[] = {
	//     -1.0, -1.0,  1.0,
	//      1.0, -1.0,  1.0,
	//      1.0,  1.0,  1.0,
	//     -1.0,  1.0,  1.0,
	//     -1.0, -1.0, -1.0,
	//      1.0, -1.0, -1.0,
	//      1.0,  1.0, -1.0,
	//     -1.0,  1.0, -1.0
	//   };
	float vertices[] = {
		0.0f, -0.5f, 0.0f,  // left
        0.9f, -0.5f, 0.0f,  // right
        0.45f, 0.5f, 0.0f   // top 
	};

	Shape::setVertices(vertices, sizeof(vertices));
	// init indices
 	int indices[] = {
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
	// int indices[] = {
	// 	0, 1, 2,
	// 	3, 4, 5,
	// 	6, 7, 8
	// };

	Shape::setIndices(indices, 39);

}
