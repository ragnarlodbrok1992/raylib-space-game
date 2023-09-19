#include "main.h"
#include "submodules/network/src/host.h"
#include <Windows.h>

rawData_t networkData = { 0 };

// Engine commands
namespace command {
bool _EXIT = false;
}

// Invoking functions - TODO(moliwa): maybe this should be moved?
void invoke_process_input(void (*func)()) {
  return func();
}

int main(int charc, char** argv) {
    // Init scenes here
    SceneMainMenu* sceneMainMenu = new SceneMainMenu(SceneEnum::MAINMENU);
    SceneGame* sceneGame = new SceneGame(SceneEnum::GAMESCENE);
    SceneEditor* sceneEditor = new SceneEditor(SceneEnum::EDITOR);
    Scene* selectedScene;

  CameraOperation* camera = new CameraOperation();
  camera->register_scene(sceneGame);
  camera->register_scene(sceneMainMenu);
  camera->set_scene(SceneEnum::MAINMENU);

  // Init render control values here
  bool dropdown_console = false;

  // Console initialization
  const int x      = 10;
  const int y      = 10;
  //const float width  = GetScreenWidth() - (x * 2.0f); // Obvious math for borders
  //const float height = 10 + (GetScreenHeight() / 3.0f);
  //Console console(x, y, width, height);
  

  // DEBUG INFO
  //std::cout << "Console values: " << width << " : " << height << std::endl;



  // Start scene is main menu
  selectedScene = sceneMainMenu;
  int gownooo = 0;
  HostNetwork *network;
 
  while (1) {
      //network.send_data(&networkData);
      std::cout << "network data:  " << (networkData.dataLength) << std::endl;
    // Checking if rendering of dropdown-console
    // This is not blockable by console input control
      /*
    if ((camera->is_key_pressed(rKEY_GRAVE)) && (dropdown_console)) {
      dropdown_console = false;

      // Clearing command
      console.clear_cmd_buf();

    } else if (IsKeyPressed(KEY_GRAVE) && (!dropdown_console)) {
      dropdown_console = true;
    }
    */

    // Selecting scene - right now with 1,2,3 keys
    // Checking if scene control is scene or console
    // TODO (ragnar): Move scene selection into a main menu Interface
    if      (camera->is_key_pressed(rKEY_ONE)) {
        camera->set_scene(SceneEnum::MAINMENU);
    }
    else if (camera->is_key_pressed(rKEY_TWO)) {
        camera->set_scene(SceneEnum::GAMESCENE);
    }
    camera->render();
    //else if (camera->is_key_pressed(rKEY_THREE)) {
      //selectedScene = sceneEditor;
   //}
 /*
    // Frame begins here
    BeginDrawing();
    ClearBackground(RAYWHITE);
    if (selectedScene == sceneGame)
    {
        BeginMode2D(*camera->calculate_player_camera(
        sceneGame->get_player_position(),
         sceneGame->get_player_velocity()));
    }

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
    */
  }

  //CloseWindow();

  return 0;
}

