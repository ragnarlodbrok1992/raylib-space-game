#pragma once
// functions for conversions to raylib structures
#include "raylibTypes.h"
#include "raylib.h"

inline Vector2 convert(rVector2 input)
{
	Vector2 val;
	val.x = input.x;
	val.y = input.y;
	return val;
}

inline Color convert(rColor input)
{
	Color val;
	val.a = input.a;
	val.b = input.b;
	val.r = input.r;
	val.g = input.g;
	return val;
}

inline rColor convert(Color input)
{
	rColor val;
	val.a = input.a;
	val.b = input.b;
	val.r = input.r;
	val.g = input.g;
	return val;
}