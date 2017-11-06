#version 400 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 color;
 
out vec3 colorV;

uniform float time = 0;
uniform vec3 velocity = vec3(0,0,0);

void main(void)
{
	gl_Position = vec4(position.x + velocity.x, position.y,0,1.0);
	
	colorV = color;
}