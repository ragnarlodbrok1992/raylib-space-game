#include <math.h>
#include <raylib.h>

#include "include/Ship.h"
#include "../globals.h"
#include "../scenes/include/SceneGame.h"
#include "../cursor.h"


Ship::Ship(Vector2 position, const float size) : InertObject(position), Size(size){
  calculate_ship_shape();
  this->velocity = { 0.0f, 0.0f };
  this->objectType = objType::SHIP;
  this->objectShape = objShape::POLYGON;
  this->shapeClassObject = new ShapePolygon(this->ship_coords, 4, size);
}

void Ship::calculate_ship_shape() {
  // Calc ship corners
  ship_coords[0] = Vector2{ this->position.x,                                this->position.y };
  ship_coords[1] = Vector2{ this->position.x - ( (float) this->Size / 2.0f), this->position.y + ( (float) this->Size / 2.0f) };
  ship_coords[2] = Vector2{ this->position.x,                                this->position.y - ( (float) this->Size / 2.0f) };
  ship_coords[3] = Vector2{ this->position.x + ( (float) this->Size / 2.0f), this->position.y + ( (float) this->Size / 2.0f) };
}

void Ship::calculate_aiming_triangle() {
	// calculate unit vectors for aiming lines based on shipMoveVector
  Vector2 aiming_line_clockwise = this->shipMoveVector, aiming_line_counter_clockwise = this->shipMoveVector;
  RotateUnitVector(aiming_line_clockwise, -aiming_line_angle);
  RotateUnitVector(aiming_line_counter_clockwise, aiming_line_angle);

  // Calculate aiming triangle
  aiming_triangle[0] = this->ship_coords[2]; // ship tip
  aiming_triangle[1] = Vector2{ aiming_triangle[0].x + this->aiming_line_length * aiming_line_clockwise.x,
                                aiming_triangle[0].y + this->aiming_line_length * aiming_line_clockwise.y };
  aiming_triangle[2] = Vector2{ aiming_triangle[0].x + aiming_line_length * aiming_line_counter_clockwise.x,
                                aiming_triangle[0].y + aiming_line_length * aiming_line_counter_clockwise.y };

  // Check if cursor is in aiming triangle TBD: move it somewhere else?
  mainRes.cursor->calculate_cursor_game_position();

  if (IsPointInTriangle(mainRes.cursor->positionInGame, aiming_triangle))
  {
	  mainRes.cursor->set_type(CursorType::GAME_TARGET);
	  mainRes.cursor->isInAimingTriangle = true;
  }
  else {
      mainRes.cursor->set_type(CursorType::GAME_DEFAULT);
	  mainRes.cursor->isInAimingTriangle = false;
  }

}

Ship::~Ship() {
}

void Ship::Draw() {
  DrawLineEx(ship_coords[0], ship_coords[1], 2.0f, PURPLE);
  DrawLineEx(ship_coords[1], ship_coords[2], 2.0f, PURPLE);
  DrawLineEx(ship_coords[2], ship_coords[3], 2.0f, PURPLE);
  DrawLineEx(ship_coords[3], ship_coords[0], 2.0f, PURPLE);

  DrawTriangleLines(aiming_triangle[0], aiming_triangle[1], aiming_triangle[2], GREEN);
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
	this->calculate_aiming_triangle();
};

// Returns new smoke pointer - should be handled otherwise memory leak
SmokeParticle* Ship::Accelerate()
{
    this->velocity.x += this->shipMoveVector.x * this->thrustAcceleration;
    this->velocity.y += this->shipMoveVector.y * this->thrustAcceleration;
    Vector2 revVec;
    revVec.x = this->shipMoveVector.x * -30 + distr(randGen) / 30.0f;
    revVec.y = this->shipMoveVector.y * -30 + distr(randGen) / 30.0f;
    SmokeParticle* smoke = new SmokeParticle(this->position, revVec, 450 + distr(randGen));
    return smoke;
}


//Returns new particle pointer - should be handled otherwise memory leak
Particle* Ship::FireMissile()
{
    Vector2 missileVelocity;
    Vector2 missilePosition;
    missileVelocity.x = this->velocity.x + this->aimingVector.x * this->missileSpeed;
    missileVelocity.y = this->velocity.y + this->aimingVector.y * this->missileSpeed;
    missilePosition.x = this->position.x + this->shipMoveVector.x * this->Size*2/3;
    missilePosition.y = this->position.y + this->shipMoveVector.y * this->Size*2/3;
    Particle* missile = new Particle(missilePosition, missileVelocity, BLUE);
    return missile;
}
