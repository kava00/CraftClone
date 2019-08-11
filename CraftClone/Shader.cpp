#include "Shader.h"



Shader::Shader()
{
}


Shader::~Shader()
{
}

void Shader::compile(const std::string& vertexShaderPath, const std::string& fragmentShaderPath, const std::string& geometryShaderPath)
{

	std::string vertexShaderSourceStr = "";
	std::string fragmentShaderSourceStr = "";
	std::string geometryShaderSourceStr = "";

	{
		std::ifstream in(vertexShaderPath.c_str());

		if (in.is_open()) {
			std::stringstream buffer;
			buffer << in.rdbuf();
			vertexShaderSourceStr = std::string(buffer.str());
		}
		else {
			getLogger()->error(format("Cannot compile vertex shader. Cannot read file: '%s'.", vertexShaderPath.c_str()));
		}
	}
	{
		std::ifstream in(fragmentShaderPath.c_str());
		if (in.is_open()) {
			std::stringstream buffer;
			buffer << in.rdbuf();
			fragmentShaderSourceStr = std::string(buffer.str());
		}
		else {
			getLogger()->error(format("Cannot compile fragment shader. Cannot read file: '%s'.", fragmentShaderPath.c_str()));
		}
	}
	if (geometryShaderPath != "")
	{
		std::ifstream in(geometryShaderPath.c_str());
		if (in.is_open()) {
			std::stringstream buffer;
			buffer << in.rdbuf();
			geometryShaderSourceStr = std::string(buffer.str());
		}
		else {
			getLogger()->error(format("Cannot compile germetry shader. Cannot read file: '%s'.", geometryShaderPath.c_str()));
		}
	}


	const char *vertexShaderSource = vertexShaderSourceStr.c_str();
	const char *fragmentShaderSource = fragmentShaderSourceStr.c_str();
	const char *geometryShaderSource = geometryShaderSourceStr.c_str();

	int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		getLogger()->error(format("Cannot compile vertex shader: '%s'. Desc: '%s'", fragmentShaderPath.c_str(), infoLog));
	}

	int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		getLogger()->error(format("Cannot compile fragment shader: '%s'. Desc: '%s'", fragmentShaderPath.c_str(), infoLog));
	}

	int geometryShader = 0;
	if (geometryShaderPath != "") {
		geometryShader = glCreateShader(GL_GEOMETRY_SHADER);
		glShaderSource(geometryShader, 1, &geometryShaderSource, NULL);
		glCompileShader(geometryShader);
		glGetShaderiv(geometryShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(geometryShader, 512, NULL, infoLog);
			getLogger()->error(format("Cannot compile geometry shader: '%s'. Desc: '%s'", geometryShaderPath.c_str(), infoLog));
		}
	}

	mProgramID = glCreateProgram();
	glAttachShader(mProgramID, vertexShader);
	glAttachShader(mProgramID, fragmentShader);
	if (geometryShaderPath != "")
		glAttachShader(mProgramID, geometryShader);
	glLinkProgram(mProgramID);

	glGetProgramiv(mProgramID, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(mProgramID, 512, NULL, infoLog);
		getLogger()->error(format("Cannot link shaders. Desc: '%s'", infoLog));
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	if (geometryShaderPath != "")
		glDeleteShader(geometryShader);
}

void Shader::bind()
{
	glUseProgram(mProgramID);
}
