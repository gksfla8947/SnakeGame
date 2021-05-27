#include<ncurses.h>
#include"Map.h"
using namespace std;

class GameScene {
  WINDOW *gameboard;
  WINDOW *scoreboard;
  WINDOW *missionboard;
public:
  GameScene();
  void InitWindow();
  void GameBoard();
  void ScoreBoard();
  void MissionBoard();
};
