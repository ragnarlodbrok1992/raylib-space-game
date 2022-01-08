#include<raylib.h>
#include"Particle.h"
#include"planet.h"

void Particle::UpdatePosition()
{
	this->position.x += this->velocity.x * SIMULATION_SPEED;
	this->position.y += this->velocity.y * SIMULATION_SPEED;
}

void Particle::UpdateVelocity()
{
	Vector2 acceleration = planet->GetAcceleration(this->position);
	this->velocity.x += acceleration.x * SIMULATION_SPEED;
	this->velocity.y += acceleration.y * SIMULATION_SPEED;

}

Particle::Particle(Vector2 position, Vector2 velocity)
{
	this->position.x = position.x;
	this->position.y = position.y;
	this->velocity.x = velocity.x;
	this->velocity.y = velocity.y;
	this->color = BLACK;
}
Particle::Particle(Vector2 position, Vector2 velocity, Color color)
{
	this->position.x = position.x;
	this->position.y = position.y;
	this->velocity.x = velocity.x;
	this->velocity.y = velocity.y;
	this->color = color;
}

void Particle::RegisterPlanet(Planet* planet)
{
	this->planet = planet;
}

Vector2 Particle::GetPosition()
{
	return this->position;
}

Color Particle::GetColor()
{
	return this->color;
}

void Particle::Update()
{
	this->UpdatePosition();
	this->UpdateVelocity();
}