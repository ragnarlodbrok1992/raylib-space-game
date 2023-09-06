#pragma once
#ifndef H_PLANET
#define H_PLANET
#include "Object.h"
#include "../../ShapeCircle.h"
#include "../../Utils.h"

class Planet : public Object
{
private:
	float mass;
	Color color;
	
	Vector2 GetVersorDirection(Vector2 objectPosition); //returns versor directed from object to center of planet
public:
	Planet(Vector2 position, float radius, float mass, Color color);

	Vector2 GetAcceleration(Vector2 objectPosition);
	void Draw();
};

#endif /* H_PLANET */

