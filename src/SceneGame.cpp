#include "SceneGame.h"

SceneGame :: SceneGame(SceneEnum se) : Scene(se) {

};

SceneGame::~SceneGame() {

};

void SceneGame::render() {
  WriteMessage("SceneGame is here!", 20, 20);
};
void SceneGame::simulate() {

};
