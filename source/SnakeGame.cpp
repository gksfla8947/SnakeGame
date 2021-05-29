#include"SnakeGame.h"

SnakeGame::SnakeGame(int objLevel) {
  intro = new StartScene();
  clearScene = new GameclearScene();
  overScene = new GameoverScene();
  endScene = new EndScene();
  this->objLevel = objLevel;
}
void SnakeGame::startGame() {
  intro->Draw();
  while(true) {
    inGame = new GameScene(curLevel);
    inGame->Run();
    if(inGame->isClear) {
      clearScene->Draw();
      curLevel += 1;
      if(curLevel > objLevel) break;
    }
    else {
      overScene->Draw();
    }
  }
  endScene->Draw();
}
