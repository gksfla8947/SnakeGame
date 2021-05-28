#include"Map.h"
#include<ctime>
#include<cstdlib>

class Gate{
public:
  int gate_X[2];
  int gate_Y[2];
  Gate();
  ~Gate();

  void Init();
  void Update();
  void set_Gatepos(Map& map);
};
