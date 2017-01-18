#include "Primitive.h"

void Primitive::load() {

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	
	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * (vertices.size()), &(vertices[0]), GL_STATIC_DRAW);

	// geometry
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, VERTEX_SIZE * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	// texture
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, VERTEX_SIZE * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// unbind
	glBindVertexArray(0);
}
void Primitive::draw() {
	glBindVertexArray(vao);

	// transformations TODO

	glDrawArrays(mode, 0, (GLuint)vertices.size());

	// unbind
	glBindVertexArray(0);
}

Primitive::~Primitive() {
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
}

std::vector<GLfloat> Primitive::scaleAndMove(std::vector<GLfloat> v, glm::vec3 scale, glm::vec3 move) {
	for (unsigned i = 0; i < v.size();) {
		unsigned ni = i + VERTEX_SIZE;
		v[i] = v[i] * scale.x/2 + move.x;
		i++;
		v[i] = v[i] * scale.y/2 + move.y;
		i++;
		v[i] = v[i] * scale.z/2 + move.z;
		i++;
		i = ni;
	}
	return v;
}