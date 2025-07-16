#include "cursor.h"

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
