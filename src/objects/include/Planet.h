#pragma once
#ifndef H_PLANET
#define H_PLANET
#include "Object.h"
#include "../../raylibTypes.h"
#include "../../ShapeCircle.h"
#include "../../Utils.h"


class Planet : public Object
{
private:
	float mass;
	rColor color;
	
	rVector2 GetVersorDirection(rVector2 objectPosition); //returns versor directed from object to center of planet
public:
	Planet(rVector2 position, float radius, float mass, rColor color);

	rVector2 GetAcceleration(rVector2 objectPosition);
	void Draw();
};

#endif /* H_PLANET */

