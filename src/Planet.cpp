#include <math.h>
#include "raylib.h"
#include "Planet.h"
#include "Utils.h"

Vector2 Planet::GetVersorDirection(Vector2 objectPosition)
{
	Vector2 vector;
	float lenght = GetDistance(this->position, objectPosition);
	vector.x = this->position.x - objectPosition.x;
	vector.y = this->position.y - objectPosition.y;
	vector.x /= lenght;
	vector.y /= lenght;
	return vector;
}

Planet::Planet(Vector2 position, float radius, float mass, Color color):Object(position)
{
	this->radius = radius;
	this->mass = mass;
	this->color = color;
}

Vector2 Planet::GetAcceleration(Vector2 objectPosition)
{
	float distance = GetDistance(this->position, objectPosition);
	float force = (float)(GRAV_CONSTANT * this->mass) / powf(distance, 2);
	Vector2 acceleration = Planet::GetVersorDirection(objectPosition);
	acceleration.x *= force;
	acceleration.y *= force;
	return acceleration;
}

void Planet::Draw()
{
	DrawCircleV(this->position, this->radius, this->color);
}
