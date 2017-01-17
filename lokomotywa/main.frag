#version 330 core

in vec2 TexCoord;

out vec4 color;

uniform sampler2D Texture0;

void main() {
	//color = vec4(1.0f, 0.1f, 0.1f, 0.1f);
	color = texture(Texture0, TexCoord);
}
