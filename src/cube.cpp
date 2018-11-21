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
	//     -0.5, -0.5,  0.5,
	//      0.5, -0.5,  0.5,
	//      0.5,  0.5,  0.5,
	//     -0.5,  0.5,  0.5,
	//     -0.5, -0.5, -0.5,
	//      0.5, -0.5, -0.5,
	//      0.5,  0.5, -0.5,
	//     -0.5,  0.5, -0.5,
	//   };

	float vertices[] = {
         0.5f,  0.5f, 0.0f,  // top right
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left 
    };

	Shape::setVertices(vertices, 12);
	// init indices
 	// 	int indices[] = {
	// 	0, 1, 2,
	// 	2, 3, 0,
	// 	1, 5, 6,
	// 	6, 2, 1,
	// 	7, 6, 5,
	// 	5, 4, 7,
	// 	4, 0, 3,
	// 	3, 7, 4,
	// 	4, 5, 1,
	// 	1, 0, 4,
	// 	3, 2, 6,
	// 	6, 7, 3,
	// };
	unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };	

	Shape::setIndices(indices, 6);

}
