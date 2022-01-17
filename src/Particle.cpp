#include "raylib.h"
#include "Particle.h"
#include "Planet.h"
#include "Utils.h"

Particle::Particle(Vector2 position, Vector2 velocity) : InertObject(position, velocity)
{
	this->color = BLACK;
};

Particle::Particle(Vector2 position, Vector2 velocity, Color color) : InertObject(position, velocity)
{
	this->color = color;
};


void Particle::Draw()
{
	DrawCircleV(this->position, this->radius, this->color);
};

