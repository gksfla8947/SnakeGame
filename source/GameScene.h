#include<ncurses.h>
#include<iostream>
#include<unistd.h>
#include"Snake.h"
using namespace std;

class GameScene {
  WINDOW *gameboard;
  WINDOW *scoreboard;
  WINDOW *missionboard;
  Map *stage;
  Snake *player;
  Gate *gate;
public:
  GameScene();
  void InitWindow();
  void Run();
  void GameOver();

  void GameBoard();
  void ScoreBoard();
  void MissionBoard();
};
