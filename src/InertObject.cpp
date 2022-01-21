#include "InertObject.h"

InertObject::InertObject(Vector2 position) : Object(position)
{
	this->velocity = { 0.0f, 0.0f };
}

InertObject::InertObject(Vector2 position, Vector2 velocity) : Object(position)
{
	this->velocity = velocity;
}

InertObject::InertObject(Vector2 position, objType objectType) : Object(position, objectType)
{
	this->velocity = { 0.0f, 0.0f };
}

InertObject::InertObject(Vector2 position, Vector2 velocity, objType objectType) : Object(position, objectType)
{
	this->velocity = velocity;
}

void InertObject::UpdatePosition()
{
	this->position.x += this->velocity.x * SIMULATION_SPEED;
	this->position.y += this->velocity.y * SIMULATION_SPEED;
};

void InertObject::UpdateVelocity(Vector2 acceleration)
{
	this->velocity.x += acceleration.x * SIMULATION_SPEED;
	this->velocity.y += acceleration.y * SIMULATION_SPEED;
};

void InertObject::Update(Vector2 acceleration)
{
	this->UpdateVelocity(acceleration);
	this->UpdatePosition();
};

