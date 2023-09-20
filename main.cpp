#include "main.h"
#include "submodules/network/src/host.h"

rawData_t networkData = { 0 };
HANDLE networkThreadHandle;

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
  Console* console = new Console();
  camera->register_scene(sceneGame);
  camera->register_scene(sceneMainMenu);
  camera->register_console(console);
  camera->set_scene(SceneEnum::MAINMENU);

  // Init render control values here
  bool dropdown_console = false;

  // Console initialization
  
  // Start scene is main menu
  selectedScene = sceneMainMenu;
  int gownooo = 0;
  HostNetwork* network = new HostNetwork(&gownooo,"10667");

  network->start_thread();
 
  while (!camera->should_window_close()) {
      network->receive_data(&networkData);
      std::cout << "network data:  " << (networkData.dataLength) << std::endl;
    // Checking if rendering of dropdown-console
    // This is not blockable by console input control
      
    if ((camera->is_key_pressed(rKEY_GRAVE)) && (console->is_active)) {
        console->is_active = false;

      // Clearing command
      console->clear_cmd_buf();

    } else if (camera->is_key_pressed(rKEY_GRAVE) && (!console->is_active)) {
        console->is_active = true;
    }
    

    // Selecting scene - right now with 1,2,3 keys
    // Checking if scene control is scene or console
    // TODO (ragnar): Move scene selection into a main menu Interface
   
    camera->render();
    if (console->is_active) 
    {
        console->process_input();
    }
    else 
    {
        selectedScene->process_input();
        if (camera->is_key_pressed(rKEY_ONE)) {
            selectedScene = sceneMainMenu;
            camera->set_scene(SceneEnum::MAINMENU);
        }
        else if (camera->is_key_pressed(rKEY_TWO)) {
            camera->set_scene(SceneEnum::GAMESCENE);
            selectedScene = sceneGame;
        }
    }
    selectedScene->simulate();
    
  }

  camera->close_window();

  return 0;
}

