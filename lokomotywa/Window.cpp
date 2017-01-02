#include "Window.h"


Window::Window(GLint width, GLint height, const char *label, ShaderProgram& sh, Drawable& scene)
	:shaderProgram(sh), scene(scene) {
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
		throw std::exception("GLEW init failed");
	}

	shaderProgram.init();

	// Init scene on GPU
	scene.load();

	// Texture options TODO
	// Textures TODO

	glEnable(GL_DEPTH_TEST);
}

void Window::run() {
	while (!glfwWindowShouldClose(window)) {
		// Frame calculation TODO

		// Handle input TODO
		glfwPollEvents();

		// Clear colorbuffer
		glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Bind textures TODO
		shaderProgram.use();
		
		// Get locations TODO

		// Set perspective projection TODO
		// Set view transformation TODO
		// Draw scene TODO
		scene.draw();

		// Swap screen buffers
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

