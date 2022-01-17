#pragma once
#include"raylib.h"
#include"Utils.h"
#include"Object.h"
#include"Particle.h"
#include"Planet.h"
#include<inttypes.h>
#include<math.h>


bool IsCollisionCircleCircle(Vector2 firstPosition, float firstRadius, Vector2 secondPosition, float secondRadius);

bool CheckCollision(void* firstObj, void* secondObj);