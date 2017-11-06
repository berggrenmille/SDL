#include "stdafx.h"
#include "ShaderLoader.h"
#include "FileLoader.h"
#include <GL/glew.h>
#include <stdexcept>

	GLuint CompileShader(const GLchar* source, GLenum shaderType)
	{
		auto shaderID = glCreateShader(shaderType);

		glShaderSource(shaderID, 1, &source, nullptr);
		glCompileShader(shaderID);

		GLint success = 0;
		GLchar infoLog[512];

		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
		if(!success)
		{
			glGetShaderInfoLog(shaderID, 512, nullptr, infoLog);
			std::cout << std::string(infoLog);
			throw std::runtime_error("Unable to load a shader: " + std::string(infoLog));
		}
		return shaderID;
	}

	GLuint LinkProgram(GLuint vertexShaderID, GLuint fragmentShaderID)
	{
		auto id = glCreateProgram();
		glAttachShader(id, vertexShaderID);
		glAttachShader(id, fragmentShaderID);
		glLinkProgram(id);
		return id;
	}

	GLuint LoadShaders(const std::string& vertexShader, const std::string& fragmentShader)
	{
		auto vertexSource = GetFileContents("Shaders/" + vertexShader + ".vert");
		auto fragmentSource = GetFileContents("Shaders/" + fragmentShader + ".frag");

		auto vertexShaderID = CompileShader(vertexSource.c_str(), GL_VERTEX_SHADER);
		auto fragmentShaderID = CompileShader(fragmentSource.c_str(), GL_FRAGMENT_SHADER);

		auto shaderID = LinkProgram(vertexShaderID, fragmentShaderID);

		glDeleteShader(vertexShaderID);
		glDeleteShader(fragmentShaderID);

		return shaderID;

	}


