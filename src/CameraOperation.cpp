#include "CameraOperation.h"


void CameraOperation::init_camera()
{
    cameraProperties.offset.x = GetScreenWidth() / 2;
    cameraProperties.offset.y = GetScreenHeight() / 2;
    cameraProperties.target.x = 0.0f;
    cameraProperties.target.y = 0.0f;
    cameraProperties.rotation = 0.0f;
    cameraProperties.zoom = 1.0f;
}

Camera2D* CameraOperation::calculate_player_camera(Vector2 playerPosition, Vector2 playerVelocityVector)
{
    cameraProperties.offset.x = GetScreenWidth() / 2;
    cameraProperties.offset.y = GetScreenHeight() / 2;
    float playerVelocity = VectorLength(playerVelocityVector);
    cameraProperties.target = playerPosition;
    if (((GetScreenWidth() / 3) < abs(playerVelocityVector.x * speedToOffsetFactor)))
    {
        if (0 < playerVelocityVector.x)
        {
            cameraProperties.offset.x -= GetScreenWidth() / 3;
        }
        else
        {
            cameraProperties.offset.x += GetScreenWidth() / 3;
        }
    }
    else
    {
        cameraProperties.offset.x -= playerVelocityVector.x * speedToOffsetFactor;
    }

    if (((GetScreenHeight() / 3) < abs(playerVelocityVector.y * speedToOffsetFactor)))
    {
        if (0 < playerVelocityVector.y)
        {
            cameraProperties.offset.y -= GetScreenHeight() / 3;
        }
        else
        {
            cameraProperties.offset.y += GetScreenHeight() / 3;
        }
    }
    else
    {
        cameraProperties.offset.y -= playerVelocityVector.y * speedToOffsetFactor;
    }

    if (playerVelocity < fullZoomMaxVelocity)
    {
        cameraProperties.zoom = maxZoom;
    }
    else if (playerVelocity < firstRange)
    {
        cameraProperties.zoom = maxZoom - (playerVelocity - fullZoomMaxVelocity) / (firstRangeAdd / (maxZoom - firstRangeZoom));
    }
    else
    {
        cameraProperties.zoom = firstRangeZoom - (playerVelocity - firstRange) / (secondRangeAdd / firstRangeZoom - secondRangeZoom);
    }
    if (cameraProperties.zoom < 0.5f)
    {
        cameraProperties.zoom = 0.5f;
    }
    return &cameraProperties;
}
