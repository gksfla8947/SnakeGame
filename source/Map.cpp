#include"Map.h"

Map::Map() {
  row = rows;
  col = cols;

  map = new int* [rows];
  for(int i = 0; i < rows; i++) {
    map[i] = new int[cols];
    for(int j = 0; j < cols; j++) map[i][j] = 0;
  }
  map[0][0] = 2; map[0][cols-1] = 2; map[rows-1][0] = 2; map[rows-1][cols-1] = 2;
  for(int i = 1; i < rows-1; i++) map[i][0] = 1, map[i][cols-1] = 1;
  for(int i = 1; i < cols-1; i++) map[0][i] = 1, map[rows-1][i] = 1;
}

void Map::print(WINDOW *win) {
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      if(map[i][j] != 0) {
        if(map[i][j] == 4) mvwaddch(win, i+1, j+1, 'X');
        else if(map[i][j] == 3) mvwaddch(win, i+1, j+1, 'O');
        else mvwaddch(win, i+1, j+1, '#');
      }
    }
  }
}
