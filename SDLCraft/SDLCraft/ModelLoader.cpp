#include "stdafx.h"
#include "ModelLoader.h"

Model ModelLoader::LoadToVAO(std::vector<float> positions, std::vector<int> indices)
{
	int vaoID = CreateVAO();
	BindIndicesBuffer(indices);
	StoreDatainAttributeList(0, positions);
	UnbindVAO();
	return Model(vaoID, indices.size());
}

int ModelLoader::CreateVAO()
{
	GLuint vaoID = 0;
	glGenVertexArrays(1, &vaoID);
	vaos.push_back(vaoID);
	glBindVertexArray(vaoID);
	return vaoID;
}

void ModelLoader::UnbindVAO()
{
	glBindVertexArray(0);
}

void ModelLoader::StoreDatainAttributeList(int AttribIndex, std::vector<float> data)
{
	GLuint vboID;
	glGenBuffers(1, &vboID);
	vbos.push_back(vboID);

	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(data[0]), &data[0], GL_STATIC_DRAW);
	glVertexAttribPointer(AttribIndex, 3, GL_FLOAT, false, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void ModelLoader::BindIndicesBuffer(std::vector<int> indices)
{
	GLuint vboID;
	glGenBuffers(1 , &vboID);
	vbos.push_back(vboID);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(indices[0]), &indices[0], GL_STATIC_DRAW);
}




