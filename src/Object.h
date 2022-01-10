#pragma once
#include "raylib.h"

enum class objType
{
	PARTICLE,
	PLANET,
	SHIP
};

class Object
{
protected:
	static unsigned int objectCount;

public:
	Vector2 position;
	unsigned int objectId;
	objType objectType;
	Object(Vector2 position);
	Object(Vector2 position, objType objectType);

	virtual void Draw();
};
