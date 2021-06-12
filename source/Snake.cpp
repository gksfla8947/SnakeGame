#include"Snake.h"

Snake::Snake(Map &map, int bodyNum) {
  stage = &map;
  size = bodyNum + 1;
  maxSize = size;
  direction = 'r';
  dead = false;
  growthNum = 0;
  gateNum = 0;
  reduceNum = 0;
}

Snake::~Snake() {
  delete stage;
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
    usleep(100000);
  }
  else if(direction == 'r') {
    headPosY += 1;
    usleep(100000);
  }
  else if(direction == 'u') {
    headPosX -= 1;
    usleep(200000);
  }
  else if(direction == 'd') {
    headPosX += 1;
    usleep(200000);
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
    gateNum += 1;
    int gx, gy;
    bool isup, isdown, isleft, isright;
    if(headPosY == gate.gate_X[0] && headPosX == gate.gate_Y[0]){
      gx = gate.gate_X[1];
      gy = gate.gate_Y[1];
    }
    else{
      gx = gate.gate_X[0];
      gy = gate.gate_Y[0];
    }

    isup = (stage->maps[gy+1][gx] == '0' || stage->maps[gy+1][gx] == '6' || stage->maps[gy+1][gx] == '7');
    isdown = (stage->maps[gy-1][gx] == '0' || stage->maps[gy-1][gx] == '6' || stage->maps[gy-1][gx] == '7');
    isleft = (stage->maps[gy][gx-1] == '0' || stage->maps[gy][gx-1] == '6' || stage->maps[gy][gx-1] == '7');
    isright = (stage->maps[gy][gx+1] == '0' || stage->maps[gy][gx+1] == '6' || stage->maps[gy][gx+1] == '7');
    if(gx == 0){
      changeDirection('r', gx, gy);
    }
    else if(gx == WIDTH-1){
      changeDirection('l', gx, gy);
    }
    else if(gy == 0){
      changeDirection('d', gx, gy);
    }
    else if(gy == HEIGHT-1){
      changeDirection('u', gx, gy);
    }
    else{
      if(isright){ //right
        if(isleft){ //left
          if(isup){ //up
            if(direction == 'u' || direction == 'd'){
              changeDirection('u', gx, gy);
            }
            else{
              changeDirection(direction, gx, gy);
            }
          }
          else if(isdown){ //down
            if(direction == 'u' || direction == 'd'){
              changeDirection('d', gx, gy);
            }
            else{
              changeDirection(direction, gx, gy);
            }
          }
          else{
            if(direction == 'r'){
              changeDirection(direction, gx, gy);
            }
            else{
              changeDirection('l', gx, gy);
            }
          }
        }
        else if(isup){ //up
          if(direction == 'r' || direction == 'l'){
            changeDirection('r', gx, gy);
          }
          else{
            changeDirection('u', gx, gy);
          }
        }
        else if(isdown){ //down
          if(direction == 'r' || direction == 'l'){
            changeDirection('r', gx, gy);
          }
          else{
            changeDirection('d', gx, gy);
          }
        }
        else{
          changeDirection('r', gx, gy);
        }
      }
      else if(isup){ //up
        if(isdown){ //down
          if(isleft){
            if(direction == 'r' || direction == 'l'){
              changeDirection('l', gx, gy);
            }
            else{
              changeDirection(direction, gx, gy);
            }
          }
          else if(isright){
            if(direction == 'r' || direction == 'l'){
              changeDirection('r', gx, gy);
            }
            else{
              changeDirection(direction, gx, gy);
            }
          }
          else{
            if(direction == 'r' || direction == 'u'){
              changeDirection('u', gx, gy);
            }
            else{
              changeDirection('d', gx, gy);
            }
          }
        }
        else if(isleft){ //left
          if(direction == 'r' || direction == 'l'){
            changeDirection('l', gx, gy);
          }
          else{
            changeDirection('u', gx, gy);
          }
        }
        else{
          changeDirection('u', gx, gy);
        }
      }
      else if(isleft){ //left
        if(isdown){ //down
          if(direction == 'r' || direction == 'l'){
            changeDirection('l', gx, gy);
          }
          else{
            changeDirection('d', gx, gy);
          }
        }
        else{
          changeDirection('l', gx, gy);
        }
      }
      else{
        changeDirection('d', gx, gy);
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
  if(size > maxSize)
    maxSize += 1;
  growthNum += 1;
}

void Snake::Reduce() {
  snake.pop_back();
  stage->Update(tailPosX, tailPosY, '0');
  tailPosX = snake[size-1].first;
  tailPosY = snake[size-1].second;
  size-=1;
  reduceNum += 1;
}

void Snake::changeDirection(char directions, int gx1, int gy1){
  if(directions == 'u'){
    headPosY = gx1;
    headPosX = gy1 - 1;
    direction = 'u';
  }
  else if(directions == 'd'){
    headPosY = gx1;
    headPosX = gy1 + 1;
    direction = 'd';
  }
  else if(directions == 'l'){
    headPosY = gx1 - 1;
    headPosX = gy1;
    direction = 'l';
  }
  else if(directions == 'r'){
    headPosY = gx1 + 1;
    headPosX = gy1;
    direction = 'r';
  }
}
