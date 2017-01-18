#version 330 core

in vec3 TexCoord;

out vec4 color;

uniform sampler2D wheelTex;
uniform sampler2D railsTex;
uniform sampler2D grassTex;
uniform sampler2D blackMetalTex;
uniform sampler2D rodTex;

void main() {
	if (abs(TexCoord.z-1.0f) < 0.00001f) {
		color = texture(wheelTex, TexCoord.xy);
	} else if (abs(TexCoord.z-2.0f) < 0.00001f) {
		color = texture(railsTex, TexCoord.xy);
	} else if (abs(TexCoord.z-3.0f) < 0.00001f) {
		color = texture(grassTex, TexCoord.xy);
	} else if (abs(TexCoord.z-4.0f) < 0.00001f) {
		color = texture(blackMetalTex, TexCoord.xy);
	} else if (abs(TexCoord.z-5.0f) < 0.00001f) {
		color = texture(rodTex, TexCoord.xy);
	} else {
		color = vec4(1.0f, 0.1f, 0.1f, 0.1f);
	}
}
