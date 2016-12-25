#define GLEW_STATIC
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Window.h"
#include "Shader.h"

int main(){

	try {
		Window window(800, 600, "Lokomotywa");
	} catch (std::exception ex){
		std::cout << ex.what() << std::endl;
	}

	glfwTerminate();
	return 0;
}