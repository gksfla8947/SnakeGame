#include"SnakeGame.h"

SnakeGame::SnakeGame() {
  intro = new StartScene();
  inGame = new GameScene();
  endScene = new GameoverScene();
}
void SnakeGame::startGame() {
  intro->Draw();
  inGame->Run();
  endScene->Draw();
}
