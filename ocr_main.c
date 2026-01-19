/*
2 kyu
Optical character recognition
https://www.codewars.com/kata/5ec9e176721b990029ebce83
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int width, height;
  unsigned* pixels;
} Image;

char* ocr(Image* image);

static int next_token(FILE* f, char* buf, int maxlen) {
  int c;
  for (;;) {
    c = fgetc(f);
    if (c == EOF)
      return 0;
    if (isspace(c))
      continue;
    if (c == '#') {
      while (c != '\n' && c != EOF)
        c = fgetc(f);
      continue;
    }
    break;
  }
  int i = 0;
  do {
    if (i < maxlen - 1)
      buf[i++] = (char)c;
    c = fgetc(f);
  } while (c != EOF && !isspace(c));
  buf[i] = '\0';
  return 1;
}

static int load_pgm_ascii(const char* filename, Image* img) {
  FILE* f = fopen(filename, "r");
  if (!f) {
    perror("fopen");
    return 0;
  }
  char tok[64];
  /* Magic number */
  if (!next_token(f, tok, sizeof(tok)) || strcmp(tok, "P2") != 0) {
    fprintf(stderr, "Not a P2 PGM file\n");
    fclose(f);
    return 0;
  }
  /* Width */
  if (!next_token(f, tok, sizeof(tok))) {
    fclose(f);
    return 0;
  }
  img->width = atoi(tok);
  /* Height */
  if (!next_token(f, tok, sizeof(tok))) {
    fclose(f);
    return 0;
  }
  img->height = atoi(tok);
  /* Max value */
  if (!next_token(f, tok, sizeof(tok))) {
    fclose(f);
    return 0;
  }
  int maxval = atoi(tok);
  if (maxval <= 0 || maxval > 255) {
    fclose(f);
    return 0;
  }
  int n = img->width * img->height;
  img->pixels = malloc(n * sizeof(unsigned));
  if (!img->pixels) {
    fclose(f);
    return 0;
  }
  /* Pixel data */
  for (int i = 0; i < n; i++) {
    if (!next_token(f, tok, sizeof(tok))) {
      free(img->pixels);
      img->pixels = NULL;
      fclose(f);
      return 0;
    }
    img->pixels[i] = (unsigned)atoi(tok);
  }
  fclose(f);
  return 1;
}

static void export_image(const char* filename, Image* img) {
  FILE* f = fopen(filename, "w");
  fprintf(f, "P2\n# Export\n%d %d\n255\n", img->width, img->height);
  for (int y = 0; y < img->height; y++) {
    for (int x = 0; x < img->width; x++) {
      fprintf(f, "%u\n", img->pixels[y * img->width + x]);
    }
  }
  fclose(f);
}

static void test1(void) {
  unsigned data[] = {
      0xff, 0xff, 0xff, 0xc0, 0xad, 0xad, 0xad, 0xad, 0xaf, 0xe8, 0xff, 0xff,
      0xff, 0xff, 0xff, 0xda, 0x2,  0x0,  0x0,  0x0,  0x0,  0x0,  0x3c, 0xff,
      0xff, 0xff, 0xff, 0xff, 0xd4, 0x0,  0x0,  0x28, 0x2e, 0xe,  0x0,  0x37,
      0xff, 0xff, 0xff, 0xff, 0xff, 0xd4, 0x0,  0x0,  0xdc, 0xff, 0x50, 0x0,
      0x37, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd4, 0x0,  0x0,  0xdc, 0xff, 0x50,
      0x0,  0x37, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd4, 0x0,  0x0,  0xdc, 0xff,
      0x50, 0x0,  0x37, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd4, 0x0,  0x0,  0xdc,
      0xff, 0x50, 0x0,  0x37, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd4, 0x0,  0x0,
      0xdc, 0xff, 0x50, 0x0,  0x37, 0xff, 0xff, 0xff, 0xff, 0xd3, 0x42, 0x0,
      0x0,  0x3a, 0x44, 0x12, 0x0,  0xe,  0x81, 0xf3, 0xff, 0xd9, 0xb,  0x0,
      0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x4f, 0xff, 0xb0, 0x0,
      0xb,  0x43, 0x43, 0x43, 0x43, 0x43, 0x43, 0x35, 0x0,  0xa,  0xf1, 0xad,
      0x0,  0x2b, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc8, 0x0,  0x0,  0xe8,
      0xad, 0x0,  0x2b, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc8, 0x0,  0x0,
      0xe8, 0xad, 0x0,  0x2b, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc8, 0x0,
      0x0,  0xe8, 0xad, 0x0,  0x2b, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc8,
      0x0,  0x0,  0xe8, 0xad, 0x0,  0x2b, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
      0xc8, 0x0,  0x0,  0xe8, 0xb2, 0x0,  0x8,  0x32, 0x32, 0x32, 0x32, 0x32,
      0x32, 0x28, 0x0,  0xe,  0xf5, 0xe8, 0x1e, 0x15, 0x15, 0x15, 0x15, 0x15,
      0x15, 0x15, 0x15, 0x15, 0x6b, 0xff};
  Image image = {13, 18, data};
  char answer[] = "8";
  char* actual = ocr(&image);
  printf(
      "Test #1 (w=%d x h=%d = %d px)\nExpected \"%s\" (%ld)\nReceived "
      "\"%s\"\n%s\n\n",
      image.width, image.height, image.width * image.height, answer,
      strlen(answer), actual, strcmp(actual, answer) == 0 ? "OK" : "ERROR");
  char exportfile[100] = "./ocr_files/img/test1_export.pgm";
  export_image(exportfile, &image);
  free(actual);
}

static void test2(const char* filename, const char* answer) {
  Image image;
  if (!load_pgm_ascii(filename, &image)) {
    printf("Failed to load \"%s\"\n", filename);
    return;
  }
  char* actual = ocr(&image);
  printf(
      "Test #2 (w=%d x h=%d = %d px, %s)\nExpected \"%s\" (%ld)\nReceived "
      "\"%s\"\n%s\n\n",
      image.width, image.height, image.width * image.height, filename, answer,
      strlen(answer), actual, strcmp(actual, answer) == 0 ? "OK" : "ERROR");
  char exportfile[100];
  strcpy(exportfile, filename);
  exportfile[strlen(filename) - 4] = '\0';
  strcat(exportfile, "_export.pgm");
  export_image(exportfile, &image);
  free(image.pixels);
  free(actual);
}

int main(void) {
  test1();
  test2("./ocr_files/digit_img/0.pgm", "0");
  test2("./ocr_files/digit_img/1.pgm", "1");
  test2("./ocr_files/digit_img/2.pgm", "2");
  test2("./ocr_files/digit_img/3.pgm", "3");
  test2("./ocr_files/digit_img/4.pgm", "4");
  test2("./ocr_files/digit_img/5.pgm", "5");
  test2("./ocr_files/digit_img/6.pgm", "6");
  test2("./ocr_files/digit_img/7.pgm", "7");
  test2("./ocr_files/digit_img/8.pgm", "8");
  test2("./ocr_files/digit_img/9.pgm", "9");
  test2("./ocr_files/img/ocr-demo6.pgm", "0123456789");
  test2("./ocr_files/img/ocr-demo1.pgm", "64007");
  test2("./ocr_files/img/ocr-demo2.pgm", "21666534928382091442");
  test2("./ocr_files/img/ocr-demo3.pgm", "5670143292");
  test2("./ocr_files/img/ocr-demo4.pgm", "165");
  test2("./ocr_files/img/ocr-demo5.pgm", "8547777277946");
  return 0;
}
