/*
5 kyu
Number of trailing zeros of N!
https://www.codewars.com/kata/52f787eb172a8b4ae1000a34
*/

long zeros(long n) {
  long count = 0;
  for (long i = 5; n / i > 0; i *= 5) {
    count += n / i;
  }
  return count;
}