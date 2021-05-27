#include"SceneManager.h"

SceneManger::SceneManger() {
}

void SceneManger::addScene(const Scene& scene, string name) {
  scenes[name] = scene;
}

void SceneManger::delScene(string name) {
  scenes.erase(name);
}

void SceneManger::showScene(string name) {

}
