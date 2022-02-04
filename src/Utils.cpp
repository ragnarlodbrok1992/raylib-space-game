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

// source: https://math.stackexchange.com/questions/2248617/shortest-distance-between-a-point-and-a-line-segment
// 2 situations to be considered: 
// 1 - line going thru point can create perpendicular line intersecting with given segment
// 2 - there is no line going thru point that can create perpendicular line intersecting with given segment
float DistancePointToSegment(Vector2 segmentFirst, Vector2 segmentSecond, Vector2 point)
{
    float y1 = segmentFirst.y;
    float x1 = segmentFirst.x;
    float y2 = segmentSecond.y;
    float x2 = segmentSecond.x;
    float y = point.y;
    float x = point.x;
    //check for first condition
    
    float tNominator = -(((x1 - x) * (x2 - x1)) + ((y1 - y) * (y2 - y1)));
    float tDenominator = powf(x2 - x1, 2) + powf(y2 - y1,2);
    float t = tNominator / tDenominator;
    if ((t >= 0) && (t <= 1))
    {
        //point can create perpendicular line intersecting with given segment
        float nominator = abs(((x2 - x1) * (y1 - y)) - ((x1 - x) * (y2 - y1)));
        float denominator = sqrtf(powf(x2 - x1, 2) + powf(y2 - y1, 2));
        return nominator / denominator;
    }
    else
    {
        //point cannot create perpendicular line intersecting with given segment
        float d1 = sqrtf(powf(x2 - x, 2) + powf(y2 - y, 2));
        float d2 = sqrtf(powf(x1 - x, 2) + powf(y1 - y, 2));
        return d1 >= d2 ? d2 : d1;
    }

}

void SwapPointers(void** first, void** second)
{
    void* temp = *first;
    *first = *second;
    *second = temp;
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

void WriteMessage(const std::string message, int x, int y) {
  std::string tempMsg = message;
  char* drawMsg = new char[tempMsg.size() + 1];
  drawMsg[tempMsg.size()] = '\0';
  std::copy(tempMsg.begin(), tempMsg.end(), drawMsg);
  DrawText(drawMsg, x, y, 12, BLACK);
  delete[] drawMsg;
};

std::random_device randDev;
std::mt19937_64 randGen(randDev());
std::uniform_int_distribution<> distr(-100, 100);

