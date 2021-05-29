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
  Gate gate;
public:
  GameScene();
  void InitWindow();
  void InitGameboard();
  void InitScoreboard();
  void InitMissionboard();

  void Run();
  void GameOver();

  void UpdateGameBoard();
  void UpdateScoreBoard();
  void UpdateMissionBoard();

  char *to_char(string s);
};
