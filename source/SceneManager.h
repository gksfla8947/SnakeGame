#include<string>
#include<map>
#include<ncurses.h>
#include"Scene.h"
using namespace std;

class SceneManger {
  map<string, Scene> scenes;
public:
  SceneManger();
  void addScene(Scene scene, string name);
  void delScene(string name);
  void showScene(string name);
  void updateScene(string name);
};
