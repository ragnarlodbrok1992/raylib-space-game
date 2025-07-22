#include "cursor.h"
#include "globals.h"
#include "Graphics.h"

Cursor::Cursor()
{
	// Default constructor
}
Cursor::~Cursor()
{
	// Default destructor
}

void Cursor::draw(Vector2 position)
{
	if (this->isHidden)
	{
		return;
	}
	if (this->type == CursorType::GAME_DEFAULT)
	{
		DrawCircleV(position, 2, RED);
		return;
	}
	if (this->type == CursorType::GAME_TARGET)
	{
		DrawCircleV(position, 2, GREEN);
		return;
	}
	DrawCircleV(position, 2, BLACK);
}

void Cursor::calculate_cursor_game_position()
{
	Vector2 mousePosition = GetMousePosition();
	this->positionInGame.x = (mousePosition.x - mainRes.camera->cameraProperties.offset.x) / mainRes.camera->cameraProperties.zoom + mainRes.camera->cameraProperties.target.x;
	this->positionInGame.y = (mousePosition.y - mainRes.camera->cameraProperties.offset.y) / mainRes.camera->cameraProperties.zoom + mainRes.camera->cameraProperties.target.y;
}
