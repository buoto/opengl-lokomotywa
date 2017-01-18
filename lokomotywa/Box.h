#pragma once
#include "Primitive.h"
class Box :
	public Primitive {
public:
	Box(glm::vec3 scale, glm::vec3 move, GLfloat texID = 0.0f, glm::vec2 texScale = glm::vec2(1.0f, 1.0f), bool isStatic = false) : Primitive({
		// front
		1.0f, 1.0f, 1.0f, 0.0f, 0.0f, texID,
		-1.0f, 1.0f, 1.0f, 0.0f, 0.0f, texID,
		-1.0f, -1.0f, 1.0f, 0.0f, 0.0f, texID,
		1.0f, 1.0f, 1.0f, 0.0f, 0.0f, texID,
		-1.0f, -1.0f, 1.0f, 0.0f, 0.0f, texID,
		1.0f, -1.0f, 1.0f, 0.0f, 0.0f, texID,

		// back
		1.0f, 1.0f, -1.0f, 0.0f, 0.0f, texID,
		-1.0f, 1.0f, -1.0f, 0.0f, 0.0f, texID,
		-1.0f, -1.0f, -1.0f, 0.0f, 0.0f, texID,
		1.0f, 1.0f, -1.0f, 0.0f, 0.0f, texID,
		-1.0f, -1.0f, -1.0f, 0.0f, 0.0f, texID,
		1.0f, -1.0f, -1.0f, 0.0f, 0.0f, texID,
		// left
		-1.0f, 1.0f, 1.0f, 0.0f, 0.0f, texID,
		-1.0f, 1.0f, -1.0f, 0.0f, 0.0f, texID,
		-1.0f, -1.0f, 1.0f, 0.0f, 0.0f, texID,
		-1.0f, 1.0f, -1.0f, 0.0f, 0.0f, texID,
		-1.0f, -1.0f, -1.0f, 0.0f, 0.0f, texID,
		-1.0f, -1.0f, 1.0f, 0.0f, 0.0f, texID,

		// right
		1.0f, 1.0f, 1.0f, 0.0f, 0.0f, texID,
		1.0f, 1.0f, -1.0f, 0.0f, 0.0f, texID,
		1.0f, -1.0f, 1.0f, 0.0f, 0.0f, texID,
		1.0f, 1.0f, -1.0f, 0.0f, 0.0f, texID,
		1.0f, -1.0f, -1.0f, 0.0f, 0.0f, texID,
		1.0f, -1.0f, 1.0f, 0.0f, 0.0f, texID,
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

	}, scale, move, GL_TRIANGLES) {}

private:
	bool isStatic;
	
};

