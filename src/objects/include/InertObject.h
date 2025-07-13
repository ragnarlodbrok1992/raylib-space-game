#pragma once
#ifndef H_INERTOBJECT
#define H_INERTOBJECT
#include"Object.h"


/*
* Class for every object that have velocity. It can be affected by gravity.
*/
class InertObject : public Object
{
protected:
	virtual void UpdateVelocity(rVector2 acceleration);
	virtual void UpdatePosition();

public:
	rVector2 velocity;
	InertObject(rVector2 position);
	InertObject(rVector2 position, rVector2 velocity);
	InertObject(rVector2 position, objType objectType);
	InertObject(rVector2 position, rVector2 velocity, objType objectType);

	virtual void Update(rVector2 acceleration);

};

#endif /* H_INERTOBJECT */

