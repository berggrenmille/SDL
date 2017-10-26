#pragma once
class Model
{
public:
	Model(int vaoID, int vertexCount);

	int GetVaoID() const;
	int GetVertexCount() const;
private:
	int vaoID;
	int vertexCount;

};

