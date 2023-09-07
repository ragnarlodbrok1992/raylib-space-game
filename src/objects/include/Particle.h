#pragma once
#ifndef H_PARTICLE
#define H_PARTICLE
#include "Planet.h"
#include "InertObject.h"
#include "../../ShapeCircle.h"

class Particle : public InertObject
{
private:
	void InitParticle();

public:
	Color color;
	Particle(Vector2 position, Vector2 velocity);
	Particle(Vector2 position, Vector2 velocity, Color color);

	virtual void Draw();
};

#endif /* H_OBJECT */

