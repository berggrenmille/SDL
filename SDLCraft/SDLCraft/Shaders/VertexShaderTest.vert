#version 400 core

in vec3 position;

out vec3 colour;

uniform float sinTime = 0;

void main(void)
{
	gl_Position = vec4(position,1.0);
	colour = vec3(sinTime, 0, 0);
}