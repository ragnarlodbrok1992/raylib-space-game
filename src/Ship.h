#pragma once
#include "raylib.h"
#include "Object.h"

class Ship: public Object {
public:
  const double Size;
  const float thrustAcceleration = 6.0f; //how fast will ship accelerate
  Vector2 velocity;

private:
  void calculate_ship_shape();
  Vector2 ship_coords[4];

  void UpdateVelocity(Vector2 acceleration);
  void UpdatePosition();
  
public:
  Ship(Vector2 position, const double Size);
  ~Ship();

  void Draw();
  void Rotate(double angle);
  void MoveByVector(Vector2& move_vector);

  void Update(Vector2 acceleration);

};

