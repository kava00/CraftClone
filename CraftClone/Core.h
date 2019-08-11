#pragma once

#include "Common.h"
#include "Logger.h"
#include "Renderer.h"


class Core
{
public:
	Core();
	~Core();

	void createWindow(const std::string& title, const glm::vec2& dim = glm::vec2(0, 0));
	void resizeWindow(const glm::vec2& dim);
	void changeTitle(const std::string& title);

	bool windowShouldClose() { return glfwWindowShouldClose(mWindow); }

	std::shared_ptr<Renderer> getRenderer();
	GLFWwindow* getGlfwWindow() { return mWindow; }

	void glfwResizeCallback(GLFWwindow* window, int width, int height);

	Settings loadSettings(const std::string& path);
	Settings getSettings() { return mSettings; }
private:
	Settings mSettings;
	GLFWwindow* mWindow;

	std::shared_ptr<Renderer> mRenderer;

	std::string mTitle;
	glm::vec2 mDimensions;
};


