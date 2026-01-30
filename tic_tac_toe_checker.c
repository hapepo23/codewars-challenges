/*
5 kyu
Tic-Tac-Toe Checker
https://www.codewars.com/kata/525caa5c1bf619d28c000335
*/

#define WINROWS 8
#define SQUARES 3

enum game_state { NOT_FINISHED = -1, DRAW = 0, X_WON = 1, O_WON = 2 };

enum square { EMPTY = 0, X = 1, O = 2 };

int rowindexes[WINROWS][SQUARES][2] = {
    {{0, 0}, {0, 1}, {0, 2}}, {{1, 0}, {1, 1}, {1, 2}},
    {{2, 0}, {2, 1}, {2, 2}}, {{0, 0}, {1, 0}, {2, 0}},
    {{0, 1}, {1, 1}, {2, 1}}, {{0, 2}, {1, 2}, {2, 2}},
    {{0, 0}, {1, 1}, {2, 2}}, {{0, 2}, {1, 1}, {2, 0}}};

enum game_state check_game_state(const enum square board[3][3]) {
  for (int r = 0; r < WINROWS; r++) {
    int count1 = 0, count2 = 0;
    for (int c = 0; c < SQUARES; c++) {
      enum square sq = board[rowindexes[r][c][0]][rowindexes[r][c][1]];
      if (sq == X)
        count1++;
      else if (sq == O)
        count2++;
    }
    if (count1 == 3)
      return X_WON;
    if (count2 == 3)
      return O_WON;
  }
  int empty = 0;
  for (int r = 0; r < SQUARES; r++)
    for (int c = 0; c < SQUARES; c++)
      if (board[r][c] == EMPTY)
        empty++;
  return empty > 0 ? NOT_FINISHED : DRAW;
}
