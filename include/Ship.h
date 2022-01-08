#pragma once
#ifndef H_SHIP
#define H_SHIP

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

#endif /* H_SHIP */
