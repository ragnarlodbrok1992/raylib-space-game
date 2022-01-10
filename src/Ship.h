#pragma once
#include "raylib.h"

class Ship {
public:
  double XPos;
  double YPos;
  const double Size;

private:
  void calculate_ship_shape();
  
public:
  Ship(double x_pos, double y_pos, const double size);
  ~Ship();

};

