#include <math.h>
#include <raylib.h>

#include "include/Planet.h"
#include "../toRaylibConversion.h"


Planet::Planet(rVector2 position, float radius, float mass, rColor color):Object(position)
{
	this->mass = mass;
	this->color = color;
	this->objectShape = objShape::CIRCLE;
	this->objectType = objType::PLANET;
	this->shapeClassObject = new ShapeCircle(radius);
}

rVector2 Planet::GetVersorDirection(rVector2 objectPosition)
{
	rVector2 vector;
	float lenght = GetDistance(this->position, objectPosition);
	vector.x = this->position.x - objectPosition.x;
	vector.y = this->position.y - objectPosition.y;
	vector.x /= lenght;
	vector.y /= lenght;
	return vector;
}


rVector2 Planet::GetAcceleration(rVector2 objectPosition)
{
	float distance = GetDistance(this->position, objectPosition);
	float force = (float)(GRAV_CONSTANT * this->mass) / powf(distance, 2);
	rVector2 acceleration = Planet::GetVersorDirection(objectPosition);
	acceleration.x *= force;
	acceleration.y *= force;
	return acceleration;
}

void Planet::Draw()
{
  float radius = (static_cast<ShapeCircle*>(shapeClassObject))->radius;
  DrawCircleV(convert(this->position), radius, convert(this->color));
}

