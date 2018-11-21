/*
This file is part of OpenGL-Cross-Platform-Benchmark which is released under the MIT License.
Copyright Stan Slupecki 2018
Go to https://misturdust319.github.io/OpenGL-Cross-Platform-Benchmark/ for full license details.
*/

#ifndef SHAPES_H
#define SHAPES_H

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <vector>

class Shape {
private:
	// the shape origin
	glm::vec3 origin;
	// the vertices of the shape
	std::vector<float> vertices;
	// indices of the shape
	std::vector<unsigned int> indices;

	// buffer IDs
	GLuint VAO, VBO, EBO;

public:
	// constructor
	Shape(int, glm::vec3 );

	// Initialize the shape
	void init();

	// BUFFER BIND FUNCTIONS
	// BIND BUFFERS
	// bind VAO
	void bindVAO();
	// bind VBO
	// void bindVBO();
	// bind EBO
	// void bindEBO();
	// INIT BUFFERS
	// initialize VAO
	// void initVAO();
	// initialize VBO
	void initVBO();
	// initialize EBO
	void initEBO();
	// DRAW FUNCTION
	void draw();

	// GETTERS AND SETTERS
	// set the vertices
	void setVertices(std::vector<float>&);
	void setVertices(float[], int);
	// set indices
	// void setVertices(std::vector<float>&);
	void setIndices(unsigned int[], int);

	// get number of vertices
	int getNumberVertices();
	// get number of indices
	int getNumberIndices();

	// set origin of shape
	void setOrigin(glm::vec3&);
	void setOrigin(float, float, float);

	// get origin of the shape
	glm::vec3 getOrigin();

	// return pointer to vertice array
	float* getVertices();
	// return pointer to index array
	unsigned int* getIndices();
};

#endif // SHAPES_H
