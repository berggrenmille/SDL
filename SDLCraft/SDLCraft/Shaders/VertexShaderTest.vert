#version 400 core

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inColor;
layout(location = 2) in vec2 inTextureCoord;
 
out vec3 passColor;

uniform float time = 0;
uniform vec3 velocity = vec3(0,0,0);

void main(void)
{
	gl_Position = vec4(inPosition.x + velocity.x, inPosition.y + velocity.y,0,1.0);
	
	passColor = inColor;
}