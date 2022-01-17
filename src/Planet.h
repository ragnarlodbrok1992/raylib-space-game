#pragma once
#include "raylib.h"
#include "Object.h"

float GetDistance(Vector2 firstObj, Vector2 secondObj); //TODO: move to different file


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
