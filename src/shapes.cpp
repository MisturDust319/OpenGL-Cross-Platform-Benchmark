#include <GLBenchmark/shapes.h>
#include <vector>

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

int Shape::getNumberVertices() {
	return vertices.size();
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