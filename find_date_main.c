/*
6 kyu
Which day of the week does this date fall on?
https://www.codewars.com/kata/6908e2f710e75a2349b0e75b
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

enum weekday { SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY };

enum weekday find_date(const unsigned date[3]);

static void do_test(const unsigned date[3], enum weekday expected) {
  const char* const weekdays[7] = {"SUNDAY",   "MONDAY", "TUESDAY", "WEDNESDAY",
                                   "THURSDAY", "FRIDAY", "SATURDAY"};
  enum weekday actual = find_date(date);
  printf("date = %u-%u-%u, expected: \"%s\", actual: \"%s\"\n", date[0],
         date[1], date[2], weekdays[expected], weekdays[actual]);
}

int main(void) {
  {
    const unsigned date[3] = {2000, 1, 1};
    do_test(date, SATURDAY);
  }
  {
    const unsigned date[3] = {1865, 2, 2};
    do_test(date, THURSDAY);
  }
  {
    const unsigned date[3] = {1775, 9, 23};
    do_test(date, SATURDAY);
  }
  {
    const unsigned date[3] = {1604, 2, 27};
    do_test(date, FRIDAY);
  }
  {
    const unsigned date[3] = {1583, 1, 1};
    do_test(date, SATURDAY);
  }
  {
    const unsigned date[3] = {2583, 12, 31};
    do_test(date, WEDNESDAY);
  }
  {
    const unsigned date[3] = {2029, 10, 16};
    do_test(date, TUESDAY);
  }
  {
    const unsigned date[3] = {9999, 12, 31};
    do_test(date, FRIDAY);
  }
  {
    const unsigned date[3] = {2000, 2, 29};
    do_test(date, TUESDAY);
  }
  {
    const unsigned date[3] = {2025, 11, 3};
    do_test(date, MONDAY);
  }
  {
    const unsigned date[3] = {1950, 6, 23};
    do_test(date, FRIDAY);
  }
  {
    const unsigned date[3] = {2015, 3, 6};
    do_test(date, FRIDAY);
  }
  return 0;
}
