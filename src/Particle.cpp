#include"../include/raylib.h"
#include"Particle.h"
#include"planet.h"
#include"Utils.h"

void Particle::UpdatePosition()
{
	this->position.x += this->velocity.x * SIMULATION_SPEED;
	this->position.y += this->velocity.y * SIMULATION_SPEED;
}

void Particle::UpdateVelocity(Vector2 acceleration)
{
	this->velocity.x += acceleration.x * SIMULATION_SPEED;
	this->velocity.y += acceleration.y * SIMULATION_SPEED;
}

Particle::Particle(Vector2 position, Vector2 velocity) : Object(position)
{
	this->velocity.x = velocity.x;
	this->velocity.y = velocity.y;
	this->color = BLACK;
}
Particle::Particle(Vector2 position, Vector2 velocity, Color color) : Object(position)
{
	this->velocity.x = velocity.x;
	this->velocity.y = velocity.y;
	this->color = color;
}
/*
void Particle::RegisterPlanet(Planet* planet)
{
	this->planets.push_back(planet);
}
*/
void Particle::Update(Vector2 acceleration)
{
	this->UpdatePosition();
	this->UpdateVelocity(acceleration);
}

void Particle::Draw()
{
	DrawCircleV(this->position, 2.0f, this->color);
}