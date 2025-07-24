#include "include/SceneEditor.h"

SceneEditor :: SceneEditor() {
  this->scene = SceneEnum::EDITOR;
};

SceneEditor::~SceneEditor() {

};

void SceneEditor::process_input() {

}

void SceneEditor::process_mouse() {

}

void SceneEditor::render() {
  WriteMessage("SceneEditor is here!", 20, 20);
};

void SceneEditor::simulate() {
  
};

void SceneEditor::prepare_scene() {
}

void SceneEditor::render_cursor() {

}
