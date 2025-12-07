#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

#include <ft2build.h>
#include FT_FREETYPE_H

int endProgram(std::string message);
unsigned int createShader(const char* vsSource, const char* fsSource);
unsigned loadImageToTexture(const char* filePath);
GLFWcursor* loadImageToCursor(const char* filePath);
void preprocessTexture(unsigned& texture, const char* filePath);
void LoadFont(const char* path);