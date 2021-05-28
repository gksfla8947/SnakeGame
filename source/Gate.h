#include<ncurses.h>
#include<string>
#include<fstream>
#include <ctime>
#include<cstdlib>
#include"Map.h"

using namespace std;

class Gate{
  int gateX[2];
  int gateY[2];
public:
  Gate();
  ~Gate();

  void Init();
  void Update();
  void set_Gatepos(Map& map);
};
