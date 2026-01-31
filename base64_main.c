/*
5 kyu
Base64 Encoding
https://www.codewars.com/kata/5270f22f862516c686000161
*/

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_LEN(array) (sizeof(array) / sizeof *(array))

#define fixed_test_from(base64, bytes) test_from(base64, ARR_LEN(bytes), bytes)
#define fixed_test_to(bytes, base64) test_to(ARR_LEN(bytes), bytes, base64)

char* to_base64(size_t byte_count, const uint8_t bytes[byte_count]);
uint8_t* from_base64(const char* base64, size_t* byte_count);

static void print_bytes(size_t byte_count, const uint8_t bytes[byte_count]) {
  printf("{ ");
  for (size_t i = 0; i < byte_count; i++)
    printf("'\\x%02" PRIx8 "'%s", bytes[i], (i == byte_count - 1) ? "" : ", ");
  printf(" }");
}

static void test_from(const char* base64,
                      size_t len_exp,
                      const uint8_t expected[len_exp]) {
  size_t len_act = 42;
  uint8_t* actual = from_base64(base64, &len_act);
  printf("for base64 = \"%s\"\n", base64);
  printf("expected: ");
  print_bytes(len_exp, expected);
  printf("\nactual:   ");
  print_bytes(len_act, actual);
  printf("\nexpected %zu bytes but got %zu\n\n", len_exp, len_act);
  free(actual);
}

static void test_to(size_t byte_count,
                    const uint8_t bytes[byte_count],
                    const char* expected) {
  char* actual = to_base64(byte_count, bytes);
  printf("for bytes: ");
  print_bytes(byte_count, bytes);
  printf("\n");
  printf("expected \"%s\"\nbut got \"%s\"\n\n", expected, actual);
  free(actual);
}

int main(void) {
  test_from("", 0, NULL);
  fixed_test_from("AA", ((uint8_t[]){'\x00'}));
  fixed_test_from("AAE", ((uint8_t[]){'\x00', '\x01'}));
  fixed_test_from("++//", ((uint8_t[]){'\xfb', '\xef', '\xff'}));
  fixed_test_from("MTIzNDU2Nzg5MA", ((uint8_t[]){'1', '2', '3', '4', '5', '6',
                                                 '7', '8', '9', '0'}));
  fixed_test_from(
      "dGhpcyBpcyBhIGJ5dGVzdHJpbmch",
      ((uint8_t[]){'t', 'h', 'i', 's', ' ', 'i', 's', ' ', 'a', ' ', 'b',
                   'y', 't', 'e', 's', 't', 'r', 'i', 'n', 'g', '!'}));
  test_to(0, NULL, "");
  fixed_test_to(((uint8_t[]){'\x00'}), "AA");
  fixed_test_to(((uint8_t[]){'\x00', '\x01'}), "AAE");
  fixed_test_to(((uint8_t[]){'\xfb', '\xef', '\xff'}), "++//");
  fixed_test_to(((uint8_t[]){'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'}),
                "MTIzNDU2Nzg5MA");
  fixed_test_to(
      ((uint8_t[]){'t', 'h', 'i', 's', ' ', 'i', 's', ' ', 'a', ' ', 'b',
                   'y', 't', 'e', 's', 't', 'r', 'i', 'n', 'g', '!'}),
      "dGhpcyBpcyBhIGJ5dGVzdHJpbmch");
  return 0;
}
