#pragma once
#ifndef H_SHIP
#define H_SHIP

#include "InertObject.h"
#include "../../Utils.h"
#include "Particle.h"
#include "SmokeParticle.h"
#include "../../ShapePolygon.h"
#include "../../ObjectPipe.h"

class Ship: public InertObject {
public:
  enum rotationDirection { CLOCKWISE, COUNTERCLOCKWISE };
  const float Size;
  const float thrustAcceleration = 6.0f/FPS; //how fast will ship accelerate
  const float rotationSpeed = 0.04f;
  bool chargingMissile = false; //indicates whether attack button is pressed
  float missileSpeed = 0.0f;
  float health = 100.0f;
  int reload = 0; //when 100 you will be able to fire. Currently checked in main
  const int reloaded = 100;
  Vector2 shipMoveVector = { 0.0f, -1.0f };
  Vector2 aimingVector = { 0.0f, -1.0f }; // vector that shows where ship is aiming

  const float aiming_line_length = 10000.0f; // length of aiming lines
  const float aiming_line_angle = 0.08f; // width of aiming lines

protected:
  void calculate_ship_shape();
  void calculate_aiming_triangle();
  Vector2 ship_coords[4];
  Vector2 aiming_triangle[3]; //used for drawing aiming triangle (area where missiles can hit without turning the ship)

  void UpdatePosition();
  
public:
  Ship(Vector2 position, const float Size);
  ~Ship();

  void Draw();
  void Rotate(rotationDirection direction);
  void MoveByVector(Vector2& move_vector);
  SmokeParticle* Accelerate();
  Particle* FireMissile();
};

#endif /* H_SHIP */

