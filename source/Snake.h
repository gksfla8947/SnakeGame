#include<ncurses.h>
#include<vector>
#include<utility>
#include<cstring>
#include<unistd.h>
#include<map>
#include"Map.h"
using namespace std;

/*
* @author 김한림(20203055) 김영광(20203042)
*/

class Snake {
  vector<pair<int, int> > snake;
  int size;
  int maxSize;
  int growthNum;
  int reduceNum;
  int gateNum;
  int cnt;
  char direction;
  int headPosX, headPosY;
  int tailPosX, tailPosY;
  bool dead;
  Map *stage;
public:
  bool inGate;
  Snake(Map& map, int bodyNum); // 김한림
  ~Snake();
  void init_snake_pos(int x = 1, int y = 1); // 김한림
  void move(int ch); // 김한림 김영광
  bool isDead(); // 김한림
  void Collision(char type); // 김한림, 김영광
  void changeDirection(char directions, int gx1, int gy1); // 김영광

  void Growth(); // 김한림
  void Reduce(); // 김한림 김영광

  // 게터: 김한림
  int getCurLen() { return size; }
  int getMaxLen() { return maxSize; }
  int getGrowthNum() { return growthNum; }
  int getReduceNum() { return reduceNum; }
  int getGateNum() { return gateNum; }
};
