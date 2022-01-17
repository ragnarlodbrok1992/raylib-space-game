#pragma once
#include "raylib.h"
#include "Planet.h"
#include "Object.h"
#include <list>
#include <cstddef>

class Particle : public Object
{
private:
	Vector2 velocity;

	void UpdateVelocity(Vector2 acceleration);
	void UpdatePosition();

public:
	Color color;
	const float radius = 2.0f;
	Particle(Vector2 position, Vector2 velocity);
	Particle(Vector2 position, Vector2 velocity, Color color);

	virtual void Draw();
	virtual void Update(Vector2 acceleration);

	void Update();
};

