#pragma once
#include "raylib.h"
#include "Object.h"

class Ship: public Object {
public:
  const double Size;

private:
  void calculate_ship_shape();
  Vector2 ship_coords[4];
  
public:
  Ship(Vector2 position, const double Size);
  ~Ship();

  void Draw();
  void Rotate(double angle);
  void MoveByVector(Vector2& move_vector);

};

