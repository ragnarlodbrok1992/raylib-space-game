#pragma once
#include"Ship.h"

#define INVALID_KEY (uint16_t)0xffff



typedef struct
{
	//all members here can be interpreted as raylibs KeyboardKey enum
	uint16_t rotateClockwise;
	uint16_t rotateCounterclockwise;
	uint16_t accelerate;
	uint16_t fire;
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
	PlayerShip(rVector2 position, const float size);
	PlayerShip(rVector2 position, const float size, playerKeyMap_t keys);
	void HandlePressedKeys();
};
