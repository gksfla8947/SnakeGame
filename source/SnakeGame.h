#include<ncurses.h>
#include<iostream>
#include<string>
#include<vector>
#include"Map.h"
using namespace std;

class SnakeGame {
  int stagesNumber;
  bool isOver;
public:
  SnakeGame(int numOfStages);
  void startGame();
  void temp();
};
