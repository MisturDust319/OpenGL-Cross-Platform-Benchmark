/*
This file is part of OpenGL-Cross-Platform-Benchmark which is released under the MIT License.
Copyright Stan Slupecki 2018
Go to https://misturdust319.github.io/OpenGL-Cross-Platform-Benchmark/ for full license details.
*/

#include <GLBenchmark/shapes.h>
#include <vector>

// using these objects
// create a new shape
// init it
// use draw to render it

//constructor
Shape::Shape(const glm::vec3 origin) {
	// set the buffers to ID
	// VAO = VBO = EBO = ID;

	// set origin
	setOrigin(origin);	
}

void Shape::init() {
	
	// generate and bind buffers
	glGenVertexArrays(1, &VAO); // VAO
	glGenBuffers(1, &VBO); // VBO
	glGenBuffers(1, &EBO); // EBO

	// 1. bind VAO
	bindVAO();
	// 2. bind then copy verts into vertex buffer
	initVBO();
	// 3. bind then copy inidices into index buffer
	initEBO();
	// 4. set vertex attribute pointers
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

void Shape::bindVAO() {
	glBindVertexArray(VAO);
}

void Shape::initVBO() {
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * getNumberVertices(),
		getVertices(), GL_STATIC_DRAW);
}
void Shape::initEBO() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * getNumberIndices(),
		getIndices(), GL_STATIC_DRAW);
}

void Shape::draw() {
	// ensure this Shape's VAO is bound
	bindVAO();
	// init(); // init the shape
	glDrawElements(GL_TRIANGLES, getNumberIndices(), GL_UNSIGNED_INT, 0);
	// glDrawArrays(GL_TRIANGLES, 0, getNumberVertices());
	glBindVertexArray(0);
}

// set the vertices to an existing vertex of vertices
void Shape::setVertices(const std::vector<float>& verts) {
	vertices = verts;
}
// set the vertices to array of floats
void Shape::setVertices(const float* verts, const int size) {
	for (int i = 0; i < size; i++) {
		this->vertices.emplace_back(verts[i]);
	}
}

void Shape::setIndices(const unsigned int* indices, const int size) {
	for (int i = 0; i < size; i++) {
		this->indices.emplace_back(indices[i]);
	}
}

int Shape::getNumberVertices() {
	return vertices.size();
}

int Shape::getNumberIndices() {
	return indices.size();
}

void Shape::setOrigin(const glm::vec3& shapeOrigin) {
	origin = shapeOrigin;
}
void Shape::setOrigin(float x, float y, float z) {
	origin = glm::vec3(x, y, z);
}

glm::vec3 Shape::getOrigin() {
	return origin;
}

float* Shape::getVertices() {
	// return vector as array
	return &vertices[0];
}

unsigned int* Shape::getIndices() {
	// return vector as array
	return &indices[0];
}

