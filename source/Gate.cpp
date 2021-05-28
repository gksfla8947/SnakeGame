#include"Gate.h"

Gate::Gate(){

}

Gate::~Gate(){

}

void Gate::Init(){
  // gateX[2] = {0, 0};
  // gateY[2] = {0, 0};
}

void Gate::Update(){

}

void Gate::set_Gatepos(Map& map){
  srand((unsigned)time(NULL));
  int x = 0;
  int y = 0;
  int gateCount = 0;
  while(1){
    x = rand() % WIDTH;
    y = rand() % HEIGHT;
    if(map.maps[y][x] != '5' && map.maps[y][x] != '2'){
      map.maps[y][x] = '5';
      // gateX[gateCount] = x;
      // gateY[gateCount] = y;
      gateCount++;
    }
    if(gateCount > 1){
      break;
    }
  }
}
