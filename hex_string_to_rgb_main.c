/*
5 kyu
Convert A Hex String To RGB
https://www.codewars.com/kata/5282b48bb70058e4c4000fa7
*/

#include <stdio.h>

typedef struct {
  int r, g, b;
} rgb;

rgb hex_str_to_rgb(const char* hex_str);

static void do_test(const char* hex_str, rgb expected) {
  rgb submitted = hex_str_to_rgb(hex_str);
  printf(
      "hex_str = \"%s\"\n"
      "Submitted: {%d, %d, %d}\n"
      "Expected : {%d, %d, %d}\n%s\n\n",
      hex_str, submitted.r, submitted.g, submitted.b, expected.r, expected.g,
      expected.b,
      (submitted.r == expected.r && submitted.g == expected.g &&
       submitted.b == expected.b)
          ? "OK"
          : "FAIL");
}

int main(void) {
  {
    const char* hex_str = "#FF9933";
    rgb expected = {255, 153, 51};
    do_test(hex_str, expected);
  }
  {
    const char* hex_str = "#beaded";
    rgb expected = {190, 173, 237};
    do_test(hex_str, expected);
  }
  {
    const char* hex_str = "#000000";
    rgb expected = {0, 0, 0};
    do_test(hex_str, expected);
  }
  {
    const char* hex_str = "#111111";
    rgb expected = {17, 17, 17};
    do_test(hex_str, expected);
  }
  {
    const char* hex_str = "#Fa3456";
    rgb expected = {250, 52, 86};
    do_test(hex_str, expected);
  }
  return 0;
}
