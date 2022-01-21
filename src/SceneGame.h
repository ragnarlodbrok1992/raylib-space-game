#pragma once
#include <list>
#include <random>
#include "raylib.h"
#include "Scene.h"
#include "Utils.h"
#include "Planet.h"
#include "InertObject.h"
#include "SmokeParticle.h"
#include "Ship.h"


class SceneGame : public Scene {
private:
  // Randomness stuff
  std::random_device rand;
  //std::mt19937_64 randGen(rand());
  //std::uniform_int_distribution<> distr(-100, 100);

  // Init control values here
  double angle = 0.04f;
  Vector2 shipMoveVector = {0.0f, -1.0f};

  // Init control structures here
  std::list <Planet*>                  gravitySources;
  std::list <InertObject*>             gravityConsumers;
  std::list <InertObject*>::iterator   iterator;
  std::list <SmokeParticle*>           smokeParticles;
  std::list <SmokeParticle*>::iterator smokeIterator;

  // Placement vectors
  Vector2 shipPlacement    = {250.0f,  200.0f};
  Vector2 planetPlacement  = {1000.0f, 600.0f};
  Vector2 planet2Placement = {650.0f,  350.0f};
  Vector2 planet3Placement = {100.0f,  120.0f};

  // Init objects here
  //Ship ship(shipPlacement, 20.0f);
  //gravityConsumers.push_back(&ship);

  //Planet planet (planetPlacement,  50, 50000,  BLUE);
  //Planet planet2(planet2Placement, 60, 170000, DARKBLUE);
  //Planet planet3(planet3Placement, 30, 30000,  BROWN);

public:
  SceneGame(SceneEnum se);
  ~SceneGame();

  void render();
  void simulate();
};

