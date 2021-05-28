#include"Map.h"

Map::Map(){

}

Map::~Map(){

}

void Map::make_item(){
  srand(time(NULL));
  int num = 0;  //현재 아이템의 개수
  int growth_Item = rand() % 3;  //Growth Item 개수
  int grow_num = 0;  //현재 Growth Item 개수
  int tmpx, tmpy;    //좌표

  while(num<3){ //동시에 나타날 수 있는 아이템의 최대수:3
    tmpx = rand()%WIDTH;  //실행할때마다 좌표값 달라짐
    tmpy = rand()%HEIGHT;

    if(maps[tmpy][tmpx] != '0')
      continue;

    /*for (int i=0; i<snake.size(); i++)  //아이템의 위치가 스네이크 body의 위치일 경우
      if (snake[i].x == tmpx && snake[i].y == tmpy) continue;*/

    if (grow_num < growth_Item) {   //Growth Item생성
      maps[tmpy][tmpx] = '6';
      num++;
      grow_num++;
      continue;
    }

    //Poison Item 생성
    maps[tmpy][tmpx] = '7';
    num++;
  }
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
  init_pair(8, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(9, COLOR_MAGENTA, COLOR_MAGENTA);
  for(int i = 0; i < HEIGHT; i++){
    for(int j = 0; j < WIDTH; j++){
      //attron(COLOR_PAIR(maps[i][j]));
      switch (maps[i][j])
      {
        case '0':
          mvwaddch(map, i+1, j+1, ' ' | COLOR_PAIR(5)); // 공백
          break;
        case '1':
          mvwaddch(map, i+1, j+1, '#' | COLOR_PAIR(2)); // 벽
          break;
        case '2':
          mvwaddch(map, i+1, j+1, '@' | COLOR_PAIR(2)); // 벽
          break;
        case '4':
          mvwaddch(map, i+1, j+1, 'O' | COLOR_PAIR(3)); // 스네이크 머리
          break;
        case '3':
          mvwaddch(map, i+1, j+1, 'X' | COLOR_PAIR(4)); // 스네이크 몸
          break;
        case '5':
          mvwaddch(map, i+1, j+1, '^' | COLOR_PAIR(7)); // 게이트
          break;
        case '6':
          mvwaddch(map, i+1, j+1, 'G' | COLOR_PAIR(8)); // Growth item
          break;
        case '7':
          mvwaddch(map, i+1, j+1, 'L' | COLOR_PAIR(9)); // Loss item
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
