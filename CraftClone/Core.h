#pragma once

#include "Common.h"
#include "Logger.h"
#include "Renderer.h"

class Core
{
public:
	Core();
	~Core();

	void createWindow(const std::string& title, const glm::vec2& dim);
	void resizeWindow(const glm::vec2& dim);
	void changeTitle(const std::string& title);

	std::shared_ptr<Renderer> getRenderer();

private:
	GLFWwindow* mWindow;

	std::shared_ptr<Renderer> mRenderer;

	std::string mTitle;
	glm::vec2 mDimensions;
};

