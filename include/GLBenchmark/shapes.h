/*
This file is part of OpenGL-Cross-Platform-Benchmark which is released under the MIT License.
Copyright Stan Slupecki 2018
Go to https://misturdust319.github.io/OpenGL-Cross-Platform-Benchmark/ for full license details.
*/

#ifndef SHAPES_H
#define SHAPES_H

#include <glm/glm.hpp>
#include <vector> 

class Shape {
private:
	// the shape origin
	glm::vec3 origin;
	// the vertices of the shape
	std::vector<float> vertices;

public:
	// set the vertices
	void setVertices(std::vector<float>&);
	void setVertices(float[], int);

	// get number of vertices
	int getNumberVertices();

	// set origin of shape
	void setOrigin(glm::vec3&);
	void setOrigin(float, float, float);

	// get origin of the shape
	glm::vec3 getOrigin();

	// to return a float array pointer to
	// an array of vertices
	virtual float* getVertices();
};

// triangle inherits from shape
class Triangle : Shape {
public:
	// constructor
	Triangle();
};

#endif // SHAPES_H
