#pragma once
#ifndef H_SCENEEDITOR
#define H_SCENEEDITOR
#include "Scene.h"
#include "../../Utils.h"


class SceneEditor : public Scene {
public:
  SceneEditor();
  ~SceneEditor();

  void process_input() override;
  void process_mouse() override;
  void render() override;
  void simulate() override;
  void prepare_scene() override;
  void render_cursor() override;

};

#endif /* H_SCENEEDITOR */

