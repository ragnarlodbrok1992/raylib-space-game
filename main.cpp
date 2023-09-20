#include "main.h"

static void handle_commands(Command cmd);
rawData_t networkData = { 0 };

// Invoking functions - TODO(moliwa): maybe this should be moved?
void invoke_process_input(void (*func)()) {
  return func();
}

int main(int charc, char** argv) {
  mainResources_t mainRes;
  int status = 0;
  // Init scenes here
  mainRes.sceneMainMenu = new SceneMainMenu(SceneEnum::MAINMENU);
  mainRes.sceneGame = new SceneGame(SceneEnum::GAMESCENE);
 

  mainRes.camera = new Graphics();
  mainRes.console = new Console();
  mainRes.camera->register_scene(mainRes.sceneGame);
  mainRes.camera->register_scene(mainRes.sceneMainMenu);
  mainRes.camera->register_console(mainRes.console);
  mainRes.camera->set_scene(SceneEnum::MAINMENU);

  // Start scene is main menu
  mainRes.selectedScene = mainRes.sceneMainMenu;
  
  mainRes.network = new HostNetwork(&status, "10667");
  if (0 != status)
  {
      delete mainRes.network;
  }
  if (mainRes.network != nullptr)
  {
      mainRes.network->start_thread();
  }
 
  while (!mainRes.camera->should_window_close()) {

    // Checking if rendering of dropdown-console
    // This is not blockable by console input control
      
    if ((mainRes.camera->is_key_pressed(rKEY_GRAVE)) && (mainRes.console->is_active)) {
        mainRes.console->is_active = false;

      // Clearing command
        mainRes.console->clear_cmd_buf();

    } else if (mainRes.camera->is_key_pressed(rKEY_GRAVE) && (!mainRes.console->is_active)) {
        mainRes.console->is_active = true;
    }
    

    // Selecting scene - right now with 1,2,3 keys
    // Checking if scene control is scene or console
    // TODO (ragnar): Move scene selection into a main menu Interface
   
    mainRes.camera->render();
    if (mainRes.console->is_active)
    {
        mainRes.console->process_input();
    }
    else 
    {
        mainRes.selectedScene->process_input();
        if (mainRes.camera->is_key_pressed(rKEY_ONE)) {
            mainRes.selectedScene = mainRes.sceneMainMenu;
            mainRes.camera->set_scene(SceneEnum::MAINMENU);
        }
        else if (mainRes.camera->is_key_pressed(rKEY_TWO)) {
            mainRes.camera->set_scene(SceneEnum::GAMESCENE);
            mainRes.selectedScene = mainRes.sceneGame;
        }
    }
    mainRes.selectedScene->simulate();
  }
  mainRes.camera->close_window();

  return 0;
}