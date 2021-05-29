#include<ncurses.h>
#include<string>
#include<fstream>
#include<iostream>
#include<ctime>
#include<map>
#include<cstdlib>

using namespace std;

#define WIDTH 110
#define HEIGHT 30

class Map{
  int objLen;
  int objGrowth;
  int objReduce;
  int objGate;
  string mapUrl;
public:
  ifstream map_txt;
  char maps[HEIGHT][WIDTH];

  Map(int level);
  ~Map();

  void Init();
  void Render(WINDOW *map);
  void Update(int x, int y, char value);
  void make_item();

  int getObjLen() { return objLen; }
  int getObjGrowth() { return objGrowth; }
  int getObjReduce() { return objReduce; }
  int getObjGate() { return objGate; }
};
