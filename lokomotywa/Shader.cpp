#include "Shader.h"

std::string loadFile(const char *path) {
	std::fstream shader_file(path);
	std::stringstream stream;
	stream << shader_file.rdbuf();
	shader_file.close();
	return stream.str();
}

// Shader constructor with RAII principle in mind
Shader::Shader(const char *path, GLenum shaderType) {

	// compilation
	std::string sourceStr = loadFile(path);
	const GLchar* source = sourceStr.c_str();
	id = glCreateShader(shaderType);
	glShaderSource(id, 1, &source, NULL);
	glCompileShader(id);

	// check compilation status
	GLint success = 0;
	glGetShaderiv(id, GL_COMPILE_STATUS, &success);
	if (!success) {
		GLchar glmsg[512];
		glGetShaderInfoLog(id, sizeof(glmsg), NULL, glmsg);
		std::string msg = std::string("Err during shader compilation: ") + glmsg;
		throw std::exception(msg.c_str());
	}
}

Shader::~Shader() {
	glDeleteShader(id);
}


GLint Shader::getID() {
	return id;
}
