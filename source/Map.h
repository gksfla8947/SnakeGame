#include<ncurses.h>
#include<string>
#include<fstream>
#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

#define HEIGHT 21
#define WIDTH 21

class Map{
public:
  int objLen;
  int objGrowth;
  int objReduce;
  int objGate;
  ifstream map_txt;
  char maps[HEIGHT][WIDTH];

  Map(int objLen, int objGrowth, int objReduce, int objGate);
  ~Map();

  void Init();
  void Render(WINDOW *map);
  void Update(int x, int y, char value);
  void make_item();
};
