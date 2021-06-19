#include<ncurses.h>
#include<string>
#include<fstream>
#include<iostream>
#include<ctime>
#include<map>
#include<cstdlib>

/*
* @author 김한림(20203055) 김영광(20203042) 이다은(20203112)
*/

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
  time_t nowT;
  time_t startT;

  int gate_X[2];
  int gate_Y[2];
  time_t gate_nowT;
  time_t gate_startT;

  Map(int level); // 김영광
  ~Map();

  void Init(); // 김영광 김한림
  void Render(WINDOW *map); // 김영광 김한림
  void Update(int x, int y, char value); // 김한림
  void make_item(); // 이다은
  void check_item(); // 이다은

  void GateUpdate(); // 김한림
  void set_Gatepos(); // 김영광 김한림

  // 게터: 김한림
  int getObjLen() { return objLen; }
  int getObjGrowth() { return objGrowth; }
  int getObjReduce() { return objReduce; }
  int getObjGate() { return objGate; }

};
