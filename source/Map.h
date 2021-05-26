#include<ncurses.h>
using namespace std;

class Map {
  int level;
  int row;
  int col;
  int **map;
public:
  Map(int rows, int cols);
  void print(WINDOW *win);
  int** getMap() { return map; }
  void setMap(int x, int y, int value) { map[x][y] = value; }
};
