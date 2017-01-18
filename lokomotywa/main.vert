#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 texture;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 TexCoord;

void main() {

	gl_Position = projection * view * model * vec4(position, 1.0);
	TexCoord = vec3(texture.x, 1.0f-texture.y, texture.z);
}
