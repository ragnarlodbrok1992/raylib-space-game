#pragma once
#include "../include/raylib.h"
#include "Object.h"

const int FPS = 60;
const float GRAV_CONSTANT = 1.0f; //may be useful for fine tuning the effect of gravity
const float SIMULATION_SPEED = 1.0f / FPS;
>>>>>>> dcdce61 (Some changes)

float GetDistance(Vector2 firstObj, Vector2 secondObj); //TODO: move to different file


class Planet : public Object
{
private:
	float mass;
	Color color;
	
	Vector2 GetVersorDirection(Vector2 objectPosition); //returns versor directed from object to center of planet
public:
	float radius;
	Planet(Vector2 position, double radius, double mass, Color color);

	Vector2 GetAcceleration(Vector2 objectPosition);
<<<<<<< HEAD
	virtual void Draw();
};
=======

};
>>>>>>> dcdce61 (Some changes)
