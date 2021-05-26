#include"Snake.h"

Snake::Snake(int bodyNum) {
  snake[0] = 4;
  for(int i = 0; i < bodyNum; i++) snake.push_back(3);
}
void Snake::init_snake_pos(Map& stage, int x, int y) {
  for(int i = 1; i < snake.size(); i++) {
    if(stage.map[x][y-i] == 1) {
      cout << "Initialized snake pos is out of range";
      return;
    }
  }
  posX = x;
  posY = y;
  stage.map[x][y] = snake[0];
  for(int i = 1; i <= snake.size(); i++) stage.map[x][y-i] = snake[i];
}
void Snake::move(Map& stage, int ch) {

}
