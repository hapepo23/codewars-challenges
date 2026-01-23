/*
4 kyu
Strings Mix
https://www.codewars.com/kata/5629db57620258aa9d000014
*/

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

static void create_result_string(char* result, char c, int count) {
  result[0] = ':';
  for (int i = 0; i < count; i++)
    result[i + 1] = c;
  result[count + 1] = '\0';
}

static int compare(const void* a, const void* b) {
  const char* p1 = *(const char**)a;
  const char* p2 = *(const char**)b;
  size_t len1 = strlen(p1);
  size_t len2 = strlen(p2);
  if (len1 != len2)
    return (len1 < len2) ? 1 : -1;
  else
    return strcmp(p1, p2);
}

char* mix(const char* s1, const char* s2) {
  int counts[2][26] = {0};
  char* results[26];
  char* result;
  const char* p1 = s1;
  while (*p1) {
    if (islower(*p1))
      counts[0][*p1 - 'a']++;
    p1++;
  }
  const char* p2 = s2;
  while (*p2) {
    if (islower(*p2))
      counts[1][*p2 - 'a']++;
    p2++;
  }
  size_t found = 0;
  for (int i = 0; i < 26; i++) {
    if (counts[0][i] > 1 || counts[1][i] > 1) {
      if (counts[0][i] >= counts[1][i]) {
        results[i] = calloc(counts[0][i] + 3, sizeof(char));
        results[i][0] = (counts[0][i] == counts[1][i]) ? '=' : '1';
        create_result_string(results[i] + 1, i + 'a', counts[0][i]);
      } else {
        results[i] = calloc(counts[1][i] + 3, sizeof(char));
        results[i][0] = '2';
        create_result_string(results[i] + 1, i + 'a', counts[1][i]);
      }
      found += (strlen(results[i]) + 1);
    } else {
      results[i] = calloc(1, sizeof(char));
    }
  }
  if (found == 0)
    result = calloc(1, sizeof(char));
  else {
    qsort(results, 26, sizeof(char*), compare);
    result = calloc(found + 1, sizeof(char));
    for (int i = 0; i < 26; i++) {
      if (result[0] != '\0' && results[i][0] != '\0')
        strcat(result, "/");
      strcat(result, results[i]);
    }
  }
  for (int i = 0; i < 26; i++)
    free(results[i]);
  return result;
}
