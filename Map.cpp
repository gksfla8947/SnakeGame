#include"Map.h"

Map::Map(){

}

Map::~Map(){

}

void Map::Init(){
  map_txt.open("stage/stage1.txt");

  int map_height = 0;
  while (!map_txt.eof())
  {
    char temp[100];
    map_txt.getline(temp, 100);
    for (int i = 0; i < WIDTH; i++)
    {
        maps[map_height][i] = temp[i];
    }
    map_height++;
  }
}

void Map::Update(WINDOW *tmp){
  for(int i = 0; i < HEIGHT; i++){
    for(int j = 0; j < WIDTH; j++){
      //attron(COLOR_PAIR(maps[i][j]));
      switch (maps[i][j])
      {
        case '0':
          mvwaddch(tmp, i+1, j+1, ' ');
          break;
        case '1':
          mvwaddch(tmp, i+1, j+1, '-');
          break;
        case '2':
          mvwaddch(tmp, i+1, j+1, 'X');
          break;
      }
      //attroff(COLOR_PAIR(maps[i][j]));
    }
  }
}
