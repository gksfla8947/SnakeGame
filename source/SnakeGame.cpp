#include"SnakeGame.h"

SnakeGame::SnakeGame(int numOfStages) {

}
void SnakeGame::startGame() {

}
void SnakeGame::temp() {
  int row, col;
  initscr();
  start_color();
  box(stdscr, 0, 0);
  init_pair(1, COLOR_RED, COLOR_WHITE);
  curs_set(false);
  refresh();

  WINDOW *gameboard = newwin(LINES, COLS/2+40, 0, 0);
  init_pair(2, COLOR_BLACK, COLOR_WHITE);
  box(gameboard, 0, 0);
  attron(COLOR_PAIR(2));
  wbkgd(gameboard, COLOR_PAIR(2));
  getmaxyx(gameboard, row, col);
  mvwprintw(gameboard, 0, col/2-5, "GAME");
  Map mainMap;
  mainMap.Init();
  mainMap.Update(gameboard);
  wrefresh(gameboard);

  WINDOW *scoreboard = newwin(LINES/2, COLS/2-40, 0, COLS/2+40);
  init_pair(2, COLOR_BLACK, COLOR_WHITE);
  box(scoreboard, 0, 0);
  attron(COLOR_PAIR(2));
  wbkgd(scoreboard, COLOR_PAIR(2));
  getmaxyx(scoreboard, row, col);
  mvwprintw(scoreboard, 0, col/2-5, "SCORE BOARD");
  mvwprintw(scoreboard, 2, 2, "B : ");
  mvwprintw(scoreboard, 4, 2, "+ : ");
  mvwprintw(scoreboard, 6, 2, "- : ");
  mvwprintw(scoreboard, 8, 2, "G : ");
  wrefresh(scoreboard);

  WINDOW *missionboard = newwin(LINES/2, COLS/2-40, LINES/2, COLS/2+40);
  init_pair(2, COLOR_BLACK, COLOR_WHITE);
  box(missionboard, 0, 0);
  attron(COLOR_PAIR(2));
  wbkgd(missionboard, COLOR_PAIR(2));
  getmaxyx(missionboard, row, col);
  mvwprintw(missionboard, 0, col/2-5, "MISSION BOARD");
  mvwprintw(missionboard, 2, 2, "B : 10 (v)");
  mvwprintw(missionboard, 4, 2, "+ : 5  ( )");
  mvwprintw(missionboard, 6, 2, "- : 2  ( )");
  mvwprintw(missionboard, 8, 2, "G : 1  (v)");
  wrefresh(missionboard);

  getch();
  endwin();
}
