#include <iostream>
#include <cstdio>

#include "Window.h"
#include "Shader.h"
#include "Scene.h"
#include "Triangle.h"
#include "Box.h"
#include "Cylinder.h"

int main(){
	ShaderProgram shaders("main.vert", "main.frag");
	Scene scene;

	Box box(glm::vec3(0.5f, 0.7f, 0.5f), glm::vec3(-1.0f, 0.0f, 0.0f));
	Cylinder c(glm::vec3(1.5f, 1.5f, 0.1f), glm::vec3(0.0f, 0.0f, 0.0f), 20);
	scene.add(&box);
	scene.add(&c);

	try {
		Window window(800, 600, "Lokomotywa", shaders, scene);

		window.run();
	} catch (std::exception ex){
		std::cout << ex.what() << std::endl;
		getchar();
	}

	return 0;
}