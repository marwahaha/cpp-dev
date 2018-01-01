#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>

#include "error.h"
#include "draw.h"
#include "shader.h"

#define	WINDOW_WIDTH   1280
#define	WINDOW_HEIGHT   720


GLFWwindow *windowInit() 
{
	int res = glfwInit();

	if (!res) 
	{
	   std::cerr << "Unable to initialize GLFW" << std::endl;
	   return nullptr;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow *window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, 
										  "Heat Conduction Visualisation", 
										  nullptr, nullptr);

	if (!window) 
	{
		std::cerr << "Unable to create GLFW window" << std::endl;
		glfwTerminate();
		return nullptr;
	}

	glfwMakeContextCurrent(window);
	res = gladLoadGL();

	if (!res) 
	{
		std::cerr << "Unable to initialize glad" << std::endl;
		glfwDestroyWindow(window);
		glfwTerminate();
		return nullptr;
	}

	std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

	return window;
}


int main(int argc, char **argv) 
{
	GLFWwindow *main_window = windowInit();

	if (!main_window)
		return -E_WINDOW_CREATE;

	GLuint vao;
	int dot_number = createRod(0.05f, 0.02f, vao);

	GLuint shaders[2];
	std::string vertex_shader, fragment_shader;

	vertex_shader = readShader("../shaders/vertex.glsl");
	fragment_shader = readShader("../shaders/fragment.glsl");

	shaders[0] = loadShader(vertex_shader, GL_VERTEX_SHADER);
	shaders[1] = loadShader(fragment_shader, GL_FRAGMENT_SHADER);

	GLuint shader_program = createProgram(shaders, 2);

	// Set the clear color to a nice blue
	glClearColor(0.0f, 0.0f, 0.44f, 1.0f);

	while (!glfwWindowShouldClose(main_window)) 
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwPollEvents();

		glUseProgram(shader_program);
		glBindVertexArray(vao);

		glDrawArrays(GL_POINTS, 0, dot_number);

		glBindVertexArray(0);

		glfwSwapBuffers(main_window);
	}

	glfwDestroyWindow(main_window);
	glfwTerminate();

	return 0;
}
