#include "include/Object.h"

unsigned int Object::objectCount = 0;


Object::Object(Vector2 position)
{
	this->objectId = objectCount;
	this->position = position;
	objectCount++;
	this->objectType = objType::UNKNOWN;
	this->objectShape = objShape::UNKNOWN;
	this->shapeClassObject = nullptr;
}

Object::~Object()
{
	if (nullptr != this->shapeClassObject)
	{
		delete this->shapeClassObject;
	}
}
