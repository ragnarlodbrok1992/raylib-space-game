#pragma once
#ifndef H_UTILS
#define H_UTILS

#include <raylib.h>
#include <sstream>
#include <random>
#include <iomanip>

#include "math.h"

const int screenWidth = 1366;
const int screenHeight = 768;

const int FPS = 60;
const float GRAV_CONSTANT = 1.0f; //may be useful for fine tuning the effect of gravity
const float SIMULATION_SPEED = 1.0f / FPS;

// std::string operations
void Upper(std::string& str);

// Vector maths
float GetDistance(Vector2 firstObj, Vector2 secondObj);
float VectorLength(Vector2 vector);
void RotateUnitVector(Vector2& vectorToRotate, double angle);
float DistancePointToSegment(Vector2 segmentFirst, Vector2 segmentSecond, Vector2 point);
Vector2 CalculateVector(Vector2 firstPoint, Vector2 secondPoint); //calculates vector from first point to second
Vector2 CalculateUnitVector(Vector2 firstPoint, Vector2 secondPoint); //calculates versor (unit vector) from first point to second

bool IsPointInTriangle(Vector2 point, Vector2 triangle[3]); //checks if point is inside triangle

// Code operations
void SwapPointers(void** first, void** second); //swaps two pointers

// Utils for writingg messages using raylib
void WriteMessage(const std::string message, float value, int x, int y);          //writes string and float with precision of 3
void WriteMessage(const std::string message, int value, int x, int y);            //writes string and int
void WriteMessage(const std::string message, unsigned int value, int x, int y);   //writes string and unsigned int
void WriteMessage(const std::string message, int x, int y);                       //writes string

// Random stuff
extern std::random_device randDev;
extern std::mt19937_64 randGen;
extern std::uniform_int_distribution<> distr;

#endif /* H_UTILS */
