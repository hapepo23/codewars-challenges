/*
5 kyu
Weight for weight
https://www.codewars.com/kata/55c6126177c9441a570000cc
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* xstrdup(const char* s) {
  size_t len = strlen(s) + 1;
  char* p = malloc(len);
  if (p)
    memcpy(p, s, len);
  return p;
}

int digitsum(const char* n) {
  int sum = 0;
  while (*n) {
    sum += (*n - '0');
    n++;
  }
  return sum;
}

static int compare(const void* x, const void* y) {
  const char* sx = *(const char**)x;
  const char* sy = *(const char**)y;
  int dx = digitsum(sx);
  int dy = digitsum(sy);
  if (dx < dy) {
    return -1;
  } else if (dx > dy) {
    return 1;
  } else {
    return strcmp(sx, sy);
  }
}

char* orderWeight(const char* string) {
  char** arr = NULL;
  int count = 0;
  char* s = xstrdup(string);
  char* token = strtok(s, " ");
  while (token != NULL) {
    arr = realloc(arr, (count + 1) * sizeof(char*));
    arr[count] = token;
    count++;
    token = strtok(NULL, " ");
  }
  char* result = calloc(strlen(string) + 2, sizeof(char));
  if (count != 0) {
    qsort(arr, count, sizeof(char*), compare);
    for (int i = 0; i < count; i++) {
      strcat(result, arr[i]);
      strcat(result, " ");
    }
    result[strlen(result) - 1] = '\0';
  }
  free(s);
  free(arr);
  return result;
}
