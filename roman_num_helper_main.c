/*
4 kyu
Roman Numerals Helper
https://www.codewars.com/kata/51b66044bce5799a7f000003
*/

#include <stdio.h>

unsigned from_roman(const char* roman);
void to_roman(unsigned number, char* roman);

static void do_test(const unsigned number, const char* roman) {
  char buffer[100];
  to_roman(number, buffer);
  printf("input was: %d - expected: \"%s\" - got: \"%s\"\n", number, roman,
         buffer);
  unsigned calculated_number = from_roman(roman);
  printf("input was: \"%s\" - expected: %u - got: %u\n\n", roman, number,
         calculated_number);
}

int main(void) {
  do_test(1u, "I");
  do_test(4u, "IV");
  do_test(1000u, "M");
  do_test(1990u, "MCMXC");
  do_test(2007u, "MMVII");
  do_test(2u, "II");
  do_test(3u, "III");
  do_test(5u, "V");
  do_test(9u, "IX");
  do_test(10u, "X");
  do_test(11u, "XI");
  do_test(15u, "XV");
  do_test(19u, "XIX");
  do_test(22u, "XXII");
  do_test(1001u, "MI");
  do_test(2008u, "MMVIII");
  do_test(3999u, "MMMCMXCIX");
  do_test(4000u, "MMMM");
  do_test(2000u, "MM");
  do_test(1666u, "MDCLXVI");
  do_test(1000u, "M");
  do_test(400u, "CD");
  do_test(90u, "XC");
  do_test(40u, "XL");
  return 0;
}
