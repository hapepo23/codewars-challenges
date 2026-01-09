/*
6 kyu
Array Exchange
https://www.codewars.com/kata/5353212e5ee40d4694001114
*/

void strxchg(char* s1, char* s2) {
  int l1 = 0, l2 = 0;
  char* p1 = s1;
  char* p2 = s2;
  while (*(p1 + l1))
    l1++;
  while (*(p2 + l2))
    l2++;
  if (l1 > l2) {
    char* ptemp = p1;
    p1 = p2;
    p2 = ptemp;
    int ltemp = l1;
    l1 = l2;
    l2 = ltemp;
  }
  int i = 0;
  int j = l1 - 1;
  int k = l2 - 1;
  while (i < l2) {
    char temp = *(p2 + i);
    if (j >= 0)
      *(p2 + i) = *(p1 + j);
    *(p1 + k) = temp;
    i++;
    j--;
    k--;
  }
  *(p1 + l2) = '\0';
  *(p2 + l1) = '\0';
}
