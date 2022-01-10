#include"Collisions.h"

void GetSphereAttribute(void* obj, objType objectType, Vector2* returnPosition, float* returnRadius)
{
	if (objectType == objType::PARTICLE)
	{
		*returnRadius = (static_cast<Particle*>(obj))->radius;
		*returnPosition = (static_cast<Particle*>(obj))->position;
	}
	else if (objectType == objType::PLANET)
	{
		*returnRadius = (static_cast<Planet*>(obj))->radius;
		*returnPosition = (static_cast<Planet*>(obj))->position;
	}
}

bool IsThisTypesCollide(objType first, objType second)
{
	if ((first == objType::PARTICLE) && (second == objType::PARTICLE)) return false;
	if ((first == objType::PLANET) && (second == objType::PARTICLE))   return true;
	if ((first == objType::PARTICLE) && (second == objType::PLANET))   return true;
	return false;
}

bool IsCollisionCircleCircle(Vector2 firstPosition, float firstRadius,
	Vector2 secondPosition, float secondRadius)
{
	float distance = GetDistance(firstPosition, secondPosition);
	if (distance <= firstRadius + secondRadius)
	{
		return true;
	}
	return false;
}

bool CheckCollision(void* firstObj, void* secondObj)
{
	//now only working for shperes/circles
	objType firstType = (static_cast<Object*>(firstObj))->objectType;
	objType secondType = (static_cast<Object*>(secondObj))->objectType;
	if (!IsThisTypesCollide(firstType, secondType))
	{
		return false;
	}

	//TODO: check shape of object
	float firstRadius = 0.0f;
	float secondRadius = 0.0f;
	Vector2 firstPosition{ 0,0 };
	Vector2 secondPosition{ 0,0 };
	GetSphereAttribute(firstObj, firstType, &firstPosition, &firstRadius);
	GetSphereAttribute(secondObj, secondType, &secondPosition, &secondRadius);
	return IsCollisionCircleCircle(firstPosition, firstRadius, secondPosition, secondRadius);
}
