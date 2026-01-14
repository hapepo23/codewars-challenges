/*
6 kyu
Decode the Morse code
https://www.codewars.com/kata/54b724efac3d5402db00065e
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* decode_morse(const char* morse_code);

static void do_test(const char* input, char* expected) {
  char* submitted = decode_morse(input);
  printf("Input    : \"%s\"\nExpected : \"%s\"\nSubmitted: \"%s\"\n%s\n\n",
         input, expected, submitted,
         strcmp(expected, submitted) == 0 ? "OK" : "ERROR");
  free(submitted);
}

int main(void) {
  do_test(".... . -.--   .--- ..- -.. .", "HEY JUDE");
  do_test(
      "---...   ..-. .- ..--.- -... ..-.   .--- .----. .--.-. .-.-. ... -....- "
      ".-. -. ...-- ... ..--.. ----. .-.-. .-.. .-.. .--   -.-- .... - .----. "
      "--..--        ",
      ": FA_BF J'@+S-RN3S?9+LLW YHT',");
  return 0;
}
