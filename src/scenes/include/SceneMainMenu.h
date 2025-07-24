#pragma once
#ifndef H_SCENEMAINMENU
#define H_SCENEMAINMENU
#include "Scene.h"
#include "../../Utils.h"


class SceneMainMenu : public Scene {
public:
  SceneMainMenu();
  ~SceneMainMenu();

  void process_input() override;
  void process_mouse() override;
  void render() override;
  void simulate() override;
  void prepare_scene() override;
  void render_cursor() override;
};

#endif /* SCENEMAINMENU */

