#include "stdafx.h"
#include "TestShader.h"

TestShader::TestShader(const std::string& VERTEX_FILE, const std::string& FRAGMENT_FILE)
	: Shader(VERTEX_FILE,FRAGMENT_FILE)
{
	
}

void TestShader::BindAttributes()
{
	BindAttribute(0, "position");
}

