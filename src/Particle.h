#pragma once
#ifndef H_PARTICLE
#define H_PARTICLE
#include "raylib.h"
#include "Planet.h"
#include "InertObject.h"
#include <list>
#include <cstddef>

class Particle : public InertObject
{
private:

public:
	Color color;
	const float radius = 2.0f;
	Particle(Vector2 position, Vector2 velocity);
	Particle(Vector2 position, Vector2 velocity, Color color);

	virtual void Draw();
};

#endif /* H_OBJECT */

