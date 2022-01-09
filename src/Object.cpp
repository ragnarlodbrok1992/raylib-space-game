#include"../include/raylib.h"
#include"Object.h"

unsigned int Object::objectCount =0;


Object::Object(Vector2 position)
{
	this->objectId = objectCount;
	this->position = position;
	objectCount++;
}

void Object::Draw()
{

}

