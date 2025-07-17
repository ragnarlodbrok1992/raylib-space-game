#pragma once
#ifndef H_SCENEMAINMENU
#define H_SCENEMAINMENU
#include "Scene.h"
#include "../../Utils.h"


class SceneMainMenu : public Scene {
public:
  SceneMainMenu(SceneEnum se);
  ~SceneMainMenu();

  void process_input();
  void process_mouse();
  void render();
  void simulate();
  void prepare_scene();
};

#endif /* SCENEMAINMENU */

