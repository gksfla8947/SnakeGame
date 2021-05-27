#include<ncurses.h>
#include<iostream>
#include<string>
#include<vector>
#include"StartScene.h"
#include"GameScene.h"
using namespace std;

class SnakeGame {
  bool isOver;
  StartScene *intro;
  GameScene *inGame;
public:
  SnakeGame();
  void startGame();
};
