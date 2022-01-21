#pragma once
#include "raylib.h"
#include "Scene.h"
#include "Utils.h"


class SceneEditor : public Scene {
public:
  SceneEditor(SceneEnum se);
  ~SceneEditor();

  void render();
  void simulate();
};
