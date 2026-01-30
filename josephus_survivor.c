/*
5 kyu
Josephus Survivor
https://www.codewars.com/kata/555624b601231dc7a400017a
*/

int josephus_survivor(int n, int k) {
  int pos = 0;
  for (int i = 1; i <= n; i++)
    pos = (pos + k) % i;
  return pos + 1;
}
