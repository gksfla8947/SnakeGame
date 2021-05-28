#include<ncurses.h>
#include<vector>
#include<utility>
#include"Gate.h"
using namespace std;

class Snake {
  vector<pair<int, int> > snake;
  int size;
  char direction;
  int headPosX, headPosY;
  int tailPosX, tailPosY;
  bool dead;
  Map *stage;
public:
  Snake(Map& map, int bodyNum);
  void init_snake_pos(int x = 1, int y = 1);
  void move(int ch);
  bool isDead();
  void Collision(char type);
};
