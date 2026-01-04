/*
6 kyu
Which day of the week does this date fall on?
https://www.codewars.com/kata/6908e2f710e75a2349b0e75b
*/

enum weekday { SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY };

enum weekday find_date(const unsigned date[3]) {
  int year = date[0];
  int mon = date[1];
  int day = date[2];
  if (mon < 3)
    year = year - 1;
  int w =
      (((day + (int)(2.6 * (double)((mon + 9) % 12 + 1) - 0.2) + year % 100 +
         (year % 100 / 4) + (year / 400) - 2 * (year / 100) - 1) %
            7 +
        7) %
           7 +
       1) %
      7;
  return (enum weekday)w;
}
