#include "stdafx.h"
#include "Shader.h"
#include "ShaderLoader.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

Shader::Shader(const std::string& vertexFile, const std::string& fragmentFile)
	:	m_programID (LoadShaders(vertexFile, fragmentFile))
{
	UseProgram();
}


void Shader::LoadInt(GLuint location, int value)
{
	glUniform1i(location, value);
}
void Shader::LoadFloat(GLuint location, int value)
{
	glUniform1f(location, value);
}
void Shader::LoadVector2(GLuint location, const Vector2& vect)
{
	glUniform2f(location, vect.x, vect.y);
}
void Shader::LoadVector3(GLuint location, const Vector3& vect)
{
	glUniform3f(location, vect.x, vect.y, vect.z);
}
void Shader::LoadVector4(GLuint location, const Vector4& vect)
{
	glUniform4f(location, vect.x, vect.y, vect.z, vect.w);
}
void Shader::LoadMatrix4(GLuint location, const Matrix4& matrix)
{
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}

void Shader::BindAttribute(int attribute, const std::string& varName)
{
	glBindAttribLocation(m_programID, attribute, varName.c_str());
}


Shader::~Shader()
{
	StopProgram();
	glDeleteProgram(m_programID);
}

void Shader::UseProgram() const //Check id
{
	glUseProgram(m_programID);
}
void Shader::StopProgram() const
{
	glUseProgram(0);
}
