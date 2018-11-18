#include <GLBenchmark/shapes.h>
#include <vector>

//constructor
Shape::Shape(int ID,
		float[] vertices, int numVertices,
		int[] indices, int numIndices,
		glm::vec3 origin
	) {
	// set the buffers to ID
	VAO = VBO = EBO = ID;

	// set origin
	setOrigin(origin);

	//store vertices
	Shape::setVertices(vertices, numVertices);
	//store indices
	Shape::setIndices(indices, numIndices);

	// generate and bind buffers
	glGenBuffers(1, &VAO); // VAO
	glGenBuffers(1, &VBO); // VBO
	glGenBuffers(1, &EBO); // EBO
	// 1. bind VAO
	initVAO();
	// 2. copy verts into vertex buffer
	initVBO();
	// 3. copy inidices into index buffer
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
	glBufferData(GL_ARRAY_BUFFER, getNumberVertices(),
		getVertices(), GL_STATIC_DRAW);
}
void Shape::initEBO() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ARRAY_BUFFER, getNumberIndices(),
		getIndices(), GL_STATIC_DRAW);
}

void Shape::draw() {
	// ensure this Shape's VAO is bound
	bindVAO();
	glDrawElements(GL_TRIANGLES, getVertices, GL)
}

// set the vertices to an existing vertex of vertices
void Shape::setVertices(std::vector<float>& verts) {
	vertices = verts;
}
// set the vertices to array of floats
void Shape::setVertices(float* verts, int size) {
	for (int i = 0; i < size; i++) {
		vertices.emplace_back(verts[i]);
	}
}

void Shape::setIndices(float* indices, int size) {
	for (int i = 0; i < size; i++) {
		vertices.emplace_back(indices[i]);
	}
}

int Shape::getNumberVertices() {
	return vertices.size();
}

int Shape::getNumberIndices() {
	return indices.size();
}

void Shape::setOrigin(glm::vec3& shapeOrigin) {
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

float* Shape::getIndices() {
	// return vector as array
	return &indices[0];
}

// TRIANGLE
Triangle::Triangle() {
	float verts[] = {
		0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		0.0f,  0.5f, 0.0f   // top 
	};

	setVertices(verts, sizeof(verts));
	setOrigin(0, 0, 0);
}

