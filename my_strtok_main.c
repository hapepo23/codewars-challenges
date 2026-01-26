/*
5 kyu
Strings: implement your own "strtok" function!
https://www.codewars.com/kata/5806203dc2799821cb000293
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* my_strtok(char* src, const char* delims);

void do_test(const char* src, const char* delims) {
  char* warriorBuffer;
  char* libraryBuffer;
  char* warriorToken;
  char* libraryToken;
  printf("src = \"%s\"\ndelims = \"%s\"\n", src, delims);
  size_t bufferLength = strlen(src);
  warriorBuffer = (char*)calloc(bufferLength + 1, sizeof(char));
  (void)strcpy(warriorBuffer, src);
  libraryBuffer = (char*)calloc(bufferLength + 1, sizeof(char));
  (void)strcpy(libraryBuffer, src);
  warriorToken = my_strtok(warriorBuffer, delims);
  libraryToken = strtok(libraryBuffer, delims);
  while (warriorToken && libraryToken) {
    printf("Token my_strtok: \"%s\", strtok: \"%s\" - %s\n", warriorToken,
           libraryToken,
           strcmp(warriorToken, libraryToken) == 0 ? "OK" : "FAIL");
    warriorToken = my_strtok(NULL, delims);
    libraryToken = strtok(NULL, delims);
  }
  printf("Token my_strtok: \"%p\", strtok: \"%p\" - %s\n\n", warriorToken,
         libraryToken, warriorToken == libraryToken ? "OK" : "FAIL");
  free(warriorBuffer);
  free(libraryBuffer);
}

int main(void) {
  {
    const char* DELIMITERS = " ";
    const char* src = "I did it MY way!";
    do_test(src, DELIMITERS);
  }
  {
    const char* DELIMITERS = " ";
    const char* src = "hello there universe";
    do_test(src, DELIMITERS);
  }
  {
    const char* DELIMITERS = "#";
    const char* src = "#Coffee#please!#";
    do_test(src, DELIMITERS);
  }
  {
    const char* DELIMITERS = " ,.-";
    const char* src = "- This, a sample string.";
    do_test(src, DELIMITERS);
  }
  {
    const char* DELIMITERS = "#";
    const char* src = "123";
    do_test(src, DELIMITERS);
  }
  {
    const char* DELIMITERS = "#";
    const char* src = "";
    do_test(src, DELIMITERS);
  }
  {
    const char* DELIMITERS = " ,.-";
    const char* src = " ,.-";
    do_test(src, DELIMITERS);
  }
  {
    const char* DELIMITERS = ",.-";
    const char* src = " , . - ";
    do_test(src, DELIMITERS);
  }
  return 0;
}
