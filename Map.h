#include<ncurses.h>
#include<string>
#include<fstream>

using namespace std;

#define HEIGHT 21
#define WIDTH 21

class Map{
public:
  ifstream map_txt;
  char maps[HEIGHT][WIDTH];

  Map();
  ~Map();

  void Init();
  void Update(WINDOW *tmp);

};
