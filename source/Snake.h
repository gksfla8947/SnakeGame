#include<ncurses.h>
#include<vector>
#include<utility>
#include<cstring>
#include<unistd.h>
#include"Gate.h"
using namespace std;

class Snake {
  vector<pair<int, int> > snake;
  int size;
  int maxSize;
  int growthNum;
  int reduceNum;
  int gateNum;
  char direction;
  int headPosX, headPosY;
  int tailPosX, tailPosY;
  bool dead;
  Map *stage;
public:
  Snake(Map& map, int bodyNum);
  ~Snake();
  void init_snake_pos(int x = 1, int y = 1);
  void move(int ch, Gate gate);
  bool isDead();
  void Collision(char type, Gate gate);
  void changeDirection(char directions, int gx1, int gy1);

  void Render();

  void Growth();
  void Reduce();

  int getCurLen() { return size; }
  int getMaxLen() { return maxSize; }
  int getGrowthNum() { return growthNum; }
  int getReduceNum() { return reduceNum; }
  int getGateNum() { return gateNum; }
};
