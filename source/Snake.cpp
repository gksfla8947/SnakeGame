#include"Snake.h"

Snake::Snake(int bodyNum) {
  size = bodyNum + 1;
  direction = 'r';
}

// 스네이크의 생성위치(x, y값은 1부터 시작) 설정
void Snake::init_snake_pos(Map& stage, int x, int y) {
  for(int i = 1; i < snake.size(); i++) {
    if(stage.maps[x][y-i] == 1) {
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

  stage.Update(snake[0].first, snake[0].second, '4');
  for(int i = 1; i < size; i++) {
    stage.Update(snake[i].first, snake[i].second, '3');
  }
}

void Snake::move(Map& stage, int ch) {
  stage.Update(snake[size-1].first, snake[size-1].second, '0');
  for(int i = size-1; i > 0; i--) {
    snake[i].first = snake[i-1].first;
    snake[i].second = snake[i-1].second;
  }
  switch (ch) {
    case KEY_LEFT:
      if(direction != 'r') {
        direction = 'l';
        headPosY -= 1;
      }
      break;
    case KEY_RIGHT:
      if(direction != 'l') {
        direction = 'r';
        headPosY += 1;
      }
      break;
    case KEY_UP:
      if(direction != 'd') {
        direction = 'u';
        headPosX -= 1;
      }
      break;
    case KEY_DOWN:
      if(direction != 'u') {
        direction = 'd';
        headPosX += 1;
      }
      break;
  }
  snake[0].first = headPosX;
  snake[0].second = headPosY;

  stage.Update(snake[0].first, snake[0].second, '4');
  for(int i = 1; i < size; i++) {
    stage.Update(snake[i].first, snake[i].second, '3');
  }
}
