#pragma once

#include <fstream>
#include <string>
#include <iostream>

#include "glad/glad.h"

std::string readShader(const char *path);
GLuint loadShader(const std::string &source, const GLenum &type);
GLuint createProgram(const GLuint *shaders, const int count);
