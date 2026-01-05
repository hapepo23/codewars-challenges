/*
5 kyu
Human Readable Time
https://www.codewars.com/kata/52685f7382004e774f0001f7
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* formatDuration(int n) {
  char* result = calloc(200, sizeof(char));
  int rem, first, last, data[5];  // y, d, h, m, s
  char* words[5] = {"%d year%s", "%d day%s", "%d hour%s", "%d minute%s",
                    "%d second%s"};
  if (n == 0) {
    strcat(result, "now");
  } else {
    data[0] = n / 31536000;
    rem = n % 31536000;
    data[1] = rem / 86400;
    rem = rem % 86400;
    data[2] = rem / 3600;
    rem = rem % 3600;
    data[3] = rem / 60;
    data[4] = rem % 60;
    first = -1;
    for (int i = 0; i < 5; i++) {
      if (data[i]) {
        if (first == -1)
          first = i;
        last = i;
      }
    }
    for (int i = 0; i < 5; i++) {
      if (data[i]) {
        if (last == i && first < i)
          strcat(result, " and ");
        else if (i > first)
          strcat(result, ", ");
        sprintf(&result[strlen(result)], words[i], data[i],
                (data[i] > 1 ? "s" : ""));
      }
    }
  }
  return result;
}
