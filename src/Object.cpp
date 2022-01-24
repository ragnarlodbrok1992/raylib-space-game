#include "raylib.h"
#include "Object.h"

unsigned int Object::objectCount = 0;


Object::Object(Vector2 position)
{
	this->objectId = objectCount;
	this->position = position;
	objectCount++;
	this->objectType = objType::UNKNOWN;
}

Object::Object(Vector2 position, objType objectType)
{
	this->objectId = objectCount;
	this->position = position;
	objectCount++;
	this->objectType = objectType;
}

// TODO: Should this function be defined?
void Object::Draw()
{

}

