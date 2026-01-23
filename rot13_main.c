/*
5 kyu
ROT13
https://www.codewars.com/kata/52223df9e8f98c7aa7000062
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* rot13(char* str_out, const char* str_in);

static void do_test(const char* input, const char* expected) {
  size_t mem_size = strlen(input) + 1;
  char* user_string = memset(malloc(mem_size), '@', mem_size);
  char* actual = rot13(user_string, input);
  printf("for string: \"%s\"\nexpected  : \"%s\"\nbut got   : \"%s\"\n%s\n\n",
         input, expected, actual,
         strcmp(expected, actual) == 0 ? "OK" : "ERROR");
  free(user_string);
}

int main(void) {
  do_test("EBG13 rknzcyr.", "ROT13 example.");
  do_test(
      "How can you tell an extrovert from an\nintrovert at NSA? Va gur "
      "ryringbef,\ngur rkgebireg ybbxf ng gur BGURE thl'f fubrf.",
      "Ubj pna lbh gryy na rkgebireg sebz na\nvagebireg ng AFN? In the "
      "elevators,\nthe extrovert looks at the OTHER guy's shoes.");
  do_test("123", "123");
  do_test(
      "Guvf vf npghnyyl gur svefg xngn V rire znqr. Gunaxf sbe svavfuvat vg! "
      ":)",
      "This is actually the first kata I ever made. Thanks for finishing it! "
      ":)");
  do_test("@[`{", "@[`{");
  return 0;
}
