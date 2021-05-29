#include<ncurses.h>
#include<iostream>
#include<string>
#include<vector>
#include"StartScene.h"
#include"GameScene.h"
#include"GameoverScene.h"
#include"GameclearScene.h"
#include"EndScene.h"
using namespace std;

class SnakeGame {
  bool isOver;
  StartScene *intro;
  GameScene *inGame;
  GameoverScene *overScene;
  GameclearScene *clearScene;
  EndScene *endScene;
  int curLevel = 1;
  int objLevel;
public:
  SnakeGame(int objLevel);
  void startGame();
};
