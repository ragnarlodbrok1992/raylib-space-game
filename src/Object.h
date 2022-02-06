#pragma once
#ifndef H_OBJECT
#define H_OBJECT
#include "raylib.h"

enum class objType
{
	PARTICLE,
	PLANET,
	SHIP,
	UNKNOWN
};

enum class objShape
{
	CIRCLE,
	POLYGON,
	UNKNOWN
};

class Object
{
protected:
	static unsigned int objectCount;

public:
	Vector2 position;
	unsigned int objectId;
	objType objectType;
	objShape objectShape;

	void* shapeClassObject;

	Object(Vector2 position);
	~Object();

	virtual void Draw() = 0;
};

#endif /* H_OBJECT */

