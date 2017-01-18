#pragma once
#include "Primitive.h"
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
class Box :
	public Primitive {
public:
	enum whatis {STATIC, BODY, ROD};

	Box(glm::vec3 scale, glm::vec3 move, whatis t = STATIC, GLfloat texID = 0.0f, glm::vec2 texScale = glm::vec2(1.0f, 1.0f)) : Primitive({
		// front
		1.0f, 1.0f, 1.0f, texScale.x, texScale.y, texID,
		-1.0f, 1.0f, 1.0f, 0.0f, texScale.y, texID,
		-1.0f, -1.0f, 1.0f, 0.0f, 0.0f, texID,
		1.0f, 1.0f, 1.0f, texScale.x, texScale.y, texID,
		-1.0f, -1.0f, 1.0f, 0.0f, 0.0f, texID,
		1.0f, -1.0f, 1.0f, texScale.x, 0.0f, texID,

		// back
		1.0f, 1.0f, -1.0f, texScale.x, texScale.y, texID,
		-1.0f, 1.0f, -1.0f, 0.0f, texScale.y, texID,
		-1.0f, -1.0f, -1.0f, 0.0f, 0.0f, texID,
		1.0f, 1.0f, -1.0f, texScale.x, texScale.y, texID,
		-1.0f, -1.0f, -1.0f, 0.0f, 0.0f, texID,
		1.0f, -1.0f, -1.0f, texScale.x, 0.0f, texID,
		// left
		-1.0f, 1.0f, 1.0f, texScale.x, texScale.y, texID,
		-1.0f, 1.0f, -1.0f, texScale.x, 0.0f, texID,
		-1.0f, -1.0f, 1.0f, 0.0f, texScale.y, texID,
		-1.0f, 1.0f, -1.0f, texScale.x, 0.0f, texID,
		-1.0f, -1.0f, -1.0f, 0.0f, 0.0f, texID,
		-1.0f, -1.0f, 1.0f, 0.0f, texScale.y, texID,

		// right
		1.0f, 1.0f, 1.0f, texScale.x, texScale.y, texID,
		1.0f, 1.0f, -1.0f, texScale.x, 0, texID,
		1.0f, -1.0f, 1.0f, 0, texScale.y, texID,
		1.0f, 1.0f, -1.0f, texScale.x, 0, texID,
		1.0f, -1.0f, -1.0f, 0, 0, texID,
		1.0f, -1.0f, 1.0f, 0, texScale.y, texID,
		// top
		1.0f, 1.0f, 1.0f, texScale.x, texScale.y, texID,
		1.0f, 1.0f, -1.0f, texScale.x, 0.0f, texID,
		-1.0f, 1.0f, 1.0f, 0.0f, texScale.y, texID,
		1.0f, 1.0f, -1.0f, texScale.x, 0.0f, texID,
		-1.0f, 1.0f, -1.0f, 0.0f, 0.0f, texID,
		-1.0f, 1.0f, 1.0f, 0.0f, texScale.y, texID,
		// down
		1.0f, -1.0f, 1.0f, 0.0f, 0.0f, texID,
		1.0f, -1.0f, -1.0f, 0.0f, 0.0f, texID,
		-1.0f, -1.0f, 1.0f, 0.0f, 0.0f, texID,
		1.0f, -1.0f, -1.0f, 0.0f, 0.0f, texID,
		-1.0f, -1.0f, -1.0f, 0.0f, 0.0f, texID,
		-1.0f, -1.0f, 1.0f, 0.0f, 0.0f, texID,

	}, scale, move, GL_TRIANGLES), type(t) {
		isStatic = !(t == ROD || t == BODY);
	}

	void draw(float delta, int modelLoc) {
		if (type == ROD) {
			last += delta;
			trans = glm::translate(trans, glm::vec3(sin(last)*0.004, cos(last)*0.004, 0.0f));
		}
		Primitive::draw(delta, modelLoc);
	}

private:
	whatis type;
	GLfloat last = 0;
	
};

