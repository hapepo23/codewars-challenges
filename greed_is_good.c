/*
5 kyu
Greed is Good
https://www.codewars.com/kata/5270d0d18625160ada0000e4
*/

int score(const int dice[5]) {
  int result = 0;
  int counts[6] = {0};
  for (int i = 0; i < 5; i++)
    counts[dice[i] - 1]++;
  for (int i = 0; i < 6; i++) {
    if (counts[i] >= 3) {
      result = result + (i + 1) * 100 + (i == 0 ? 900 : 0);
      counts[i] -= 3;
    }
  }
  while (counts[0] > 0) {
    result += 100;
    counts[0]--;
  }
  while (counts[4] > 0) {
    result += 50;
    counts[4]--;
  }
  return result;
}
