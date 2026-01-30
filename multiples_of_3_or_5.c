/*
6 kyu
Multiples of 3 or 5
https://www.codewars.com/kata/514b92a657cdc65150000006
*/

int solution(int number) {
  if (number < 3)
    return 0;
  int sum = 0;
  for (int i = 3; i < number; i++)
    if (i % 3 == 0 || i % 5 == 0)
      sum += i;
  return sum;
}
