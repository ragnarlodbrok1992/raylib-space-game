#pragma once
#include"raylib.h"
#include"Ship.h"

#define INVALID_KEY (KeyboardKey)0xff

typedef struct
{
	KeyboardKey rotateClockwise;
	KeyboardKey rotateCounterclockwise;
	KeyboardKey accelerate;
	KeyboardKey fire;
}playerKeyMap_t;

enum class PlayerType
{
	LOCAL,
	REMOTE
};

class PlayerShip : public Ship
{
private:
	playerKeyMap_t keymap;

public:
	PlayerType playerType;
	PlayerShip(Vector2 position, const float size);
	PlayerShip(Vector2 position, const float size, playerKeyMap_t keys);
	void HandlePressedKeys();
};
