/*
4 kyu
Rectangle Rotation
https://www.codewars.com/kata/5886e082a836a691340000c3
*/

#include <math.h>

typedef long long ll;

ll rectangle_rotation(int a, int b) {
  double x1, x2, x3, x4;
  int ic1, ic3, ic4, if1, if2, if3;
  double aa = (double)a / sqrt(8.);
  double bb = (double)b / sqrt(8.);
  x1 = aa - bb;
  x2 = aa + bb;
  x3 = -aa + bb;
  x4 = -aa - bb;
  if1 = (int)floor(x1);
  if2 = (int)floor(x2);
  if3 = (int)floor(x3);
  ic1 = (int)ceil(x1);
  ic3 = (int)ceil(x3);
  ic4 = (int)ceil(x4);
  int delta = -ic4;
  int l = if2 - ic4 + 1;
  int m[2][l];
  for (int i = ic4; i <= if1; i++)
    m[0][i + delta] = (int)floor(i + 2. * bb);
  for (int i = ic1; i <= if2; i++)
    m[0][i + delta] = (int)floor(-i + 2. * aa);
  for (int i = ic4; i <= if3; i++)
    m[1][i + delta] = (int)ceil(-i - 2. * aa);
  for (int i = ic3; i <= if2; i++)
    m[1][i + delta] = (int)ceil(i - 2. * bb);
  ll sum = 0;
  for (int i = 0; i < l; i++)
    sum += (m[0][i] - m[1][i]) + 1;
  return sum;
}
