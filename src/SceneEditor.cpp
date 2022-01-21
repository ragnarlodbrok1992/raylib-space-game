#include "SceneEditor.h"

SceneEditor :: SceneEditor(SceneEnum se) : Scene(se) {

};

SceneEditor::~SceneEditor() {

};

void SceneEditor::render() {
  WriteMessage("SceneEditor is here!", 20, 20);
};

void SceneEditor::simulate() {
  
};

