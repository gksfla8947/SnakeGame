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

void Map::Render(WINDOW *map){
  init_pair(5, COLOR_WHITE, COLOR_WHITE);
  init_pair(2, COLOR_GREEN, COLOR_GREEN);
  init_pair(3, COLOR_RED, COLOR_RED);
  init_pair(4, COLOR_BLUE, COLOR_BLUE);
  for(int i = 0; i < HEIGHT; i++){
    for(int j = 0; j < WIDTH; j++){
      //attron(COLOR_PAIR(maps[i][j]));
      switch (maps[i][j])
      {
        case '0':
          mvwaddch(map, i+1, j+1, ' ' | COLOR_PAIR(5));
          break;
        case '1':
          mvwaddch(map, i+1, j+1, '#' | COLOR_PAIR(2));
          break;
        case '2':
          mvwaddch(map, i+1, j+1, '@' | COLOR_PAIR(2));
          break;
        case '4':
          mvwaddch(map, i+1, j+1, 'O' | COLOR_PAIR(3));
          break;
        case '3':
          mvwaddch(map, i+1, j+1, 'X' | COLOR_PAIR(4));
          break;
        case '5':
          mvwaddch(map, i+1, j+1, '^' | COLOR_PAIR(7));
          break;
      }
      //attroff(COLOR_PAIR(maps[i][j]));
    }
  }
  wrefresh(map);
}

void Map::Update(int x, int y, char value) {
  maps[x][y] = value;
}
