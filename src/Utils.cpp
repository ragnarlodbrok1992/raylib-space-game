#include <math.h>
#include "raylib.h"
#include "Utils.h"

float GetDistance(Vector2 firstObj, Vector2 secondObj)
{ 
	return sqrtf(powf(secondObj.x - firstObj.x, 2) + powf(secondObj.y - firstObj.y, 2));
};

float VectorLength(Vector2 vector)
{
	return sqrtf(powf(vector.x, 2) + powf(vector.y, 2));
}

void RotateUnitVector(Vector2& VectorToRotate, double angle) {
  float casted_sin = static_cast<float>(sin(angle));
  float casted_cos = static_cast<float>(cos(angle));

  VectorToRotate = {((VectorToRotate.x * casted_cos) - (VectorToRotate.y * casted_sin)),
                    ((VectorToRotate.x * casted_sin) + (VectorToRotate.y * casted_cos))};
}

void WriteMessage(const std::string message, float value, int x, int y)
{
    std::string tempString = message;
    std::stringstream stream;
    stream << std::fixed << std::setprecision(3) << value;
    tempString += stream.str();
    char* fullMessage = new char[tempString.size() + 1];
    fullMessage[tempString.size()] = '\0';
    std::copy(tempString.begin(), tempString.end(), fullMessage);
    DrawText(fullMessage, x, y, 12, BLACK);
    delete[] fullMessage;
}

void WriteMessage(const std::string message, int value, int x, int y)
{
    std::string tempString = message;
    tempString += std::to_string(value);
    char* fullMessage = new char[tempString.size() + 1];
    fullMessage[tempString.size()] = '\0';
    std::copy(tempString.begin(), tempString.end(), fullMessage);
    DrawText(fullMessage, x, y, 12, BLACK);
    delete[] fullMessage;
}
