/*
6 kyu
Decode the Morse code
https://www.codewars.com/kata/54b724efac3d5402db00065e
*/

#include <stdlib.h>
#include <string.h>

static const char* const morse[55] = {
    ".-",     "-...",   "-.-.",   "-..",     ".",      "..-.",     "--.",
    "....",   "..",     ".---",   "-.-",     ".-..",   "--",       "-.",
    "---",    ".--.",   "--.-",   ".-.",     "...",    "-",        "..-",
    "...-",   ".--",    "-..-",   "-.--",    "--..",   "-----",    ".----",
    "..---",  "...--",  "....-",  ".....",   "-....",  "--...",    "---..",
    "----.",  ".-.-.-", "--..--", "..--..",  ".----.", "-.-.--",   "-..-.",
    "-.--.",  "-.--.-", ".-...",  "---...",  "-.-.-.", "-...-",    ".-.-.",
    "-....-", "..--.-", ".-..-.", "...-..-", ".--.-.", "...---..."};
static const char* const ascii[55] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",  "K", "L", "M",  "N",
    "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X",  "Y", "Z", "0",  "1",
    "2", "3", "4", "5", "6", "7", "8", "9", ".", ",",  "?", "'", "!",  "/",
    "(", ")", "&", ":", ";", "=", "+", "-", "_", "\"", "$", "@", "SOS"};

char* decode_morse(const char* morse_code) {
  char* result = calloc(strlen(morse_code) + 1, sizeof(char));
  char buf[15];
  const char* p = morse_code;
  while (*p == ' ') {
    p++;
  }
  while (*p) {
    int i = 0;
    while (*p != ' ' && *p != '\0') {
      buf[i] = *p;
      i++;
      p++;
    }
    buf[i] = '\0';
    for (int j = 0; j < 55; j++) {
      if (strcmp(buf, morse[j]) == 0) {
        strcat(result, ascii[j]);
        break;
      }
    }
    int spaces = 0;
    while (*p == ' ') {
      spaces++;
      p++;
    }
    if (spaces > 2 && *p) {
      strcat(result, " ");
    }
  }
  return result;
}
