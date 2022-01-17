#pragma once
#include "raylib.h"
#include "InertObject.h"
#include "Utils.h"

class Ship: public InertObject {
public:
  const double Size;
  const float thrustAcceleration = 6.0f/FPS; //how fast will ship accelerate

private:
  void calculate_ship_shape();
  Vector2 ship_coords[4];

  void UpdatePosition();
  
public:
  Ship(Vector2 position, const double Size);
  ~Ship();

  void Draw();
  void Rotate(double angle);
  void MoveByVector(Vector2& move_vector);
};

