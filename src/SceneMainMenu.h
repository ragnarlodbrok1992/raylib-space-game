#pragma once
#include "Scene.h"
#include "raylib.h"
#include "Utils.h"


class SceneMainMenu : public Scene {
public:
  SceneMainMenu(SceneEnum se);
  ~SceneMainMenu();

  void render();
  void simulate();
};

