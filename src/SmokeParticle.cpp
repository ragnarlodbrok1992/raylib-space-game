#include "SmokeParticle.h"

SmokeParticle::SmokeParticle(Vector2 position, Vector2 velocity, unsigned int lifetime) : InertObject(position, velocity), fadingStrength(255.0f / lifetime)
{
	this->lifetime = lifetime;
	this->color = RED;
}

//not using acceleration. It is just for type prototype compatibility
void SmokeParticle::Update(Vector2 acceleration)
{
	this->UpdatePosition();
	if (this->lifetime > 0) lifetime--;
	this->currentfade -= this->fadingStrength;
	this->color.a = (unsigned char)this->currentfade;
}

void SmokeParticle::Draw()
{
	DrawCircleV(this->position, this->radius, this->color);
}