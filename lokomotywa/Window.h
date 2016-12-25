#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <exception>
#include <string>
#include "Shader.h"

class Window {
public:
	Window(int width, int height, const char *label);
	~Window();



private:
	static void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mode);


	GLFWwindow *window;
};

