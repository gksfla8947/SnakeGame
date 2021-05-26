#include<ncurses.h>
#include<vector>
using namespace std;

class Snake {
  vector<int> snake;
  int posX, posY;
public:
  Snake(int bodyNum);
  void init_snake_pos(Map& stage, int x, int y);
  void move(Map& stage, int ch);
};
