#pragma once

#include <string>
#include <iostream>
#include <exception>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/ext.hpp>

#include "ShaderProgram.h"
#include "Scene.h"

class Window {
public:
	Window(int width, int height, const char *label, ShaderProgram& sh, Drawable& scene);
	~Window();
	void run();

	static GLuint loadMipmapTexture(GLuint texID, const char* filename);
private:
	static const GLfloat SPEED_MULTIPLIER;
	static bool keys[1024];

	static void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mode);
	void moveCamera();

	GLFWwindow *window;
	int width, height;
	GLfloat deltaTime = 0.0f, lastFrame = 0.0f;
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 0.0f);
	GLfloat theta = 0, phi = 0;
	ShaderProgram& shaderProgram;
	Drawable& scene;
};

