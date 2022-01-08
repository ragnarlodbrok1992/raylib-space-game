#pragma once
#include<raylib.h>
#include"Planet.h"

class Particle
{
private:
	Vector2 position;
	Vector2 velocity;
	Color color;	
	Planet* planet=NULL;

	void UpdateVelocity();
	void UpdatePosition();

public:
	Particle(Vector2 position, Vector2 velocity);
	Particle(Vector2 position, Vector2 velocity, Color color);

	void RegisterPlanet(Planet* planet);

	Vector2 GetPosition();
	Color GetColor();
	void Update();
};