#include "include/SmokeParticle.h"
#include "../toRaylibConversion.h"


SmokeParticle::SmokeParticle(rVector2 position, rVector2 velocity, unsigned int lifetime) : InertObject(position, velocity), fadingStrength(255.0f / lifetime)
{
	this->lifetime = lifetime;
	this->color = convert(RED);
	this->objectType = objType::UNKNOWN;
	this->objectShape = objShape::CIRCLE;
}

//not using acceleration. It is just for type prototype compatibility
void SmokeParticle::Update(rVector2 acceleration)
{
	this->UpdatePosition();
	if (this->lifetime > 0) lifetime--;
	this->currentfade -= this->fadingStrength;
	this->color.a = (unsigned char)this->currentfade;
}

void SmokeParticle::Draw()
{
	DrawCircleV(convert(this->position), this->radius, convert(this->color));
}

