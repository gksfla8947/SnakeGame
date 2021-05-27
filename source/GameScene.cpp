#include"GameScene.h"

GameScene::GameScene() {
  initscr();
  start_color();
  curs_set(false);
  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  gameboard = newwin(LINES, COLS/2+40, 0, 0);
  scoreboard = newwin(LINES/2, COLS/2-40, 0, COLS/2+40);
  missionboard = newwin(LINES/2, COLS/2-40, LINES/2, COLS/2+40);
}

void GameScene::InitWindow() {
  GameBoard();
  ScoreBoard();
  MissionBoard();

  wrefresh(gameboard);
  wrefresh(scoreboard);
  wrefresh(missionboard);

  getch();
  Map *mymap = new Map();
  mymap->Init();
  mymap->Render(gameboard);
  getch();
  delwin(gameboard);
  delwin(scoreboard);
  delwin(missionboard);
  endwin();
}

void GameScene::GameBoard(){
  int row, col;
  getmaxyx(gameboard, row, col);
  box(gameboard, 0, 0);
  attron(COLOR_PAIR(1));
  wbkgd(gameboard, COLOR_PAIR(1));
  mvwprintw(gameboard, 0, col/2-col/10, "GAME");
}

void GameScene::ScoreBoard() {
  int row, col;
  getmaxyx(scoreboard, row, col);
  box(scoreboard, 0, 0);
  attron(COLOR_PAIR(1));
  wbkgd(scoreboard, COLOR_PAIR(1));
  mvwprintw(scoreboard, 0, col/2-col/5, "SCORE BOARD");
  mvwprintw(scoreboard, 2, 2, "B : ");
  mvwprintw(scoreboard, 4, 2, "+ : ");
  mvwprintw(scoreboard, 6, 2, "- : ");
  mvwprintw(scoreboard, 8, 2, "G : ");
}

void GameScene::MissionBoard() {
  int row, col;
  getmaxyx(missionboard, row, col);
  box(missionboard, 0, 0);
  attron(COLOR_PAIR(1));
  wbkgd(missionboard, COLOR_PAIR(1));
  mvwprintw(missionboard, 0, col/2-col/5, "MISSION BOARD");
  mvwprintw(missionboard, 2, 2, "B : 10 (v)");
  mvwprintw(missionboard, 4, 2, "+ : 5  ( )");
  mvwprintw(missionboard, 6, 2, "- : 2  ( )");
  mvwprintw(missionboard, 8, 2, "G : 1  (v)");
}