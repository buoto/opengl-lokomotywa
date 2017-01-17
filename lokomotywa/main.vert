#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 texture;
layout (location = 2) in vec3 normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 vViewPosition;
out vec3 TexCoord;

void main() {
	vec4 viewModelPosition = view * model * vec4(position, 1.0);
	vViewPosition = viewModelPosition.xyz;

	gl_Position = projection * viewModelPosition;
	TexCoord = vec3(texture.x, 1.0f-texture.y, texture.z);
}
