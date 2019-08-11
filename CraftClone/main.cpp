

#include <iostream>

#include "Common.h"
#include "Renderer.h"
#include "Core.h"




int main()
{

	std::unique_ptr<Core> core = std::make_unique<Core>();
	core->createWindow("Test");

	std::shared_ptr<Renderer> renderer;

	renderer = core->getRenderer();


	while(!core->windowShouldClose()) {
		renderer->begin();




		renderer->end();
	}


	renderer = nullptr;
	core = nullptr;

	system("pause");


    std::cout << "Hello World!\n"; 
}

