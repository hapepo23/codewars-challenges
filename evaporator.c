/*
7 kyu
Deodorant Evaporator
https://www.codewars.com/kata/5506b230a11c0aeab3000c1f
*/

#define UNUSED(x) (void)(x)

int evaporator(double content, double evap_per_day, double threshold) {
  UNUSED(content);
  double act_content = 100.0;
  double lost;
  int days = 0;
  do {
    days++;
    lost = act_content * evap_per_day / 100.0;
    act_content -= lost;
  } while (act_content > threshold);
  return days;
}
