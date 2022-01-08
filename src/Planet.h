#pragma once
#include<raylib.h>

const int FPS = 60;
const float GRAV_CONSTANT = 1.0f; //may be useful for fine tuning the effect of gravity
const float SIMULATION_SPEED = 1.0f / FPS;

float GetDistance(Vector2 firstObj, Vector2 secondObj); //TODO: move to different file


class Planet
{
private:
	Vector2 position;
	double radius;
	double mass;
	
	Vector2 GetVersorDirection(Vector2 objectPosition); //returns versor directed from object to center of planet
public:
	
	Planet(Vector2 position, double radius, double mass);
	Vector2 GetPlanetPosition();
	float GetPlanetRadius();

	Vector2 GetAcceleration(Vector2 objectPosition);

};