#pragma once
#ifndef H_SCENE
#define H_SCENE
#include "raylib.h"
#include <stdexcept>

enum class SceneEnum
{
  MAINMENU,
  EDITOR,
  GAMESCENE,
  UNDEFINED  // Required for some math
};

constexpr const char* SceneEnumToString(SceneEnum e) {
  switch (e) {
    case SceneEnum::MAINMENU:  return "MainMenu";
    case SceneEnum::EDITOR:    return "Editor";
    case SceneEnum::GAMESCENE: return "Game";
    case SceneEnum::UNDEFINED: return "Undefined";
    default: throw std::invalid_argument("Unimplemented item");
  }
};

class Scene {
private:
public:

  Scene(SceneEnum se);
  ~Scene();
  SceneEnum scene;
  virtual void render();    // Function to draw all scene objects
  virtual void simulate();  // Function to simulate internal state of scene
};

#endif /* H_SCENE */

