#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>

#include "error.h"
#include "draw.h"


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

      GLFWwindow *window = glfwCreateWindow(1280, 720, "Heat Conduction Visualisation", nullptr, nullptr);

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

	GLuint temp = 0;

	std::cout  << createRod(0, 0, temp) << std::endl;

   // Set the clear color to a nice blue
   glClearColor(0.0f, 0.0f, 0.44f, 1.0f);

   while (!glfwWindowShouldClose(main_window)) 
   {
      glClear(GL_COLOR_BUFFER_BIT);

      glfwSwapBuffers(main_window);
      glfwPollEvents();
   }

   glfwDestroyWindow(main_window);
   glfwTerminate();

   return 0;
}
