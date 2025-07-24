#include "include/SceneMainMenu.h"


SceneMainMenu::SceneMainMenu(){
  this->scene = SceneEnum::MAINMENU;
};

SceneMainMenu::~SceneMainMenu() {

};

void SceneMainMenu::process_input() {

}

void SceneMainMenu::process_mouse() {

}

void SceneMainMenu::prepare_scene() {
	HideCursor();
}

void SceneMainMenu::render() {
  WriteMessage("SceneMainMenu is here!", 20, 20);
};

void SceneMainMenu::simulate() {

};

void SceneMainMenu::render_cursor() {

};
