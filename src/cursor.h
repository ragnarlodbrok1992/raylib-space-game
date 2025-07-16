#pragma once

#ifndef H_CURSOR
#define H_CURSOR

#include <raylib.h>


// How cursor should look in different situations
enum class CursorType
{
	MAIN_MENU,
	GAME_DEFAULT,	// cursor out of available angle for shoot
	GAME_TARGET,	// cursor in available angle for shoot
	UNDEFINED

};

static class Cursor
{
		

public:
	bool isHidden = false;
	Cursor();
	~Cursor();
	void draw(Vector2 position);
	CursorType type = CursorType::UNDEFINED;
	void set_type(CursorType type) { this->type = type; }
};

#endif /* H_CURSOR */