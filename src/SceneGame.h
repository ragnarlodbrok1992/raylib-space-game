#pragma once
#ifndef H_SCENEGAME
#define H_SCENEGAME
#include <list>
#include "raylib.h"
#include "Scene.h"
#include "Utils.h"
#include "Planet.h"
#include "InertObject.h"
#include "SmokeParticle.h"
#include "Ship.h"
#include "Collisions.h"
#include "ObjectPipe.h"
#include "PlayerShip.h"


class SceneGame : public Scene {
private:
  // Init control values here
  double angle = 0.04f;
  Vector2 shipMoveVector = {0.0f, -1.0f};

  // Init control structures here
  std::list <Planet*>                  gravitySources;
  std::list <InertObject*>             gravityConsumers;
  std::list <Ship*>					   shipsList;
  std::list <SmokeParticle*>           smokeParticles;

  // Placement vectors
  Vector2 shipPlacement    = {250.0f,  200.0f};
  Vector2 planetPlacement  = {1000.0f, 600.0f};
  Vector2 planet2Placement = {650.0f,  350.0f};
  Vector2 planet3Placement = {100.0f,  120.0f};

public:
  SceneGame(SceneEnum se);
  ~SceneGame();

  void process_input();
  void render();
  void simulate();
};

#endif /* H_SCENEGAME */

