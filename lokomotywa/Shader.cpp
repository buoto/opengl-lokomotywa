#include "Shader.h"

// Shader constructor with RAII principle in mind
Shader::Shader(const char *path, GLenum shaderType) {
	std::fstream shader_file(path);
	std::stringstream stream;
	stream << shader_file.rdbuf();
	shader_file.close();

	// compilation
	const GLchar* source = stream.str().c_str();
	std::cout << "SOURCE: " << source << std::endl;
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


GLint Shader::getID() {
	return id;
}
