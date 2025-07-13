#include "include/PlayerShip.h"

#include <raylib.h>

PlayerShip::PlayerShip(rVector2 position, const float size) : Ship(position, size)
{
    this->keymap.accelerate = INVALID_KEY;
    this->keymap.fire = INVALID_KEY;
    this->keymap.rotateClockwise = INVALID_KEY;
    this->keymap.rotateCounterclockwise = INVALID_KEY;
	this->playerType = PlayerType::REMOTE;
}

PlayerShip::PlayerShip(rVector2 position, const float size, playerKeyMap_t keys) : Ship(position, size)
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

    if (IsKeyPressed(this->keymap.fire))
    {
        if (this->reload >= this->reloaded)
        {
            this->chargingMissile = true;
            this->missileSpeed = 3.0f;
            this->reload = 0;
        }
    }
    if (IsKeyDown(this->keymap.fire))
    {
        if (true == this->chargingMissile)
        {
            this->missileSpeed += 0.5;
        }
    }
    if (IsKeyReleased(this->keymap.fire))
    {
        if (this->chargingMissile == true)
        {
            AddInertObjectToPipe(this->FireMissile());
            this->missileSpeed = 0.0f;
            this->chargingMissile = false;
        }
    }
    if (!this->chargingMissile)
    {
        if (this->reload < this->reloaded) this->reload++;
    }
}
