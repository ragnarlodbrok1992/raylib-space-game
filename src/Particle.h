#pragma once
#include"../include/raylib.h"
#include"Planet.h"
#include"Object.h"
#include <list>

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
};