#pragma once
#ifndef H_SHIP
#define H_SHIP
#include "raylib.h"
#include "InertObject.h"
#include "Utils.h"
#include "Particle.h"
#include "SmokeParticle.h"
#include "ShapePolygon.h"

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

private:
  void calculate_ship_shape();
  Vector2 ship_coords[4];

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

