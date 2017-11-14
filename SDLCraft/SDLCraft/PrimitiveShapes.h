#pragma once
#include "Model.h"
#include "ModelLoader.h"

class PrimitiveShapes
{
public:
	static Model Triangle(ModelLoader& loader);;

	static Model Triangle(ModelLoader& loader, int w, int h);;

	static Model Rect(ModelLoader& loader);;

	static Model Rect(ModelLoader& loader, int w, int h);;

private:
	static std::vector<float> verticesTriangle;
	static std::vector<int> indicesTriangle;
	static std::vector<float> colorTriangle;
	static std::vector<float> verticesRect;
	static std::vector<int> indicesRect;
	static std::vector<float> colorRect;

};

