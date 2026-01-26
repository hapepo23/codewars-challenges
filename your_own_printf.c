/*
5 kyu
Write your own printf
https://www.codewars.com/kata/59480c92e3102df28f0000dd
*/

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR_OUTPUT 1000

static void reverse(char* s) {
  int i, j;
  char c;
  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

static void itoa(int n, char* s) {
  int i, sign;
  if ((sign = n) < 0)
    n = -n;
  i = 0;
  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

char* mr_asprintf(const char* format, ...) {
  va_list args;
  int value;
  char* string;
  char* result = calloc(MAX_CHAR_OUTPUT, sizeof(char));
  char* p = result;
  va_start(args, format);
  while (*format != '\0') {
    if (*format == '{') {
      switch (*(format + 1)) {
        case '{':
          *p = *format;
          p++;
          format += 2;
          break;
        case 'i':
          value = va_arg(args, int);
          char buffer[15];
          itoa(value, buffer);
          strcpy(p, buffer);
          p += strlen(buffer);
          format += 3;
          break;
        case 's':
          string = va_arg(args, char*);
          strcpy(p, string);
          p += strlen(string);
          format += 3;
          break;
        default:
          *p = *format;
          p++;
          format++;
      }
    } else {
      *p = *format;
      p++;
      format++;
    }
  }
  va_end(args);
  return result;
}
