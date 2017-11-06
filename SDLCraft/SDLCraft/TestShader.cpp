#include "stdafx.h"
#include "TestShader.h"

TestShader::TestShader(const std::string& VERTEX_FILE, const std::string& FRAGMENT_FILE)
	: Shader(VERTEX_FILE,FRAGMENT_FILE)
{
	GetUniforms();
}		

void TestShader::BindAttributes()
{
	BindAttribute(0, "position");
	BindAttribute(1, "color");
}

void TestShader::GetUniforms()
{
	UseProgram();
	m_locTime = glGetUniformLocation(m_programID, "time");
	m_locVel = glGetUniformLocation(m_programID, "velocity");
}

