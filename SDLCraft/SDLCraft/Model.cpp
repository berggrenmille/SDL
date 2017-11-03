#include "stdafx.h"
#include "Model.h"


Model::Model(int vaoID, int vertexCount)
{
	this->vaoID = vaoID;
	this->vertexCount = vertexCount;
}

int Model::GetVaoID() const
{
	return vaoID;
}

int Model::GetVertexCount() const
{
	return vertexCount;
}
