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
#include "ShapePolygon.h"
#include "ShapeCircle.h"

bool IsCollisionCircleCircle(Object* firstCircle, Object* secondCircle);

bool CheckCollision(Object* firstObj, Object* secondObj);

#endif /* H_COLLISIONS */

