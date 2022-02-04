#include "raylib.h"
#include "Particle.h"
#include "Planet.h"
#include "Utils.h"
#include "ShapeCircle.h"

Particle::Particle(Vector2 position, Vector2 velocity): InertObject(position, velocity)
{
	this->color = BLACK;
	InitParticle();
};

Particle::Particle(Vector2 position, Vector2 velocity, Color color): InertObject(position, velocity)
{
	this->color = color;
	InitParticle();
};

void Particle::InitParticle()
{
	this->objectType = objType::PARTICLE;
	this->objectShape = objShape::CIRCLE;
	this->shapeClassObject = new ShapeCircle(2.0f);
};


void Particle::Draw()
{
	float radius = (static_cast<ShapeCircle*>(shapeClassObject))->radius;
	DrawCircleV(this->position, radius, this->color);
};

