#pragma once
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Drawable.h"
#include "Primitive.h"

class Cylinder :
	public Drawable {
public:
	Cylinder(glm::vec3 scale, glm::vec3 move) : vertices(Primitive::scaleAndMove(vertices, scale, move)) {}
	~Cylinder();
	void load();
	void draw();
private:
	std::vector<GLfloat> vertices;
	GLuint vao;
	GLuint vbo;
};
