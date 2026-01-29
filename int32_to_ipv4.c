/*
5 kyu
int32 to IPv4
https://www.codewars.com/kata/52e88b39ffb6ac53a400022e
*/

#include <inttypes.h>
#include <stdio.h>

void uint32_to_ip(uint32_t ip, char* output) {
  uint8_t parts[4];
  for (unsigned i = 0; i < 4; i++)
    parts[i] = ip >> (i*8);
  sprintf(output, "%" PRIu8 ".%" PRIu8 ".%" PRIu8 ".%" PRIu8, parts[3],
          parts[2], parts[1], parts[0]);
}
