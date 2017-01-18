#pragma once
#include <vector>
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Drawable.h"

class Primitive :
	public Drawable {
public:
	~Primitive();
	void load();
	void draw(float delta, int modelLoc);

	static std::vector<GLfloat> scaleAndMove(std::vector<GLfloat> v, glm::vec3 scale, glm::vec3 move);
protected:
	Primitive(std::vector<GLfloat> vertices, glm::vec3 scale, glm::vec3 move, GLuint mode) : vertices(scaleAndMove(vertices, scale, move)), mode(mode), move(move) {}
	Primitive(GLuint mode) : mode(mode) {}
	std::vector<GLfloat> vertices;
	GLuint mode;
	static const unsigned VERTEX_SIZE = 6;
	glm::mat4 trans;
	glm::vec3 move;
	bool isStatic = true;
private:
	GLuint vao;
	GLuint vbo;
};



