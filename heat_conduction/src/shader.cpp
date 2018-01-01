#include "shader.h"

using std::string;


std::string readShader(const char *path)
{
	std::string content;
	std::ifstream input_file;

	content.assign(std::istreambuf_iterator<char>(input_file), 
				   std::istreambuf_iterator<char>());
//
	std::cout << content[0] << std::endl;
	std::cout << content.back() << std::endl;
//
	return content;
}

GLuint loadShader(const std::string &source, const GLenum &type)
{
	const char *c_source = source.c_str();

	if (type != GL_VERTEX_SHADER &&
		type != GL_FRAGMENT_SHADER)
	{
		std::cerr << "loadShader: unknown shader type" << 
					std::endl;
		return 0;
	}

	GLuint shader = glCreateShader(type);
//
	std::cout << "Compiling" << std::endl;
//

	glShaderSource(shader, 1, &c_source, nullptr);
	glCompileShader(shader);

	return shader;
}

GLuint createProgram(const GLuint *shaders, const int count)
{
	GLuint program = glCreateProgram();

	for (int i = 0; i < count; i++)
		glAttachShader(program, shaders[i]);

	glLinkProgram(program);

	for (int i = 0; i < count; i++)
		glDeleteShader(shaders[i]);

	return program;
}
