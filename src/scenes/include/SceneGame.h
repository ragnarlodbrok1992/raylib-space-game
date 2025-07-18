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


class SceneGame : public Scene {
private:
  // Init control values here
  double angle = 0.04f;
  Vector2 shipMoveVector;
  Cursor cursor;

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

  Vector2 calculate_cursor_game_position();

public:
	Vector2 cameraTarget;
	Vector2 cameraOffset;
	float cameraZoom;
  SceneGame(SceneEnum se);
  ~SceneGame();

  void process_input();
  void render();
  void simulate();
  void prepare_scene();
  void render_cursor();
  Vector2 get_player_position();
  Vector2 get_player_velocity();
};

#endif /* H_SCENEGAME */

