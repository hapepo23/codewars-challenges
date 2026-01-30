/*
5 kyu
Merged String Checker
https://www.codewars.com/kata/54c9fcad28ec4c6e680011aa
*/

#include <stdbool.h>
#include <string.h>

bool is_merge(const char* s, const char* part1, const char* part2) {
  int m = strlen(part1);
  int n = strlen(part2);
  if ((int)strlen(s) != m + n)
    return false;
  bool dp[m + 1][n + 1];
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= n; j++)
      dp[i][j] = false;
  dp[0][0] = true;
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      int k = i + j - 1;
      if (i > 0 && dp[i - 1][j] && part1[i - 1] == s[k])
        dp[i][j] = true;
      if (j > 0 && dp[i][j - 1] && part2[j - 1] == s[k])
        dp[i][j] = true;
    }
  }
  return dp[m][n];
}
