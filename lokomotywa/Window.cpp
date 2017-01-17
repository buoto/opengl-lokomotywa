#include "Window.h"

bool Window::keys[1024] = {};

const GLfloat Window::SPEED_MULTIPLIER = 5.0f;

Window::Window(GLint width, GLint height, const char *label, ShaderProgram& sh, Drawable& scene)
	:width(width), height(height), shaderProgram(sh), scene(scene) {
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

	// Texture options
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Textures

	textures.push_back(loadMipmapTexture(GL_TEXTURE0, "wheel.jpg"));

	glEnable(GL_DEPTH_TEST);

	// Init scene on GPU
	scene.load();
}

void Window::run() {
	while (!glfwWindowShouldClose(window)) {
		// Frame calculation
		GLfloat currentFrame = (GLfloat)glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		// Handle input
		glfwPollEvents();
		moveCamera();

		// Clear colorbuffer
		glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Bind textures
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, textures[0]);
		glUniform1i(glGetUniformLocation(shaderProgram.getID(), "Texture0"), 0);

		shaderProgram.use();
		
		// Get locations
		GLuint modelLoc = glGetUniformLocation(shaderProgram.getID(), "model");
		GLuint viewLoc = glGetUniformLocation(shaderProgram.getID(), "view");
		GLuint projectionLoc = glGetUniformLocation(shaderProgram.getID(), "projection");

		// Set perspective projection
		glm::mat4 projection = glm::perspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.f);
		//std::cout << glm::to_string(projection) << std::endl;
		glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

		// Set view transformation
		glm::mat4 view = glm::lookAt(cameraPos, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

		// Set model transformation
		glm::mat4 model;
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		// Draw scene TODO
		scene.draw();

		// Swap screen buffers
		glfwSwapBuffers(window);
	}
}

Window::~Window() {
	glfwTerminate();
}

void Window::moveCamera() {
	GLfloat cameraSpeed = SPEED_MULTIPLIER * deltaTime, radius = 3.0f;
	if (keys[GLFW_KEY_LEFT]) {
		theta -= cameraSpeed;
	} else if (keys[GLFW_KEY_RIGHT]) {
		theta += cameraSpeed;
	} else if (keys[GLFW_KEY_UP]) {
		if (phi + cameraSpeed < glm::half_pi<GLfloat>()) {
			phi += cameraSpeed;
		}
	} else if (keys[GLFW_KEY_DOWN]) {
		if (phi - cameraSpeed > 0) { // > -glm::half_pi<GLfloat>()) {
			phi -= cameraSpeed;
		}
	}
	cameraPos = glm::vec3(sin(theta) * cos(phi) * radius, sin(phi) * radius, cos(theta) * cos(phi) * radius);
}

void Window::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mode) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
		return;
	}
	if (key < 1024) {
		if (action == GLFW_PRESS) {
			keys[key] = true;
		} else if (action == GLFW_RELEASE) {
			keys[key] = false;
		}
	}
}


GLuint Window::loadMipmapTexture(GLuint texID, const char *filename) {
	int width, height;
	unsigned char *image = SOIL_load_image(filename, &width, &height, 0, SOIL_LOAD_RGB);
	if (image == nullptr) {
		throw std::exception(std::string("failed to load texture file: ").append(filename).c_str());
	}
	GLuint texture;
	glGenTextures(1, &texture);

	glActiveTexture(texID);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
	return texture;
}
