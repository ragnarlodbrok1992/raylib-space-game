#pragma once
#include"raylibTypes.h"

class ShapePolygon
{
public:
	rVector2 *shipCoords;
	unsigned int vertexNumber;
	float circumscribedCircleRadius;
	ShapePolygon(rVector2 *shipCoords, unsigned int vertex, float circumscribedCircle)
	{
		this->shipCoords = shipCoords;
		this->vertexNumber = vertex;
		this->circumscribedCircleRadius = circumscribedCircle;
	}
};
