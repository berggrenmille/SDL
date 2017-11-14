#include "stdafx.h"
#include "PrimitiveShapes.h"

std::vector<float> PrimitiveShapes::verticesTriangle = 
{
	0,0.1f,0,
	-0.1f,-0.1f,0,
	0.1f,-0.1f,0
};
std::vector<int> PrimitiveShapes::indicesTriangle =
{
	0,1,2
};
std::vector<float> PrimitiveShapes::colorTriangle = 
{
	1.0f,1.0f,0,
	0,1.0f,1.0f,
	0.5f,0,1.0f
};

std::vector<float> PrimitiveShapes::verticesRect =
{
	-0.1f,0.1f,0,
	-0.1f,-0.1f,0,
	0.1f,-0.1f,0,
	0.1f,0.1f,0
};
std::vector<int> PrimitiveShapes::indicesRect =
{
	0,1,2,
	0,3,2
};
std::vector<float> PrimitiveShapes::colorRect =
{
	1.0f,1.0f,0,
	0,1.0f,1.0f,
	0.5f,0,1.0f,
	1.0f,0,0
};

Model PrimitiveShapes::Triangle(ModelLoader& loader)
{
	return loader.LoadToVAO(verticesTriangle, indicesTriangle, colorTriangle);
}

Model PrimitiveShapes::Triangle(ModelLoader& loader, int w, int h)
{
	std::vector<float> vT(verticesTriangle);
	std::vector<int> iT(indicesTriangle);
	std::vector<float> cT(colorTriangle);
	for (auto i = 0; i < vT.size(); i++)
	{
		if ((i + 1) % 3 == 2)
			vT[i] *= w;
		else if ((i + 1) % 3 == 1)
			vT[i] *= h;
	}
	return loader.LoadToVAO(vT, iT, cT);
}

Model PrimitiveShapes::Rect(ModelLoader& loader)
{
	return loader.LoadToVAO(verticesRect, indicesRect, colorRect);
}

Model PrimitiveShapes::Rect(ModelLoader& loader, int w, int h)
{
	std::vector<float> vR(verticesRect);
	std::vector<int> iR(indicesRect);
	std::vector<float> cR(colorRect);
	for (auto i = 0; i < vR.size(); i++)
	{
		if ((i + 1) % 3 == 2)
			vR[i] *= w;
		else if ((i + 1) % 3 == 1)
			vR[i] *= h;
	}
	return loader.LoadToVAO(vR, iR, cR);
}
