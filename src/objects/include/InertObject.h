#pragma once
#ifndef H_INERTOBJECT
#define H_INERTOBJECT
#include"Object.h"
#include"../../Utils.h"

/*
* Class for every object that have velocity. It can be affected by gravity.
*/
class InertObject : public Object
{
protected:
	virtual void UpdateVelocity(Vector2 acceleration);
	virtual void UpdatePosition();

public:
	Vector2 velocity;
	InertObject(Vector2 position);
	InertObject(Vector2 position, Vector2 velocity);
	InertObject(Vector2 position, objType objectType);
	InertObject(Vector2 position, Vector2 velocity, objType objectType);

	virtual void Update(Vector2 acceleration);

};

#endif /* H_INERTOBJECT */

