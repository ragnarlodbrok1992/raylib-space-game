#include "include/PlayerShip.h"
#include "../globals.h"
#include "../cursor.h"

// Constructor for remote player... maybe some AI?
PlayerShip::PlayerShip(Vector2 position, const float size) : Ship(position, size)
{
    this->keymap.accelerate = INVALID_KEY;
    this->keymap.fire = INVALID_KEY;
    this->keymap.rotateClockwise = INVALID_KEY;
    this->keymap.rotateCounterclockwise = INVALID_KEY;
	this->playerType = PlayerType::REMOTE;
}

// Constructor for local player
PlayerShip::PlayerShip(Vector2 position, const float size, playerKeyMap_t keys) : Ship(position, size)
{
	this->playerType = PlayerType::LOCAL;
	this->keymap.accelerate = keys.accelerate;
	this->keymap.fire = keys.fire;
	this->keymap.rotateClockwise = keys.rotateClockwise;
	this->keymap.rotateCounterclockwise = keys.rotateCounterclockwise;
}


void PlayerShip::HandlePressedKeys()
{
    if (IsKeyDown(this->keymap.rotateCounterclockwise))
    {
        this->Rotate(Ship::COUNTERCLOCKWISE);
    }
    if (IsKeyDown(this->keymap.rotateClockwise))
    {
        this->Rotate(Ship::CLOCKWISE);
    }

    if (IsKeyDown(this->keymap.accelerate))
    {
        this->velocity.x += this->shipMoveVector.x * this->thrustAcceleration;
        this->velocity.y += this->shipMoveVector.y * this->thrustAcceleration;
        Vector2 revVec;
        revVec.x = this->shipMoveVector.x * -15 + distr(randGen) / 30.0f;
        revVec.y = this->shipMoveVector.y * -15 + distr(randGen) / 30.0f;
        AddSmokeParticleToPipe(this->Accelerate());
    }

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        if(mainRes.cursor->isInAimingTriangle)
            if (this->reload >= this->reloaded)
            {
            this->reload = 0;
            this->missileSpeed = GetDistance(this->position, mainRes.cursor->positionInGame);
			if (this->missileSpeed > 100.0f) this->missileSpeed = 100.0f; // limit missile speed

			this->aimingVector = CalculateUnitVector(this->position, mainRes.cursor->positionInGame);
            AddInertObjectToPipe(this->FireMissile());
            }
    }
    if (!this->chargingMissile)
    {
        if (this->reload < this->reloaded) this->reload++;
    }
}
