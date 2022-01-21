#include "raylib.h"
#include "Scene.h"

// TEMP includes
#include <iostream>

void Scene::render() {
  // TEMP debug shit - remove before pushing
  std::cout << "I am rendering scene " << SceneEnumToString(this->scene) << "\n";
}

void Scene::simulate() {
  // TEMP debug shit - remove before pushing
  std::cout << "I am simulating scene " << SceneEnumToString(this->scene) << "\n";
}

Scene::Scene(SceneEnum se) {
  this->scene = se;
}

Scene::~Scene() {

}
