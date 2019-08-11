#pragma once



#include <Windows.h>

#include <GL/glew.h>
#define GLFW_INCLUDE_NONE
#ifdef _WIN32
#define GLFW_EXPOSE_NATIVE_WIN32
#endif
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>


#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h> 

#include <IL/il.h>
#include <IL/ilu.h>


#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <wrl.h>

using namespace glm;

typedef unsigned int U32;
typedef unsigned short U16;
typedef unsigned char U8;

inline std::string format(const char* fmt, ...) {
	int size = 512;
	char* buffer = 0;
	buffer = new char[size];
	va_list vl;
	va_start(vl, fmt);
	int nsize = vsnprintf(buffer, size, fmt, vl);
	if (size <= nsize) {
		delete[] buffer;
		buffer = 0;
		buffer = new char[nsize + 1];
		nsize = vsnprintf(buffer, size, fmt, vl);
	}
	std::string ret(buffer);
	va_end(vl);
	delete[] buffer;
	return ret;
}


struct Vertex {
	glm::vec3 pos;
	glm::vec2 uvs;
};
