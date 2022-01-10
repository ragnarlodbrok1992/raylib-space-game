#include "raylib.h"
#include "Utils.h"
#include <math.h>

float GetDistance(Vector2 firstObj, Vector2 secondObj)
{ 
	return sqrtf(powf(secondObj.x - firstObj.x, 2) + powf(secondObj.y - firstObj.y, 2));
};

void RotateUnitVector(Vector2& VectorToRotate, double angle) {
  float casted_sin = static_cast<float>(sin(angle));
  float casted_cos = static_cast<float>(cos(angle));

  VectorToRotate = {((VectorToRotate.x * casted_cos) - (VectorToRotate.y * casted_sin)),
                    ((VectorToRotate.x * casted_sin) + (VectorToRotate.y * casted_cos))};
}
