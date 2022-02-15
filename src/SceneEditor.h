#pragma once
#ifndef H_SCENEEDITOR
#define H_SCENEEDITOR
#include "raylib.h"
#include "Scene.h"
#include "Utils.h"


class SceneEditor : public Scene {
public:
  SceneEditor(SceneEnum se);
  ~SceneEditor();

  void process_input();
  void render();
  void simulate();
};

#endif /* H_SCENEEDITOR */

