/*
6 kyu
Roman Numerals Decoder
https://www.codewars.com/kata/51b6249c4612257ac0000005
*/

#include <stdio.h>

unsigned decode_roman(const char* roman_number);

static void do_test(const char* roman_number, unsigned expected) {
  unsigned actual = decode_roman(roman_number);
  printf("input was:\n\"%s\"\nexpected:\n\"%u\"\ngot:\n\"%u\"\n\n",
         roman_number, expected, actual);
}

int main(void) {
  do_test("I", 1);
  do_test("IV", 4);
  do_test("MCD", 1400);
  do_test("XXVII", 27);
  do_test("DCXXXIV", 634);
  do_test("MMVI", 2006);
  do_test("XXXIX", 39);
  do_test("MCMXCIX", 1999);
  // Historical Test Cases :)
  // The fall of the Western Roman Empire:
  do_test("CDLXXVI", 476);
  // The fall of the Byzantine Empire:
  do_test("MCDLIII", 1453);
  // Cristopher Columbus "Discovers" America
  do_test("MCDXCII", 1492);
  return 0;
}
