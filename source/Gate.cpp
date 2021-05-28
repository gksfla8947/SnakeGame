#include"Gate.h"

Gate::Gate(){
}

Gate::~Gate(){

}

void Gate::Init(){
  for(int i = 0; i < 2; i++){
    gate_X[i] = 0;
    gate_Y[i] = 0;
  }
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
    if(map.maps[y][x] == '1'){
      map.maps[y][x] = '5';
      gate_X[gateCount] = x;
      gate_Y[gateCount] = y;
      gateCount++;
    }
    if(gateCount > 1){
      break;
    }
  }
}
