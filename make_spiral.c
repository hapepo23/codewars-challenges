/*
3 kyu
Make a spiral
https://www.codewars.com/kata/534e01fbbb17187c7e0000c6
*/

static void do_spiral(unsigned n,
                      unsigned m,
                      int spiral[n][n],
                      unsigned startrow,
                      unsigned startcol) {
  for (unsigned i = 0; i < m; i++) {
    spiral[startrow][i + startcol] = 1;
    spiral[i + startrow][startcol + m - 1] = 1;
    if (m > 2)
      spiral[startrow + m - 1][i + startcol] = 1;
    if (i > 1)
      spiral[i + startrow][startcol] = 1;
  }
  if (m > 4) {
    spiral[startrow + 2][startcol + 1] = 1;
    do_spiral(n, m - 4, spiral, startrow + 2, startcol + 2);
  }
}

void spiralize(unsigned n, int spiral[n][n]) {
  for (unsigned i = 0; i < n; i++) {
    for (unsigned j = 0; j < n; j++) {
      spiral[i][j] = 0;
    }
  }
  do_spiral(n, n, spiral, 0, 0);
}
