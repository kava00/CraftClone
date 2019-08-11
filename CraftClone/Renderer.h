#pragma once

#include "Common.h"
#include "Logger.h"


class Renderer
{
public:
	Renderer(GLFWwindow* window);


	GLuint createInputLayout();


	void begin();
	void end();

	~Renderer();

private:
	GLFWwindow* mWindow;
};

