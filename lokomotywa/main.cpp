#include <iostream>

#include "Window.h"
#include "Shader.h"
#include "Scene.h"
#include "Triangle.h"

int main(){
	ShaderProgram shaders("main.vert", "main.frag");
	Scene scene;
	Triangle triangle;
	scene.add(&triangle);

	try {
		Window window(800, 600, "Lokomotywa", shaders, scene);

		window.run();
	} catch (std::exception ex){
		std::cout << ex.what() << std::endl;
		_sleep(10000);
	}

	glfwTerminate();
	return 0;
}