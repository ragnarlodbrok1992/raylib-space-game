#pragma once
#ifndef H_COLLISIONS
#define H_COLLISIONS
#include <inttypes.h>
#include <math.h>
#include "raylib.h"
#include "Utils.h"
#include "Object.h"
#include "Particle.h"
#include "Planet.h"

bool IsCollisionCircleCircle(Vector2 firstPosition, float firstRadius, Vector2 secondPosition, float secondRadius);

bool CheckCollision(void* firstObj, void* secondObj);

#endif /* H_COLLISIONS */

