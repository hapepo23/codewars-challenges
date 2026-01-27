/*
5 kyu
Convert A Hex String To RGB
https://www.codewars.com/kata/5282b48bb70058e4c4000fa7
*/

#include <stdio.h>

typedef struct {
  int r, g, b;
} rgb;

rgb hex_str_to_rgb(const char* hex_str) {
  rgb result;
  sscanf(hex_str, "#%02x%02x%02x", &result.r, &result.g, &result.b);
  return result;
}