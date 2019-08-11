
#version 330 core
out vec4 FragColor;
  

in vec3 normal;
in vec2 TexCoord;

uniform sampler2D mTexture;

void main()
{
	//FragColor = texture(mTexture, TexCoord);

	vec3 norm = normalize(normal);
	vec3 lightDir = normalize(vec3(-0.65f, 0.5f, 0.3f));  
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * texture(mTexture, TexCoord).rgb;
	vec3 ambient = 0.4f * texture(mTexture, TexCoord).rgb;
	vec3 result = (diffuse*0.7f) + ambient;
	FragColor = vec4(result, 1.0);
} 