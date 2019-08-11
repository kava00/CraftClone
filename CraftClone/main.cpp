

#include <iostream>

#include "Common.h"
#include "Renderer.h"
#include "Core.h"
#include "Mesh.h"



int main()
{

	std::unique_ptr<Core> core = std::make_unique<Core>();
	core->createWindow("Test");

	std::shared_ptr<Renderer> renderer;

	renderer = core->getRenderer();


	std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>();
	// Front Face
	mesh->getVertexVector().push_back({ {-0.5f, -0.5f, -0.5f},   { 0.0f, 0.5f } });
	mesh->getVertexVector().push_back({ {-0.5f,  0.5f, -0.5f},  {0.0f, 0.0f } });
	mesh->getVertexVector().push_back({ {0.5f,  0.5f, -0.5f},   { 0.5f, 0.0f } });
	mesh->getVertexVector().push_back({ {0.5f, -0.5f, -0.5f},   { 0.5f, 0.5f } });

	// Back Face
	mesh->getVertexVector().push_back({ {-0.5f, -0.5f, 0.5f},  { 0.5f, 0.5f } });
	mesh->getVertexVector().push_back({ {0.5f, -0.5f, 0.5f},   { 0.0f, 0.5f } });
	mesh->getVertexVector().push_back({ {0.5f,  0.5f, 0.5f},  { 0.0f, 0.0f } });
	mesh->getVertexVector().push_back({ {-0.5f,  0.5f, 0.5f}, { 0.5f, 0.0f } });

	// Top Face
	mesh->getVertexVector().push_back({ {-0.5f, 0.5f, -0.5f},   { 0.0f, 0.5f } });
	mesh->getVertexVector().push_back({ {-0.5f, 0.5f,  0.5f},   { 0.0f, 0.0f } });
	mesh->getVertexVector().push_back({ {0.5f, 0.5f,  0.5f},   { 0.5f, 0.0f } });
	mesh->getVertexVector().push_back({ {0.5f, 0.5f, -0.5f},   { 0.5f, 0.5f } });

	// Bottom Face
	mesh->getVertexVector().push_back({ {-0.5f, -0.5f, -0.5f},  { 0.5f, 0.5f } });
	mesh->getVertexVector().push_back({ {0.5f, -0.5f, -0.5f},   { 0.0f, 0.5f } });
	mesh->getVertexVector().push_back({ {0.5f, -0.5f,  0.5f},   { 0.0f, 0.0f } });
	mesh->getVertexVector().push_back({ {-0.5f, -0.5f,  0.5f},  { 0.5f, 0.0f } });

	// Left Face
	mesh->getVertexVector().push_back({ {-0.5f, -0.5f,  0.5f},  { 0.0f, 0.5f } });
	mesh->getVertexVector().push_back({ {-0.5f,  0.5f,  0.5f}, { 0.0f, 0.0f } });
	mesh->getVertexVector().push_back({ {-0.5f,  0.5f, -0.5f},  { 0.5f, 0.0f } });
	mesh->getVertexVector().push_back({ {-0.5f, -0.5f, -0.5f},  { 0.5f, 0.5f } });

	// Right Face
	mesh->getVertexVector().push_back({ {0.5f, -0.5f, -0.5f},   { 0.0f, 0.5f } });
	mesh->getVertexVector().push_back({ {0.5f,  0.5f, -0.5f},   { 0.0f, 0.0f } });
	mesh->getVertexVector().push_back({ {0.5f,  0.5f,  0.5f},   { 0.5f, 0.0f } });
	mesh->getVertexVector().push_back({ {0.5f, -0.5f,  0.5f},   { 0.5f, 0.5f } });

	DWORD indices[] = {
		// Front Face
		0,  1,  2,
		0,  2,  3,

		// Back Face
		4,  5,  6,
		4,  6,  7,

		// Top Face
		8,  9, 10,
		8, 10, 11,

		// Bottom Face
		12, 13, 14,
		12, 14, 15,

		// Left Face
		16, 17, 18,
		16, 18, 19,

		// Right Face
		20, 21, 22,
		20, 22, 23
	};

	for (int i = 0; i < 36; ++i) {
		mesh->getIndexVector().push_back(indices[i]);
	}

	mesh->loadIntoBuffer();

	while(!core->windowShouldClose()) {
		renderer->begin();


		mesh->bindAndRender();

		renderer->end();
	}


	renderer = nullptr;
	core = nullptr;

	system("pause");


    std::cout << "Hello World!\n"; 
}

