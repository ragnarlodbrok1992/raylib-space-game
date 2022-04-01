#include "SceneMainMenu.h"


SceneMainMenu::SceneMainMenu(SceneEnum se) : Scene(se) {

};

SceneMainMenu::~SceneMainMenu() {

};

void SceneMainMenu::process_input() {

}

void SceneMainMenu::render() {
  WriteMessage("SceneMainMenu is here!", 20, 20);
};

void SceneMainMenu::simulate() {

};
