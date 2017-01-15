#include "Cylinder.h"

void Cylinder::load() {
	// TODO
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	
	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vertices.size(), &(vertices[0]), GL_STATIC_DRAW);

	// geometry
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	// texture TODO
	//glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	//glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// unbind
	glBindVertexArray(0);
}

void Cylinder::draw() {
	// TODO
	glBindVertexArray(vao);

	// transformations TODO

	glDrawArrays(GL_TRIANGLES, 0, (GLuint)vertices.size());

	// unbind
	glBindVertexArray(0);
}

Cylinder::~Cylinder() {
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
}