#include "ShaderProgram.h"


ShaderProgram::ShaderProgram(const char *vertex_path, const char *fragment_path) {
	this->vertex_path = vertex_path;
	this->fragment_path = fragment_path;
	this->id = -1;
}

void ShaderProgram::init() {
	Shader vertex(vertex_path, GL_VERTEX_SHADER);
	Shader fragment(fragment_path, GL_FRAGMENT_SHADER);

	id = glCreateProgram();
	glAttachShader(id, vertex.getID());
	glAttachShader(id, fragment.getID());
	glLinkProgram(id);

	// check linkage status
	GLint success = 0;
	glGetProgramiv(id, GL_LINK_STATUS, &success);
	if (!success) {
		GLchar glmsg[512];
		glGetProgramInfoLog(id, sizeof(glmsg), NULL, glmsg);
		std::string msg = std::string("Err during shader linkage: ") + glmsg;
		throw std::exception(msg.c_str());
	}
}


GLint ShaderProgram::getID() {
	return id;
}

bool ShaderProgram::use() {
	if (id != -1) {
		glUseProgram(id);
	}
	return false;
}
