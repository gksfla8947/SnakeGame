#include"SnakeGame.h"

SnakeGame::SnakeGame(int objLevel) {
  intro = new StartScene();
  endScene = new GameoverScene();
  this->objLevel = objLevel;
}
void SnakeGame::startGame() {
  intro->Draw();
  while(true) {
    inGame = new GameScene(curLevel);
    inGame->Run();
    if(inGame->isClear) {
      curLevel += 1;
      if(curLevel > objLevel) break;
    }
    endScene->Draw();
  }
  initscr();
  printw("The End");
  refresh();
  getch();
  endwin();
}
