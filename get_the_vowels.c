/*
7 kyu
Consecutive Vowels in a String
https://www.codewars.com/kata/62a933d6d6deb7001093de16
*/

int get_the_vowels(const char* string) {
  int result = 0;
  char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
  int vindex = 0;
  while (*string) {
    if (*string == vowels[vindex]) {
      result++;
      vindex++;
      if (vindex == 5)
        vindex = 0;
    }
    string++;
  }
  return result;
}
