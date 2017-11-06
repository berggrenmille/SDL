#version 400 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 color;
 
out vec3 colorV;

uniform float time = 0;

void main(void)
{
	gl_Position = vec4(position.x+cos(time),position.y+ sin(time),position.z,1.0);
	colorV = color;
}