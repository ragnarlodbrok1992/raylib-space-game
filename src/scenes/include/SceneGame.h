#pragma once
#ifndef H_SCENEGAME
#define H_SCENEGAME
#include <list>
#include "Scene.h"
#include "../../Utils.h"
#include "../../objects/include/Planet.h"
#include "../../objects/include/InertObject.h"
#include "../../objects/include/SmokeParticle.h"
#include "../../objects/include/Ship.h"
#include "../../Collisions.h"
#include "../../ObjectPipe.h"
#include "../../objects/include/PlayerShip.h"
#include "../../cursor.h"
#include "../../globals.h"


class SceneGame : public Scene {
private:
  // Init control values here
  double angle = 0.04f;
  Vector2 shipMoveVector;

  // Init control structures here
  std::list <Planet*>                  gravitySources;
  std::list <InertObject*>             gravityConsumers;
  std::list <Ship*>					   shipsList;
  std::list <SmokeParticle*>           smokeParticles;

  // Placement vectors
  Vector2 shipPlacement = { 250.0f,  250.0f };
  Vector2 planetPlacement = { 1000.0f, 1000.0f };
  Vector2 planet2Placement = { 650.0f,  350.0f };
  Vector2 planet3Placement = { 100.0f,  120.0f };


public:
  SceneGame();
  ~SceneGame();

  void process_input() override;
  void render() override;
  void simulate() override;
  void prepare_scene() override;
  void render_cursor() override;
  void process_mouse() override;
  Vector2 get_player_position();
  Vector2 get_player_velocity();
};

#endif /* H_SCENEGAME */

