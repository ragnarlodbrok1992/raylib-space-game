#include "raylib.h"
#include "Ship.h"
#include "Utils.h"

#include <math.h>

Ship::Ship(Vector2 position, const double size) : Object(position), Size(size){
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

void Ship::Rotate(double angle) {

  // Vector2 pivot_vector = position; <-- pivot_vector is always ship position

  for (int x = 0; x < 4; x++) {
    //Vector2 new_values = {0.0f, 0.0f};
    float casted_x   = static_cast<float>(ship_coords[x].x) - position.x;
    float casted_y   = static_cast<float>(ship_coords[x].y) - position.y;
    float casted_sin = static_cast<float>(sin(angle));
    float casted_cos = static_cast<float>(cos(angle));

    ship_coords[x] = { position.x + (( casted_x * casted_cos) - ( casted_y * casted_sin)),
                       position.y + (( casted_x * casted_sin) + ( casted_y * casted_cos))};
  }

}

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

void Ship::UpdateVelocity(Vector2 acceleration)
{
    this->velocity.x += acceleration.x * SIMULATION_SPEED;
    this->velocity.y += acceleration.y * SIMULATION_SPEED;
};

void Ship::Update(Vector2 acceleration)
{
    this->UpdatePosition();
    this->UpdateVelocity(acceleration);
}