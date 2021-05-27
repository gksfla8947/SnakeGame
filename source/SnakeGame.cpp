#include"SnakeGame.h"

SnakeGame::SnakeGame() {
  intro = new StartScene();
  inGame = new GameScene();
}
void SnakeGame::startGame() {
  intro->Draw();
  inGame->InitWindow();
}
