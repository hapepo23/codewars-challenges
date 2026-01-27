/*
4 kyu
Ordered set
https://www.codewars.com/kata/5c0c5ec84e8f1804b9000296
*/

#include <stdio.h>
#include <stdlib.h>

typedef int (*Comparator)(const void* a, const void* b);
typedef char* (*Stringizer)(const void* a);

typedef struct set Set;

Set* set_initialize(Comparator, Stringizer);
void set_destroy(Set*);
size_t set_size(const Set*);
int set_includes(const Set*, const void*);
void set_insert(Set*, const void*);
void set_remove(Set*, const void*);

int int_ascending(const void* a, const void* b) {
  int left = *((int*)a), right = *((int*)b);
  return left - right;
}

char* int_stringizer(const void* a) {
  int value = *((int*)a);
  char* s = calloc(16, sizeof(char));
  sprintf(s, "int(%d)", value);
  return s;
}

int main() {
  Set* set = set_initialize(int_ascending, int_stringizer);
  if (set_size(set) != 0)
    printf("Initial size should be 0\n");
  const int a[] = {5, 1, 8, 0, 6, 3, 7, 9, 2, 4};
  size_t n;
  for (size_t i = 0; i < 10; i++) {
    n = set_size(set);
    if (n != i)
      printf("Size before insertion: %ld should be %ld\n", n, i);
    if (set_includes(set, &a[i]))
      printf("%d has not been added yet but was found in the set\n", a[i]);
    set_insert(set, &a[i]);
    n = set_size(set);
    if (n != i + 1)
      printf("Size after insertion: %ld should be %ld\n", n, i + 1);
    if (!set_includes(set, &a[i]))
      printf("%d has just been added but was not found in the set\n", a[i]);
  }
  for (size_t i = 0; i < 10; i++) {
    n = set_size(set);
    if (n != 10 - i)
      printf("Size before deletion: %ld should be %ld\n", n, 10 - i);
    if (!set_includes(set, &a[i]))
      printf("%d was added earlier but was not found in the set\n", a[i]);
    set_remove(set, &a[i]);
    n = set_size(set);
    if (n != 10 - i - 1)
      printf("Size after deletion: %ld should be %ld\n", n, 10 - i - 1);
    if (set_includes(set, &a[i]))
      printf("%d has just been removed but was found in the set\n", a[i]);
  }
  set_destroy(set);
  printf("No messages => OK\n");
}
