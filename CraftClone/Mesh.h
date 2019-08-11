#pragma once

#include "Common.h"
#include "Logger.h"

class Mesh
{
public:
	Mesh();
	~Mesh();

	void pushMovedVertex(const Vertex& vert);
	void setVertexMovedPos(const glm::vec3& off) { mOffset = off; }

	void* getVertexRef() { return &mVertices[0]; }
	U32 getVertexSize() { return mVertices.size(); }
	std::vector<Vertex>& getVertexVector() { return mVertices; }

	void* getIndexRef() { return &mIndices[0]; }
	U32 getIndexSize() { return mIndices.size(); }
	std::vector<U32>& getIndexVector() { return mIndices; }

	void loadIntoBuffer();
	void bindAndRender(GLenum primitives = GL_TRIANGLES);
	void releaseFromBuffer();

	GLuint getVBO() { return mVBO; }
	GLuint getEBO() { return mEBO; }

private:
	glm::vec3 mOffset;

	std::vector<Vertex> mVertices;
	std::vector<U32> mIndices;

	GLuint mVBO;
	GLuint mEBO;
};

