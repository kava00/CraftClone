#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoord;
  
out vec3 normal;
out vec2 TexCoord;


uniform mat4 MVP;
uniform mat4 M;
uniform mat4 V;
uniform mat4 P;

void main()
{
	TexCoord = aTexCoord;
    gl_Position = MVP * vec4(aPos, 1.0);
	normal = aNormal;
}