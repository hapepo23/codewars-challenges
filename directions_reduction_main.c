/*
5 kyu
Directions Reduction
https://www.codewars.com/kata/550f22f4d758534c1100025a
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char** dirReduc(const char* const array[],
                      int length_in,
                      int* length_out);

static char* join(size_t length, const char* const strings[length]) {
  size_t total_size = sizeof("{}");
  for (size_t i = 0; i < length; i++)
    total_size += strlen(strings[i]) + sizeof("\"\", ") - 1;
  char *joined = malloc(total_size), *ptr = joined;
  *(ptr++) = '{';
  for (size_t i = 0; i < length; i++)
    ptr += sprintf(ptr, "\"%s\"%s", strings[i], (i == length - 1) ? "" : ", ");
  *(ptr++) = '}';
  *ptr = '\0';
  return joined;
}

static void do_test(size_t input_len,
                    const char* const input[input_len],
                    size_t exp_len,
                    const char* const expected[exp_len]) {
  int act_len = 666;
  const char** actual = dirReduc(input, input_len, &act_len);
  char* str_input = join(input_len, input);
  char* str_exp = join(exp_len, expected);
  char* str_act = join(act_len, actual);
  printf("For directions:\n%s\nexpected:\n%s\nbut got:\n%s\n%s\n\n", str_input,
         str_exp, str_act, strcmp(str_exp, str_act) == 0 ? "OK" : "FAIL");
  free(str_input);
  free(str_act);
  free(str_exp);
  free(actual);
}

int main(void) {
  do_test(7,
          (const char* [7]){"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH",
                            "WEST"},
          1, (const char* [1]){"WEST"});
  do_test(4, (const char* [4]){"NORTH", "WEST", "SOUTH", "EAST"}, 4,
          (const char* [4]){"NORTH", "WEST", "SOUTH", "EAST"});
  do_test(10,
          (const char* [10]){"NORTH", "WEST", "SOUTH", "EAST", "NORTH", "WEST",
                             "SOUTH", "EAST", "SOUTH", "NORTH"},
          8,
          (const char* [8]){"NORTH", "WEST", "SOUTH", "EAST", "NORTH", "WEST",
                            "SOUTH", "EAST"});
  do_test(7,
          (const char* [7]){"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH",
                            "NORTH"},
          1, (const char* [1]){"NORTH"});
  do_test(10,
          (const char* [10]){"EAST", "EAST", "WEST", "NORTH", "WEST", "EAST",
                             "EAST", "SOUTH", "NORTH", "WEST"},
          2, (const char* [2]){"EAST", "NORTH"});
  do_test(10,
          (const char* [10]){"NORTH", "EAST", "NORTH", "EAST", "WEST", "WEST",
                             "EAST", "EAST", "WEST", "SOUTH"},
          2, (const char* [2]){"NORTH", "EAST"});
  do_test(4, (const char* [4]){"NORTH", "SOUTH", "WEST", "EAST"}, 0, NULL);
  do_test(7,
          (const char* [7]){"NORTH", "SOUTH", "WEST", "EAST", "WEST", "WEST",
                            "WEST"},
          3, (const char* [3]){"WEST", "WEST", "WEST"});
  do_test(7,
          (const char* [7]){"NORTH", "SOUTH", "WEST", "WEST", "EAST", "EAST",
                            "WEST"},
          1, (const char* [1]){"WEST"});
  do_test(0, NULL, 0, NULL);
  do_test(9,
          (const char* [9]){"NORTH", "SOUTH", "WEST", "EAST", "EAST", "EAST",
                            "WEST", "WEST", "SOUTH"},
          1, (const char* [1]){"SOUTH"});
  return 0;
}
