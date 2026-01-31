/*
5 kyu
Base64 Encoding
https://www.codewars.com/kata/5270f22f862516c686000161
*/

#include <ctype.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

static const char b64[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char* to_base64(size_t byte_count, const uint8_t bytes[byte_count]) {
  size_t full = byte_count / 3;
  size_t rem = byte_count % 3;
  size_t out_len = full * 4 + (rem ? rem + 1 : 0);
  char* out = malloc(out_len + 1);
  if (!out)
    return NULL;
  size_t i = 0, j = 0;
  for (size_t n = 0; n < full; n++) {
    uint32_t t = (bytes[i] << 16) | (bytes[i + 1] << 8) | bytes[i + 2];
    i += 3;
    out[j++] = b64[(t >> 18) & 0x3F];
    out[j++] = b64[(t >> 12) & 0x3F];
    out[j++] = b64[(t >> 6) & 0x3F];
    out[j++] = b64[t & 0x3F];
  }
  if (rem == 1) {
    uint32_t t = bytes[i] << 16;
    out[j++] = b64[(t >> 18) & 0x3F];
    out[j++] = b64[(t >> 12) & 0x3F];
  } else if (rem == 2) {
    uint32_t t = (bytes[i] << 16) | (bytes[i + 1] << 8);
    out[j++] = b64[(t >> 18) & 0x3F];
    out[j++] = b64[(t >> 12) & 0x3F];
    out[j++] = b64[(t >> 6) & 0x3F];
  }
  out[out_len] = '\0';
  return out;
}

static int b64_val(char c) {
  if ('A' <= c && c <= 'Z')
    return c - 'A';
  if ('a' <= c && c <= 'z')
    return c - 'a' + 26;
  if ('0' <= c && c <= '9')
    return c - '0' + 52;
  if (c == '+')
    return 62;
  if (c == '/')
    return 63;
  return -1;
}

uint8_t* from_base64(const char* base64, size_t* byte_count) {
  size_t len = 0;
  for (const char* p = base64; *p; p++)
    if (!isspace((unsigned char)*p))
      len++;
  size_t out_len = (len * 3) / 4;
  uint8_t* out = malloc(out_len);
  if (!out)
    return NULL;
  uint32_t acc = 0;
  int bits = 0;
  size_t j = 0;
  for (; *base64; base64++) {
    if (isspace((unsigned char)*base64))
      continue;
    int v = b64_val(*base64);
    if (v < 0)
      break;
    acc = (acc << 6) | v;
    bits += 6;
    if (bits >= 8) {
      bits -= 8;
      out[j++] = (acc >> bits) & 0xFF;
    }
  }
  *byte_count = j;
  return out;
}
