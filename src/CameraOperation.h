#pragma once

#include <raylib.h>
#include <math.h>
#include "Utils.h"

class CameraOperation
{
public:
	Camera2D* calculate_player_camera(Vector2 playerPosition, Vector2 playerVelocityVector);


	CameraOperation() { init_camera(); }
	~CameraOperation() {}

private:
	void init_camera();
	Camera2D cameraProperties;
	const float maxZoom = 2.0f;
	const float fullZoomMaxVelocity = 40.0f;
	const float firstRangeAdd = 100.0f;
	const float firstRange = fullZoomMaxVelocity + firstRangeAdd;
	const float firstRangeZoom = 1.0f;
	const float secondRangeAdd = 300.0f;
	const float secondRangeZoom = 0.5f;
	const float speedToOffsetFactor = 2.0f;
};
