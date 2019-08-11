#include "Renderer.h"



Renderer::Renderer(GLFWwindow * window)
{
	if (window == nullptr) {
		getLogger()->error("Cannot create renderer. Window is nullptr.");
	}

	mWindow = window;
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE);
}

GLuint Renderer::createInputLayout()
{
	GLuint vao;


	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glVertexAttribFormat(0, 3, GL_FLOAT, GL_FALSE, 0);
	glVertexAttribBinding(0, 0);
	glEnableVertexAttribArray(0);

	glVertexAttribFormat(1, 3, GL_FLOAT, GL_FALSE, (3 * sizeof(float)));
	glVertexAttribBinding(1, 0);
	glEnableVertexAttribArray(1);

	glVertexAttribFormat(2, 2, GL_FLOAT, GL_FALSE, (6 * sizeof(float)));
	glVertexAttribBinding(2, 0);
	glEnableVertexAttribArray(2);


	glBindVertexArray(0);


	return vao;
}


void Renderer::begin()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::end()
{
	if (mWindow) {
		glfwSwapBuffers(mWindow);
		glfwPollEvents();
	}
}

Renderer::~Renderer()
{
}
