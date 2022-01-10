#include "raylib.h"
#include "Utils.h"
#include <math.h>

float GetDistance(Vector2 firstObj, Vector2 secondObj)
{ 
	return sqrtf(powf(secondObj.x - firstObj.x, 2) + powf(secondObj.y - firstObj.y, 2));
};

