#pragma once
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

#include "Drawable.h"
#include "Primitive.h"

class Cylinder :
	public Primitive {
public:
	Cylinder(glm::vec3 scale, glm::vec3 move, int sides) : Primitive(GL_LINE_STRIP) {
		GLfloat radius = 0.5f, halfLength = 0.5f, a = 0.0f;
		GLfloat step = glm::two_pi<GLfloat>() / sides;
		vertices.reserve(5*5*sides);

		GLfloat currentHeight = halfLength;
		for (int i = 0; i < sides; i++) {
			GLfloat x = glm::cos(a) * radius;
			GLfloat y = glm::sin(a) * radius;
			a += step;
			GLfloat x2 = glm::cos(a) * radius;
			GLfloat y2 = glm::sin(a) * radius;

			vertices.push_back(x);
			vertices.push_back(y);
			vertices.push_back(currentHeight);
			vertices.push_back(0);
			vertices.push_back(0);

			vertices.push_back(x2);
			vertices.push_back(y2);
			vertices.push_back(currentHeight);
			vertices.push_back(0);
			vertices.push_back(0);
			
			currentHeight = (currentHeight < 0) ? halfLength : -halfLength;

			vertices.push_back(x);
			vertices.push_back(y);
			vertices.push_back(currentHeight);
			vertices.push_back(0);
			vertices.push_back(0);

			vertices.push_back(x2);
			vertices.push_back(y2);
			vertices.push_back(currentHeight);
			vertices.push_back(0);
			vertices.push_back(0);

			vertices.push_back(0);
			vertices.push_back(0);
			vertices.push_back(currentHeight);
			vertices.push_back(0);
			vertices.push_back(0);

		}
		vertices = Primitive::scaleAndMove(vertices, scale, move);
	}
};
