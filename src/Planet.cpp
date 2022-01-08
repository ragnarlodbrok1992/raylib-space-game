#include<raylib.h>
#include "Planet.h"
#include<math.h>

float GetDistance(Vector2 firstObj, Vector2 secondObj) { //TODO: move to different file
	return sqrtf(powf(secondObj.x - firstObj.x,2) + powf(secondObj.y-firstObj.y,2));
}


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

Planet::Planet(Vector2 position, double radius, double mass)
{
	this->position.x = position.x;
	this->position.y = position.y;
	this->radius = radius;
	this->mass = mass;
}

Vector2 Planet::GetPlanetPosition()
{
	return this->position;
}
float Planet::GetPlanetRadius()
{
	return this->radius;
}

Vector2 Planet::GetAcceleration(Vector2 objectPosition)
{
	float distance = GetDistance(this->position, objectPosition);
	float force = (GRAV_CONSTANT * this->mass) / powf(distance, 2);
	Vector2 acceleration = Planet::GetVersorDirection(objectPosition);
	acceleration.x *= force;
	acceleration.y *= force;
	return acceleration;
}