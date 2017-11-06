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
}

void TestShader::GetUniforms()
{
	UseProgram();
	m_locSinTime = glGetUniformLocation(m_programID, "sinTime");
	StopProgram();
}

