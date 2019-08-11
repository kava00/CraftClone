#pragma once

#include "Common.h"
#include "Logger.h"

class Shader
{
public:
	Shader();
	~Shader();

	void compile(const std::string& vertexShaderPath, const std::string& fragmentShaderPath, const std::string& geometryShaderPath = "");
	void bind();
	GLuint getProgramId() { return mProgramID; }

private:
	GLuint mProgramID;
};

