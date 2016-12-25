#define GLEW_STATIC
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Window.h"
#include "Shader.h"

int main(){
	ShaderProgram s("main.vert", "main.frag");

	try {
		Window window(800, 600, "Lokomotywa", s);

		window.run();
	} catch (std::exception ex){
		std::cout << ex.what() << std::endl;
		_sleep(10000);
	}

	glfwTerminate();
	return 0;
}