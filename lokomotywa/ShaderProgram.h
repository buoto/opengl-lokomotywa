#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shader.h"

class ShaderProgram {
public:
	ShaderProgram(const char *vertex_path,const char *fragment_path);
	void init();
	GLint getID();
	bool use();
private:
	GLint id;
	const char *vertex_path;
	const char *fragment_path;
};

