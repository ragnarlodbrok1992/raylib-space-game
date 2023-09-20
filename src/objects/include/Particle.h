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
	rColor color;
	Particle(rVector2 position, rVector2 velocity);
	Particle(rVector2 position, rVector2 velocity, rColor color);

	virtual void Draw();
};

#endif /* H_OBJECT */

