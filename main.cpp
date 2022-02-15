#pragma once
#include "src/raylib.h"
#include "src/Scene.h"
#include "src/SceneMainMenu.h"
#include "src/SceneGame.h"
#include "src/SceneEditor.h"
#include "src/Console.h"

// TEMP INCLUDES
#include <iostream>

// Invoking functions - TODO(moliwa): maybe this should be moved?
void invoke_process_input(void (*func)()) {
  return func();
}

int main(int charc, char** argv) {
  InitWindow(screenWidth, screenHeight, "RayLib Space Game");

  SetTargetFPS(60);

  // Init render control values here
  bool dropdown_console = false;

  // Console initialization
  int x      = 10;
  int y      = 10;
  int width  = GetScreenWidth() - (x * 2); // Obvious math for borders
  int height = 10 + (GetScreenHeight() / 3);
  Console console(x, y, width, height);

  // DEBUG INFO
  std::cout << "Console values: " << width << " : " << height << std::endl;

  // Init scenes here
  SceneMainMenu* sceneMainMenu = new SceneMainMenu(SceneEnum::MAINMENU);
  SceneGame*     sceneGame     = new SceneGame(SceneEnum::GAMESCENE);
  SceneEditor*   sceneEditor   = new SceneEditor(SceneEnum::EDITOR);
  Scene*         selectedScene;

  // Start scene is main menu
  selectedScene = sceneMainMenu;

  while (!WindowShouldClose()) {
    // Checking if rendering of dropdown-console
    // This is not blockable by console input control
    if ((IsKeyPressed(KEY_GRAVE)) && (dropdown_console)) {
      std::cout << "Deactivating dropdown console!\n";
      dropdown_console = false;

      // Clearing command
      console.clear_cmd_buf();

    } else if (IsKeyPressed(KEY_GRAVE) && (!dropdown_console)) {
      std::cout << "Activating dropdown console!\n";
      dropdown_console = true;
    }

    // Selecting scene - right now with 1,2,3 keys
    // Checking if scene control is scene or console
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
    if (dropdown_console) {
      console.process_input();
    } else {
      selectedScene->process_input();
    }

    selectedScene->render();
    selectedScene->simulate();

    // Render above-scene elements (such as dropdown console - should work on every scene)
    console.render(dropdown_console);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
