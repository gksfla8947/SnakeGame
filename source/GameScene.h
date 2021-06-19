#include<ncurses.h>
#include<iostream>
#include<unistd.h>
#include"Snake.h"
using namespace std;

/*
* @author 김한림(20203055) 김영광() 이다은(20203112)
* Run함수 제외 김한림 구현
*/

class GameScene {
  WINDOW *gameboard;
  WINDOW *scoreboard;
  WINDOW *missionboard;
  Map *stage;
  Snake *player;
public:
  bool isClear;

  GameScene(int level);
  ~GameScene();
  void InitWindow();
  void InitGameboard();
  void InitScoreboard();
  void InitMissionboard();

  void Run(); // 김한림, 김영광 공동작업
  void GameOver();

  void UpdateGameBoard();
  void UpdateScoreBoard();
  void UpdateMissionBoard();

  char *to_char(string s);

  string isAchieve(int cur, int goal);

  bool checkClear();
};
