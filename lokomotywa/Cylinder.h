#pragma once
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

#include "Drawable.h"
#include "Primitive.h"

#define pv2(p, v) p.push_back((v).x); p.push_back((v).y)
#define pv3(p, v) p.push_back((v).x); p.push_back((v).y); p.push_back((v).z);

class Cylinder :
	public Primitive {
public:
	Cylinder(glm::vec3 scale, glm::vec3 move, int sides) : Primitive(GL_TRIANGLE_STRIP) {
		this->move = move;
		isStatic = false;
		GLfloat radius = 0.5f, halfLength = 0.5f, a = 0.0f;
		GLfloat step = glm::two_pi<GLfloat>() / sides;
		vertices.reserve(5*5*sides);

		glm::vec2 tex(0.5f, 0.5f);
		GLfloat textureID = 1;

		GLfloat currentHeight = halfLength;
		for (int i = 0; i <= sides; i++) {
			glm::vec2 base(glm::cos(a), glm::sin(a));
			glm::vec2 cur = base * radius;

			a += step;
			glm::vec2 base2(glm::cos(a), glm::sin(a));
			glm::vec2 next = base2 * radius;

			pv2(vertices, cur);
			vertices.push_back(currentHeight);
			pv2(vertices, tex + cur);
			vertices.push_back(textureID);

			pv2(vertices, next);
			vertices.push_back(currentHeight);
			pv2(vertices, tex + next);
			vertices.push_back(textureID);
			
			currentHeight = (currentHeight < 0) ? halfLength : -halfLength;

			pv2(vertices, cur);
			vertices.push_back(currentHeight);
			pv2(vertices, tex + cur);
			vertices.push_back(textureID);

			pv2(vertices, next);
			vertices.push_back(currentHeight);
			pv2(vertices, tex + next);
			vertices.push_back(textureID);

			vertices.push_back(0);
			vertices.push_back(0);
			vertices.push_back(currentHeight);
			pv2(vertices, tex);
			vertices.push_back(textureID);

		}
		vertices = Primitive::scaleAndMove(vertices, scale, move);
	}
	void draw(float delta, int modelLoc) {
		trans = glm::translate(trans, move);
		trans = glm::rotate(trans, delta * ROTATE_SPEED, glm::vec3(0.0f, 0.0f, 1.0f));
		trans = glm::translate(trans, -move);
		Primitive::draw(delta, modelLoc);
	}

private:
	const float ROTATE_SPEED = -1.0f;
};
