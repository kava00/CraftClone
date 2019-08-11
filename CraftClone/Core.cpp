#include "Core.h"

namespace Global {
	Core* core; // USED FOR GLFW CALLBACKS
	void glfwResizeCallbackTramp(GLFWwindow* window, int width, int height) {
		if (core) {
			core->glfwResizeCallback(window, width, height);
		}
	}
}

Core::Core()
{
	Global::core = this;
}


Core::~Core()
{
	mRenderer.reset();
	glfwTerminate();
	mWindow = nullptr;
}

void Core::createWindow(const std::string & title, const glm::vec2 & dim)
{
	mTitle = title;
	mDimensions = dim;
	if (!glfwInit()) {
		getLogger()->fatal("Failed to initialize GLFW");
	}

	glfwWindowHint(GLFW_SAMPLES, 1);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	mWindow = glfwCreateWindow(mDimensions.x, mDimensions.y, mTitle.c_str(), nullptr, nullptr);
	if (mWindow == nullptr) {
		getLogger()->fatal("Failed to open GLFW window. If you have an Intel GPU, they are not OpenGL 3.3 compatible.");
		glfwTerminate();
	}
	glfwMakeContextCurrent(mWindow);

	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		getLogger()->fatal("Failed to initialize GLEW");
		glfwTerminate();
	}

	if (!GLEW_VERSION_4_6) {
		getLogger()->fatal("OpenGL 4.6 not supported");
		glfwTerminate();
	}

	glfwSetFramebufferSizeCallback(mWindow, Global::glfwResizeCallbackTramp);


	ilInit();

	glViewport(0.0f, 0.0f, mDimensions.x, mDimensions.y);

	glfwSetInputMode(mWindow, GLFW_STICKY_KEYS, GL_TRUE);

	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
}

void Core::resizeWindow(const glm::vec2 & dim)
{
	if (mWindow) {
		mDimensions = dim;
		glViewport(0.0f, 0.0f, mDimensions.x, mDimensions.y);
	}
}

void Core::changeTitle(const std::string & title)
{
	mTitle = title;
}

std::shared_ptr<Renderer> Core::getRenderer()
{
	if (mWindow != nullptr) {
		if (mRenderer == nullptr) {
			mRenderer = std::make_shared<Renderer>(mWindow);
		}
		return mRenderer;
	}
	else {
		getLogger()->error("Cannot get renderer. Window not created.");
		return nullptr;
	}
}

void Core::glfwResizeCallback(GLFWwindow * window, int width, int height)
{
	resizeWindow(glm::vec2(width, height));
	//getLogger()->debug(format("%i,%i", width, height));
}
