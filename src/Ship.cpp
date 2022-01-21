#include <math.h>
#include "raylib.h"
#include "Ship.h"
#include "Utils.h"

// TEMP INCLUDE
#include <iostream>

Ship::Ship(Vector2 position, const float size) : InertObject(position), Size(size){
  calculate_ship_shape();
  this->velocity = { 0.0f, 0.0f };
}

void Ship::calculate_ship_shape() {
  // Calc ship corners
  ship_coords[0] = Vector2{ this->position.x,                                this->position.y };
  ship_coords[1] = Vector2{ this->position.x - ( (float) this->Size / 2.0f), this->position.y + ( (float) this->Size / 2.0f) };
  ship_coords[2] = Vector2{ this->position.x,                                this->position.y - ( (float) this->Size / 2.0f) };
  ship_coords[3] = Vector2{ this->position.x + ( (float) this->Size / 2.0f), this->position.y + ( (float) this->Size / 2.0f) };

}

Ship::~Ship() {
}

void Ship::Draw() {
  DrawLineEx(ship_coords[0], ship_coords[1], 2.0f, PURPLE);
  DrawLineEx(ship_coords[1], ship_coords[2], 2.0f, PURPLE);
  DrawLineEx(ship_coords[2], ship_coords[3], 2.0f, PURPLE);
  DrawLineEx(ship_coords[3], ship_coords[0], 2.0f, PURPLE);

}

void Ship::Rotate(rotationDirection direction) {

  // Vector2 pivot_vector = position; <-- pivot_vector is always ship position
    float angleToRotate = this->rotationSpeed;
    if (direction == COUNTERCLOCKWISE)
    {
        angleToRotate *= -1;
    }
  for (int x = 0; x < 4; x++) {
    //Vector2 new_values = {0.0f, 0.0f};
    float casted_x   = static_cast<float>(ship_coords[x].x) - position.x;
    float casted_y   = static_cast<float>(ship_coords[x].y) - position.y;
    float casted_sin = static_cast<float>(sin(angleToRotate));
    float casted_cos = static_cast<float>(cos(angleToRotate));

    ship_coords[x] = { position.x + (( casted_x * casted_cos) - ( casted_y * casted_sin)),
                       position.y + (( casted_x * casted_sin) + ( casted_y * casted_cos))};
  }
  RotateUnitVector(this->shipMoveVector, angleToRotate);

}

//deprecated and unused - for future removal?
void Ship::MoveByVector(Vector2& move_vector) {
  // Add move vector to all vector2 inside the ship
  position.x         += move_vector.x;
  position.y         += move_vector.y;

  for (int x = 0; x < 4; x++) {
    ship_coords[x].x += move_vector.x;
    ship_coords[x].y += move_vector.y;
  }
}

void Ship::UpdatePosition()
{
    float xChange = this->velocity.x * SIMULATION_SPEED;
    float yChange = this->velocity.y * SIMULATION_SPEED;
    this->position.x += xChange;
    this->position.y += yChange;
    for (int x = 0; x < 4; x++) {
        ship_coords[x].x += xChange;
        ship_coords[x].y += yChange;
    }
};

/* Problem - random number generator should be placed in another class available for the rest of code?
void Ship::Accelerate(SmokeParticle* smoke)
{
    this->velocity.x += this->shipMoveVector.x * this->thrustAcceleration;
    this->velocity.y += this->shipMoveVector.y * this->thrustAcceleration;
    Vector2 revVec;
    revVec.x = ship.shipMoveVector.x * -15 + distr(randGen) / 30.0f;
    revVec.y = ship.shipMoveVector.y * -15 + distr(randGen) / 30.0f;
    SmokeParticle* smoke = new SmokeParticle(ship.position, revVec, 150 + distr(randGen));
}
*/

//Returns new particle pointer - should be handled otherwise memory leak
Particle* Ship::FireMissile()
{
    Vector2 missileVelocity;
    Vector2 missilePosition;
    missileVelocity.x = this->velocity.x + this->shipMoveVector.x * this->missileSpeed;
    missileVelocity.y = this->velocity.y + this->shipMoveVector.y * this->missileSpeed;
    missilePosition.x = this->position.x + this->shipMoveVector.x * this->Size / 2;
    missilePosition.y = this->position.y + this->shipMoveVector.y * this->Size / 2;
    Particle* missile = new Particle(missilePosition, missileVelocity, BLUE);
    missile->objectType = objType::PARTICLE;
    return missile;
}
