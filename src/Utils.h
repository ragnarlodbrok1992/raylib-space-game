#pragma once
#include "raylib.h"
const int FPS = 60;
const float GRAV_CONSTANT = 1.0f; //may be useful for fine tuning the effect of gravity
const float SIMULATION_SPEED = 1.0f / FPS;

float GetDistance(Vector2 firstObj, Vector2 secondObj);

