#include "Mesh.h"



Mesh::Mesh()
{
	mOffset = glm::vec3(0.0f);
}


Mesh::~Mesh()
{
}

void Mesh::pushMovedVertex(const Vertex & vert)
{
	Vertex v = vert;
	v.pos.x += mOffset.x;
	v.pos.y += mOffset.y;
	v.pos.z += mOffset.z;

	mVertices.push_back(v);
}

void Mesh::loadIntoBuffer()
{

	glGenBuffers(1, &mVBO);
	glGenBuffers(1, &mEBO);



	glBindBuffer(GL_ARRAY_BUFFER, mVBO);
	glBufferData(GL_ARRAY_BUFFER, getVertexSize() * sizeof(Vertex), getVertexRef(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, getIndexSize() * sizeof(U32), getIndexRef(), GL_STATIC_DRAW);




	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}

void Mesh::bindAndRender(GLenum primitives)
{
	glBindVertexBuffer(0, mVBO, 0, sizeof(Vertex));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);

	glDrawElements(primitives, getIndexSize(), GL_UNSIGNED_INT, (void*)0);
}

void Mesh::releaseFromBuffer()
{
	glDeleteBuffers(1, &mVBO);
	glDeleteBuffers(1, &mEBO);
	mVBO = 0;
	mEBO = 0;
}
