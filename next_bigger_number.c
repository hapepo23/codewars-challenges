/*
4 kyu
Next bigger number with the same digits
https://www.codewars.com/kata/55983863da40caa2c900004e
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef long long ll;

static void swap(char* a, char* b) {
  char temp = *a;
  *a = *b;
  *b = temp;
}

static void reverse(char arr[], int start, int end) {
  while (start < end) {
    swap(&arr[start], &arr[end]);
    start++;
    end--;
  }
}

static bool next(char digits[], int n) {
  int i = n - 2;
  while (i >= 0 && digits[i] >= digits[i + 1])
    i--;
  if (i < 0)
    return false;
  int j = n - 1;
  while (digits[j] <= digits[i])
    j--;
  swap(&digits[i], &digits[j]);
  reverse(digits, i + 1, n - 1);
  return true;
}

ll next_bigger_number(ll n) {
  char buf[25];
  ll result = -1ll;
  sprintf(buf, "%lld", n);
  if (next(buf, strlen(buf)))
    sscanf(buf, "%lld", &result);
  return result;
}
