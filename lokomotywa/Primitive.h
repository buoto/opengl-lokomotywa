#pragma once
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Drawable.h"

class Primitive :
	public Drawable {
public:
	~Primitive();
	void load();
	void draw();
protected:
	Primitive(std::vector<GLfloat> vertices, glm::vec3 scale, glm::vec3 move, GLuint mode) : vertices(scaleAndMove(vertices, scale, move)), mode(mode) {}
	std::vector<GLfloat> vertices;
	GLuint mode;
private:
	static std::vector<GLfloat> scaleAndMove(std::vector<GLfloat> v, glm::vec3 scale, glm::vec3 move);
	GLuint vao;
	GLuint vbo;
};



