#include<ncurses.h>
#include<vector>
#include<utility>
#include<cstring>
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
  void init_snake_pos(int x = 1, int y = 1);
  void move(int ch, Gate gate);
  bool isDead();
  void Collision(char type, Gate gate);

  void Render();

  void Growth();
  void Reduce();

  string getCurLen() { return to_string(size); }
  string getMaxLen() { return to_string(maxSize); }
  string getGrowthNum() { return to_string(growthNum); }
  string getReduceNum() { return to_string(reduceNum); }
  string getGateNum() { return to_string(gateNum); }
};
