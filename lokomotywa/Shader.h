#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
public:
	Shader(const char *path, GLenum shaderType);
	GLint getID();
private:
	GLint id;
};

