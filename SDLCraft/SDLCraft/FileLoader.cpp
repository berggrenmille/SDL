#include "stdafx.h"
#include "FileLoader.h"

#include <fstream>
#include <sstream>
#include <stdexcept>

std::string GetFileContents(const std::string& filePath)
{
	//Load filestream
	std::ifstream inFile(filePath);
	if (!inFile.is_open())
	{
		throw std::runtime_error("Unable to open file: " + filePath);
	}

	//Read filestream
	std::stringstream stream;
	stream << inFile.rdbuf();
	return stream.str();
}
