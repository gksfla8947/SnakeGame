#include<ncurses.h>
#include<vector>
#include<utility>
#include"Map.h"
using namespace std;

class Snake {
  vector<pair<int, int>> snake;
  int size;
  char direction;
  int headPosX, headPosY;
  int tailPosX, tailPosY;
public:
  Snake(int bodyNum);
  void init_snake_pos(Map& stage, int x = 1, int y = 1);
  void move(Map& stage, int ch);
};
