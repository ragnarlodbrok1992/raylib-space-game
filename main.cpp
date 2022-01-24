#pragma once
#include "src/raylib.h"
#include "src/Scene.h"
#include "src/SceneMainMenu.h"
#include "src/SceneGame.h"
#include "src/SceneEditor.h"


int main(int charc, char** argv) {
  InitWindow(screenWidth, screenHeight, "RayLib Space Game");

  SetTargetFPS(60);

  // Init scenes here
  SceneMainMenu* sceneMainMenu = new SceneMainMenu(SceneEnum::MAINMENU);
  SceneGame*     sceneGame     = new SceneGame(SceneEnum::GAMESCENE);
  SceneEditor*   sceneEditor   = new SceneEditor(SceneEnum::EDITOR);
  Scene*         selectedScene;

  // Start scene is main menu
  selectedScene = sceneMainMenu;

  while (!WindowShouldClose()) {
    // Selecting scene - right now with 1,2,3 keys
    if      (IsKeyPressed(KEY_ONE)) {
      selectedScene = sceneMainMenu;
    }
    else if (IsKeyPressed(KEY_TWO)) {
      selectedScene = sceneGame;
    }
    else if (IsKeyPressed(KEY_THREE)) {
      selectedScene = sceneEditor;
   }
 
    // Frame begins here
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Select scene to render
    selectedScene->render();
    selectedScene->simulate();

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
