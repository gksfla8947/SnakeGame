#include"Map.h"

Map::Map(int level) {
  this->mapUrl = "stage/stage" + to_string(level) + ".txt";
  map_txt.open(this->mapUrl);
  for(int i = 0; i < 2; i++){
    gate_X[i] = 0;
    gate_Y[i] = 0;
  }
}

Map::~Map(){
}

void Map::Init(){
  int map_height = 0;
  while (!map_txt.eof())
  {
    char temp[200];
    map_txt.getline(temp, 200);
    if(map_height == 0) {
      string tmp;
      for(int i = 0; i < 3; i++) {
        tmp += temp[i];
      }
      objLen = stoi(tmp);
    }
    else if(map_height == 1) {
      string tmp;
      for(int i = 0; i < 3; i++) {
        tmp += temp[i];
      }
      objGrowth = stoi(tmp);
    }
    else if(map_height == 2) {
      string tmp;
      for(int i = 0; i < 3; i++) {
        tmp += temp[i];
      }
      objReduce = stoi(tmp);
    }
    else if(map_height == 3) {
      string tmp;
      for(int i = 0; i < 3; i++) {
        tmp += temp[i];
      }
      objGate = stoi(tmp);
    }
    else {
      for (int i = 0; i < WIDTH; i++)
      {
        maps[map_height-4][i] = temp[i];
      }
    }
    map_height++;
  }
}

void Map::Render(WINDOW *board){
  init_pair(5, COLOR_WHITE, COLOR_WHITE);
  init_pair(2, COLOR_GREEN, COLOR_GREEN);
  init_pair(3, COLOR_RED, COLOR_RED);
  init_pair(4, COLOR_BLUE, COLOR_BLUE);
  init_pair(8, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(9, COLOR_MAGENTA, COLOR_MAGENTA);
  init_pair(7, COLOR_CYAN, COLOR_CYAN);
  init_pair(10, COLOR_BLACK, COLOR_BLACK);
  for(int i = 0; i < HEIGHT; i++){
    for(int j = 0; j < WIDTH; j++){
      //attron(COLOR_PAIR(maps[i][j]));
      switch (maps[i][j])
      {
        case '0':
          mvwaddch(board, i+1, j+1, ' ' | COLOR_PAIR(5)); // 공백
          break;
        case '1':
          mvwaddch(board, i+1, j+1, '#' | COLOR_PAIR(2)); // 벽
          break;
        case '2':
          mvwaddch(board, i+1, j+1, '@' | COLOR_PAIR(10)); // 벽
          break;
        case '4':
          mvwaddch(board, i+1, j+1, 'O' | COLOR_PAIR(3)); // 스네이크 머리
          break;
        case '3':
          mvwaddch(board, i+1, j+1, 'X' | COLOR_PAIR(4)); // 스네이크 몸
          break;
        case '5':
          mvwaddch(board, i+1, j+1, '^' | COLOR_PAIR(7)); // 게이트
          break;
        case '6':
          mvwaddch(board, i+1, j+1, 'G' | COLOR_PAIR(8)); // Growth item
          break;
        case '7':
          mvwaddch(board, i+1, j+1, 'L' | COLOR_PAIR(9)); // Loss item
          break;
      }
      //attroff(COLOR_PAIR(maps[i][j]));
    }
  }
  wrefresh(board);
}

void Map::Update(int x, int y, char value) {
  maps[x][y] = value;
}

void Map::make_item(){
  startT = time(NULL);

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

void Map::check_item() {
  nowT = time(NULL);

	if(nowT - startT > 5){  //5초 이상 지났을 경우
    for (int i=0; i<30; i++) {   //아이템의 위치 지움
      for (int j=0; j<110; j++) {
        if (maps[i][j]=='6' || maps[i][j]=='7') maps[i][j]='0';
      }
    }
		make_item();
	}
}

void Map::set_Gatepos(){
  gate_startT = time(NULL);

  srand(time(NULL));
  int x = 0;
  int y = 0;
  int gateCount = 0;
  while(gateCount < 2){
    x = rand() % WIDTH;
    y = rand() % HEIGHT;
    if(maps[y][x] == '1'){
      maps[y][x] = '5';
      gate_X[gateCount] = x;
      gate_Y[gateCount] = y;
      gateCount++;
    }
  }
}

void Map::GateUpdate(){
  gate_nowT = time(NULL);
  if(nowT - startT > 4) {
    for (int i=0; i<30; i++) {  
      for (int j=0; j<110; j++) {
        if (maps[i][j]=='5') maps[i][j]='1';
      }
    }
    set_Gatepos();
	}
}
