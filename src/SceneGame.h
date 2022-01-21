#pragma once
#include "raylib.h"
#include "Scene.h"
#include "Utils.h"


class SceneGame : public Scene {
private:

public:
  SceneGame(SceneEnum se);
  ~SceneGame();

  void render();
  void simulate();
};

