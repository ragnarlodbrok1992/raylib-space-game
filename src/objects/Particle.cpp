#include "include/Particle.h"
#include "../toRaylibConversion.h"

Particle::Particle(rVector2 position, rVector2 velocity): InertObject(position, velocity)
{
	this->color = convert(BLACK);
	InitParticle();
};

Particle::Particle(rVector2 position, rVector2 velocity, rColor color): InertObject(position, velocity)
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
	DrawCircleV(convert(this->position), radius, convert(this->color));
};

