#include "Window.h"


Window::Window(GLint width, GLint height, const char *label) {
	if (glfwInit() != GL_TRUE) {
		throw std::exception("GLFW init failed");
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	window = glfwCreateWindow(width, height, label, nullptr, nullptr);
	if (window == nullptr)
		throw std::exception("GLFW window creation failed");
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, Window::keyCallback);


	glViewport(0, 0, width, height);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cout << "GLEW init failed" << std::endl;
	}

	Shader s("main.vert", GL_VERTEX_SHADER); // TODO extract

	glEnable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwSwapBuffers(window);
	}
}

Window::~Window() {
}

void Window::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mode) {
	// TODO
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

