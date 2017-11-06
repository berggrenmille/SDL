#pragma once
#include "Model.h"
#include <vector>
#include <GL/glew.h>

class ModelLoader
{
public:
	void Cleanup();
	Model LoadToVAO(std::vector<float> positions, std::vector<int> indices, std::vector<float> colours);
private:
	int CreateVAO();
	void UnbindVAO();
	void StoreDatainAttributeList(int AttribIndex, std::vector<float> data);
	
	void BindIndicesBuffer(std::vector<int> indices);

	std::vector<GLuint> vaos;
	std::vector<GLuint> vbos;
};

