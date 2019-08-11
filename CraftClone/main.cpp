

#include <iostream>

#include "Common.h"
#include "Renderer.h"
#include "Core.h"




int main()
{

	std::shared_ptr<Core> core = std::make_shared<Core>();
	core->createWindow("Test", glm::vec2(1366.0f, 768.0f));


	std::shared_ptr<Renderer> renderer;

	renderer = core->getRenderer();


	for (;;) {
		renderer->begin();


		renderer->end();
	}

    std::cout << "Hello World!\n"; 
}

