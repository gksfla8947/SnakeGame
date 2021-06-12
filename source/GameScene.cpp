#include"GameScene.h"

GameScene::GameScene(int level) {
  gameboard = newwin(LINES, COLS/2+40, 0, 0);
  scoreboard = newwin(LINES/2, COLS/2-40, 0, COLS/2+40);
  missionboard = newwin(LINES/2, COLS/2-40, LINES/2, COLS/2+40);
  stage = new Map(level);
  stage->Init();
  player = new Snake(*stage, 5);
  gate.Init();
  isClear = false;
  player->init_snake_pos(1, 7);
}

GameScene::~GameScene() {
}

void GameScene::InitWindow() {
  initscr();
  start_color();
  curs_set(false);
  noecho();
  cbreak();
  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  InitGameboard();
  InitScoreboard();
  InitMissionboard();
  UpdateGameBoard();
  UpdateScoreBoard();
  UpdateMissionBoard();
  gate.set_Gatepos(*stage);
  stage->make_item();  //시작할 때 아이템 배치
  nodelay(gameboard, TRUE);
}

void GameScene::Run() {
  InitWindow();
  while(true) {
    int ch = wgetch(gameboard);
    if(ch == KEY_F(1)) break;
    player->move(ch, gate);
    UpdateGameBoard();
    UpdateScoreBoard();
    UpdateMissionBoard();
    ///추가된 부분
    stage->check_item();  //5초 이상 지났는지 체크해서
    stage->Render(gameboard);   //아이템 재배치
    //////
    if(checkClear()) {
      isClear = true;
      break;
    }
    else if(player->isDead()) break;
  }
  endwin();
}

void GameScene::GameOver() {
  stage->Init();
  stage->Render(gameboard);
}

void GameScene::InitGameboard() {
  int row, col;
  getmaxyx(gameboard, row, col);
  box(gameboard, 0, 0);
  attron(COLOR_PAIR(1));
  wbkgd(gameboard, COLOR_PAIR(1));
  mvwprintw(gameboard, 0, col/2-col/10, "GAME");
  keypad(gameboard, true);
}

void GameScene::InitScoreboard() {
  int row, col;
  getmaxyx(scoreboard, row, col);
  box(scoreboard, 0, 0);
  attron(COLOR_PAIR(1));
  wbkgd(scoreboard, COLOR_PAIR(1));
  mvwprintw(scoreboard, 0, col/2-col/5, "SCORE BOARD");
  mvwprintw(scoreboard, 2, 2, "B : 6");
  mvwprintw(scoreboard, 4, 2, "+ : 0");
  mvwprintw(scoreboard, 6, 2, "- : 0");
  mvwprintw(scoreboard, 8, 2, "G : 0");
}

void GameScene::InitMissionboard() {
  int row, col;
  getmaxyx(missionboard, row, col);
  box(missionboard, 0, 0);
  attron(COLOR_PAIR(1));
  wbkgd(missionboard, COLOR_PAIR(1));
  mvwprintw(missionboard, 0, col/2-col/5, "MISSION BOARD");
}

void GameScene::UpdateGameBoard(){
  stage->Render(gameboard);
}

void GameScene::UpdateScoreBoard() {
  mvwprintw(scoreboard, 2, 6, to_char(to_string(player->getCurLen()) + "/" + to_string(player->getMaxLen())));
  mvwprintw(scoreboard, 4, 6, to_char(to_string(player->getGrowthNum())));
  mvwprintw(scoreboard, 6, 6, to_char(to_string(player->getReduceNum())));
  mvwprintw(scoreboard, 8, 6, to_char(to_string(player->getGateNum())));
  wrefresh(scoreboard);
}

void GameScene::UpdateMissionBoard() {
  string bm = "B : " + to_string(stage->getObjLen()) + isAchieve(player->getCurLen(), stage->getObjLen());
  string gm = "+ : " + to_string(stage->getObjGrowth()) + isAchieve(player->getGrowthNum(), stage->getObjGrowth());
  string rm = "- : " + to_string(stage->getObjReduce()) + isAchieve(player->getReduceNum(), stage->getObjReduce());
  string gam = "G : " + to_string(stage->getObjGate()) + isAchieve(player->getGateNum(), stage->getObjGate());
  mvwprintw(missionboard, 2, 2, to_char(bm));
  mvwprintw(missionboard, 4, 2, to_char(gm));
  mvwprintw(missionboard, 6, 2, to_char(rm));
  mvwprintw(missionboard, 8, 2, to_char(gam));
  wrefresh(missionboard);
}

char *GameScene::to_char(string s) {
  char *tmp = new char[100];
  strcpy(tmp, s.c_str());
  return tmp;
}

string GameScene::isAchieve(int cur, int goal) {
  string res = "";
  if(cur >= goal) {
    res = "(v)";
  }
  else {
    res = "( )";
  }
  return res;
}

bool GameScene::checkClear() {
  if(player->getCurLen() >= stage->getObjLen() && player->getGrowthNum() >= stage->getObjGrowth() && player->getReduceNum() >= stage->getObjReduce() && player->getGateNum() >= stage->getObjGate()) {
    return true;
  }
  else {
    return false;
  }
}
