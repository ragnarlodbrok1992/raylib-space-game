#pragma once

class ShapeCircle
{
public:
	ShapeCircle(float radius)
	{
		this->radius = radius;
	}
	float radius;
	float GetRadius()
	{
		return this->radius;
	}
};
