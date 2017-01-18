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

	Box body(glm::vec3(2.1f, 0.7f, 0.97f), glm::vec3(0.0f, 0.05f, 0.0f), Box::BODY, 4);
	Box cabin(glm::vec3(0.79f, 0.69f, 0.96f), glm::vec3(-0.35f, 0.7f, 0.0f), Box::BODY, 4);

	// wheels
	Cylinder fr(glm::vec3(1.5f, 1.5f, 0.1f), glm::vec3(0.5f, -0.125f, 0.52f), 20);
	Cylinder fl(glm::vec3(1.5f, 1.5f, 0.1f), glm::vec3(0.5f, -0.125f, -0.51f), 20);
	Cylinder br(glm::vec3(1.5f, 1.5f, 0.1f), glm::vec3(-0.5f, -0.125f, 0.52f), 20);
	Cylinder bl(glm::vec3(1.5f, 1.5f, 0.1f), glm::vec3(-0.5f, -0.125f, -0.51f), 20);

	Box rodR(glm::vec3(1.1f, 0.1f, 0.05f), glm::vec3(0.1f, 0.1f, 0.58f), Box::ROD, 5);
	Box rodL(glm::vec3(1.1f, 0.1f, 0.05f), glm::vec3(0.1f, 0.1f, -0.57f), Box::ROD, 5);
	

	Box ground(glm::vec3(100.0f, 1.0f, 100.0f), glm::vec3(0.7f, -1.05f, 0.0f), Box::STATIC, 3.0f, glm::vec2(20, 20));
	Box rails(glm::vec3(100.0f, 1.0f, 2.0f), glm::vec3(0.4f, -1.0f, 0.0f), Box::STATIC, 2.0f, glm::vec2(20, 1));

	scene.add(&body);
	scene.add(&cabin);
	scene.add(&fr);
	scene.add(&fl);
	scene.add(&br);
	scene.add(&bl);
	scene.add(&rodL);
	scene.add(&rodR);
	scene.add(&ground);
	scene.add(&rails);

	try {
		Window window(800, 600, "Lokomotywa", shaders, scene);

		window.run();
	} catch (std::exception ex){
		std::cout << ex.what() << std::endl;
		getchar();
	}

	return 0;
}