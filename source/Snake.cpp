#include"Snake.h"

Snake::Snake(Map& map, int bodyNum) {
  size = bodyNum + 1;
  direction = 'r';
  dead = false;
  stage = &map;
}

// 스네이크의 생성위치(x, y값은 1부터 시작) 설정
void Snake::init_snake_pos(int x, int y) {
  for(int i = 1; i < snake.size(); i++) {
    if(stage->maps[x][y-i] == 1) {
      return;
    }
  }
  for(int i = 0; i < size; i++) {
    snake.push_back(make_pair(x, y-i));
  }
  headPosX = snake[0].first;
  headPosY = snake[0].second;
  tailPosX = snake[size-1].first;
  tailPosY = snake[size-1].second;

  stage->Update(snake[0].first, snake[0].second, '4');
  for(int i = 1; i < size; i++) {
    stage->Update(snake[i].first, snake[i].second, '3');
  }
}

void Snake::move(int ch, Gate gate) {
  for(int i = size-1; i > 0; i--) {
    snake[i].first = snake[i-1].first;
    snake[i].second = snake[i-1].second;
  }
  switch (ch) {
    case KEY_LEFT:
      if(direction != 'r') {
        direction = 'l';
      }
      else {
        dead = true;
        return;
      }
      break;
    case KEY_RIGHT:
      if(direction != 'l') {
        direction = 'r';
      }
      else {
        dead = true;
        return;
      }
      break;
    case KEY_UP:
      if(direction != 'd') {
        direction = 'u';
      }
      else {
        dead = true;
        return;
      }
      break;
    case KEY_DOWN:
      if(direction != 'u') {
        direction = 'd';
      }
      else {
        dead = true;
        return;
      }
      break;
  }
  if(direction == 'l') {
    headPosY -= 1;
  }
  else if(direction == 'r') {
    headPosY += 1;
  }
  else if(direction == 'u') {
    headPosX -= 1;
  }
  else if(direction == 'd') {
    headPosX += 1;
  }
  Collision(stage->maps[headPosX][headPosY], gate);
  if(!dead) {
    snake[0].first = headPosX;
    snake[0].second = headPosY;

    stage->Update(tailPosX, tailPosY, '0');
    tailPosX = snake[size-1].first;
    tailPosY = snake[size-1].second;
    stage->Update(headPosX, headPosY, '4');

    for(int i = 1; i < size; i++) {
      stage->Update(snake[i].first, snake[i].second, '3');
    }
  }
}

bool Snake::isDead() {
  return dead;
}

void Snake::Collision(char type, Gate gate) {
  if(type == '1' || type == '2' || type == '3') {
    dead = true;
  }
  else if(type == '5') {
    if(headPosY == gate.gate_X[0] && headPosX == gate.gate_Y[0]){
      if(gate.gate_X[1] == 0){
        headPosY = gate.gate_X[1] + 1;
        headPosX = gate.gate_Y[1];
      }
      else if(gate.gate_X[1] == WIDTH-1){
        headPosY = gate.gate_X[1] - 1;
        headPosX = gate.gate_Y[1];
      }
      else if(gate.gate_Y[1] == 0){
        headPosY = gate.gate_X[1];
        headPosX = gate.gate_Y[1] + 1;
      }
      else if(gate.gate_Y[1] == HEIGHT-1){
        headPosY = gate.gate_X[1];
        headPosX = gate.gate_Y[1] - 1;
      }
    }
    else{
      if(gate.gate_X[0] == 0){
        headPosY = gate.gate_X[0] + 1;
        headPosX = gate.gate_Y[0];
      }
      else if(gate.gate_X[0] == WIDTH-1){
        headPosY = gate.gate_X[0] - 1;
        headPosX = gate.gate_Y[0];
      }
      else if(gate.gate_Y[0] == 0){
        headPosY = gate.gate_X[0];
        headPosX = gate.gate_Y[0] + 1;
      }
      else if(gate.gate_Y[0] == HEIGHT-1){
        headPosY = gate.gate_X[0];
        headPosX = gate.gate_Y[0] - 1;
      }
    }
  }
  else if(type == '6') {
    Growth();
  }
  else if(type == '7') {
    Reduce();
  }
}

void Snake::Growth() {
  snake.push_back(make_pair(tailPosX, tailPosY));
  size+=1;
}

void Snake::Reduce() {
  snake.pop_back();
  stage->Update(tailPosX, tailPosY, '0');
  tailPosX = snake[size-1].first;
  tailPosY = snake[size-1].second;
  size-=1;
}
