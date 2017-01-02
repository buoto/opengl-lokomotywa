#pragma once
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Drawable.h"

class Triangle :
	public Drawable {
public:
	Triangle();
	~Triangle();
	void load();
	void draw();
private:
	GLuint vao;
	GLuint vbo;
	std::vector<GLfloat> vertices;
};

