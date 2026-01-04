/*
6 kyu
Roman Numerals Decoder
https://www.codewars.com/kata/51b6249c4612257ac0000005
*/

unsigned decode_roman(const char* roman_number) {
  int result = 0;
  const char* p = roman_number;
  while (*p) {
    const char* pp = p + 1;
    switch (*p) {
      case 'M':
        result += 1000;
        p++;
        break;
      case 'D':
        result += 500;
        p++;
        break;
      case 'L':
        result += 50;
        p++;
        break;
      case 'V':
        result += 5;
        p++;
        break;
      case 'C':
        if (*pp == 'M') {
          result += 900;
          p += 2;
        } else if (*pp == 'D') {
          result += 400;
          p += 2;
        } else {
          result += 100;
          p++;
        }
        break;
      case 'X':
        if (*pp == 'C') {
          result += 90;
          p += 2;
        } else if (*pp == 'L') {
          result += 40;
          p += 2;
        } else {
          result += 10;
          p++;
        }
        break;
      case 'I':
        if (*pp == 'X') {
          result += 9;
          p += 2;
        } else if (*pp == 'V') {
          result += 4;
          p += 2;
        } else {
          result += 1;
          p++;
        }
        break;
    }
  }
  return result;
}
