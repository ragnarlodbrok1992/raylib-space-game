#pragma once
#include"../include/raylib.h"

class Object
{
protected:
	static unsigned int objectCount;

public:
	Vector2 position;
	unsigned int objectId;
	Object(Vector2 position);

	virtual void Draw();
};