#include "include/InertObject.h"
#include"../Utils.h"

InertObject::InertObject(rVector2 position) : Object(position)
{
	this->velocity = { 0.0f, 0.0f };
}

InertObject::InertObject(rVector2 position, rVector2 velocity) : Object(position)
{
	this->velocity = velocity;
}

void InertObject::UpdatePosition()
{
	this->position.x += this->velocity.x * SIMULATION_SPEED;
	this->position.y += this->velocity.y * SIMULATION_SPEED;
};

void InertObject::UpdateVelocity(rVector2 acceleration)
{
	this->velocity.x += acceleration.x * SIMULATION_SPEED;
	this->velocity.y += acceleration.y * SIMULATION_SPEED;
};

void InertObject::Update(rVector2 acceleration)
{
	this->UpdateVelocity(acceleration);
	this->UpdatePosition();
};

