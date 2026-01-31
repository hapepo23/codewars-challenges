/*
5 kyu
Snakes and Ladders
https://www.codewars.com/kata/587136ba2eefcb92a9000027
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAXJUMPS 21

static int jumps[MAXJUMPS][2] = {
    {2, 38},  {7, 14},  {8, 31},  {15, 26}, {21, 42}, {28, 84}, {36, 44},
    {51, 67}, {71, 91}, {78, 98}, {87, 94}, {16, 6},  {46, 25}, {49, 11},
    {62, 19}, {64, 60}, {74, 53}, {89, 68}, {92, 88}, {95, 75}, {99, 80}};

const char* snakes_ladders(int die1, int die2) {
  static char result[80];
  static int pos[2] = {0, 0};
  static int next_player = 0;
  bool notfin = true;
  result[0] = '\0';
  if (pos[0] == 100 || pos[1] == 100) {
    strcpy(result, "Game over!");
  } else {
    pos[next_player] += die1 + die2;
    if (pos[next_player] == 100) {
      sprintf(result, "Player %d Wins!", next_player + 1);
      notfin = false;
    } else if (pos[next_player] > 100) {
      pos[next_player] = 200 - pos[next_player];
    }
    if (notfin) {
      for (int i = 0; i < MAXJUMPS; i++) {
        if (pos[next_player] == jumps[i][0]) {
          pos[next_player] = jumps[i][1];
          break;
        }
      }
    }
  }
  if (result[0] == '\0')
    sprintf(result, "Player %d is on square %d", next_player + 1,
            pos[next_player]);
  if (!(notfin && die1 == die2))
    next_player = (next_player + 1) % 2;
  return result;
}
