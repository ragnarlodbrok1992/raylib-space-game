#pragma once
#include "raylib.h"
#include "Object.h"

class Planet : public Object
{
private:
	float mass;
	Color color;
	
	Vector2 GetVersorDirection(Vector2 objectPosition); //returns versor directed from object to center of planet
public:
	float radius;
	Planet(Vector2 position, float radius, float mass, Color color);

	Vector2 GetAcceleration(Vector2 objectPosition);
	virtual void Draw();
};
