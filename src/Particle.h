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
	
	std::list <Planet*> planets;

	void UpdateVelocity(Vector2 acceleration);
	void UpdatePosition();

public:
	Color color;
	Particle(Vector2 position, Vector2 velocity);
	Particle(Vector2 position, Vector2 velocity, Color color);

	virtual void Draw();
	virtual void Update(Vector2 acceleration);
	void RegisterPlanet(Planet* planet);

	Vector2 GetPosition();
	Color GetColor();
	void Update();
};
