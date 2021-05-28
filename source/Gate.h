#include<ncurses.h>
#include<string>
#include<fstream>
#include <ctime>
#include<cstdlib>
#include"Map.h"

using namespace std;

class Gate{
public:
  int gateX[2];
  int gateY[2];
  Gate();
  ~Gate();

  void Init();
  void Update();
  void set_Gatepos(Map& map);
};
