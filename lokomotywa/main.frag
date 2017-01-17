#version 330 core

in vec3 TexCoord;

out vec4 color;

uniform sampler2D Texture0;

void main() {
	if (abs(TexCoord.z-1.0f) < 0.00001f) {
		color = texture(Texture0, TexCoord.xy);
	} else {
		color = vec4(1.0f, 0.1f, 0.1f, 0.1f);
	}
}
