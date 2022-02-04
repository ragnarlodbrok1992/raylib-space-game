#pragma once
#include"raylib.h"

class ShapePolygon
{
public:
	Vector2 *shipCoords;
	unsigned int vertexNumber;
	float circumscribedCircleRadius;
	ShapePolygon(Vector2 *shipCoords, unsigned int vertex, float circumscribedCircle)
	{
		this->shipCoords = shipCoords;
		this->vertexNumber = vertex;
		this->circumscribedCircleRadius = circumscribedCircle;
	}
};
