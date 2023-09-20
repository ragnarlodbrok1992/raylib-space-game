#pragma once
#ifndef H_UTILS
#define H_UTILS
#include <sstream>
#include <random>
#include <iomanip>
#include "raylibTypes.h"
#include "math.h"

const int screenWidth = 1366;
const int screenHeight = 768;

const int FPS = 60;
const float GRAV_CONSTANT = 1.0f; //may be useful for fine tuning the effect of gravity
const float SIMULATION_SPEED = 1.0f / FPS;

// std::string operations
void Upper(std::string& str);

// Vector maths
float GetDistance(rVector2 firstObj, rVector2 secondObj);
float VectorLength(rVector2 vector);
void RotateUnitVector(rVector2& vectorToRotate, double angle);
float DistancePointToSegment(rVector2 segmentFirst, rVector2 segmentSecond, rVector2 point);

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
