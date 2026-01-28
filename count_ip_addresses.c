/*
5 kyu
Count IP Addresses
https://www.codewars.com/kata/526989a41034285187000de4
*/

#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

uint32_t ip_string_to_uint32(const char* ip) {
  char s[16];
  unsigned parts[4];
  strcpy(s, ip);
  char* token = strtok(s, ".");
  unsigned index = 0;
  while (token != NULL) {
    parts[index] = atoi(token);
    index++;
    token = strtok(NULL, ".");
  }
  return parts[3] + 256 * (parts[2] + 256 * (parts[1] + 256 * parts[0]));
}

uint32_t ips_between(const char* start, const char* end) {
  return ip_string_to_uint32(end) - ip_string_to_uint32(start);
}
