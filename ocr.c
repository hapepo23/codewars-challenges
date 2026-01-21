/*
2 kyu
Optical character recognition (not definitively solved)
https://www.codewars.com/kata/5ec9e176721b990029ebce83
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define CHAR_MAX 200
#define DEBUG false

const unsigned IMAGE_MAX = 255;

typedef struct {
  int width, height;
  unsigned* pixels;
} Image;

typedef struct {
  int xleft, xright, width, ytop, ybottom, height;
  Image* image_copy;
  Image* image_30x48;
  float features[8][5];
} Digitbox;

static Digitbox digitboxes[CHAR_MAX];
static int digitboxes_count;

static float templates[10][8][5] = {{
                                        {
                                            0.917f,
                                            1.000f,
                                            1.000f,
                                            1.000f,
                                            0.889f,
                                        },
                                        {
                                            1.000f,
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                            1.000f,
                                        },
                                        {
                                            1.000f,
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                            1.000f,
                                        },
                                        {
                                            1.000f,
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                            1.000f,
                                        },
                                        {
                                            1.000f,
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                            1.000f,
                                        },
                                        {
                                            1.000f,
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                            1.000f,
                                        },
                                        {
                                            1.000f,
                                            0.167f,
                                            0.167f,
                                            0.167f,
                                            1.000f,
                                        },
                                        {
                                            0.778f,
                                            1.000f,
                                            1.000f,
                                            1.000f,
                                            0.722f,
                                        },
                                    },
                                    {
                                        {
                                            0.972f,
                                            1.000f,
                                            1.000f,
                                            0.000f,
                                            0.000f,
                                        },
                                        {
                                            0.000f,
                                            0.000f,
                                            1.000f,
                                            0.000f,
                                            0.000f,
                                        },
                                        {
                                            0.000f,
                                            0.000f,
                                            1.000f,
                                            0.000f,
                                            0.000f,
                                        },
                                        {
                                            0.000f,
                                            0.000f,
                                            1.000f,
                                            0.000f,
                                            0.000f,
                                        },
                                        {
                                            0.000f,
                                            0.000f,
                                            1.000f,
                                            0.000f,
                                            0.611f,
                                        },
                                        {
                                            0.000f,
                                            0.000f,
                                            1.000f,
                                            0.000f,
                                            1.000f,
                                        },
                                        {
                                            0.139f,
                                            0.167f,
                                            1.000f,
                                            0.167f,
                                            1.000f,
                                        },
                                        {
                                            0.944f,
                                            1.000f,
                                            1.000f,
                                            1.000f,
                                            0.889f,
                                        },
                                    },
                                    {
                                        {
                                            0.944f,
                                            1.000f,
                                            1.000f,
                                            1.000f,
                                            0.917f,
                                        },
                                        {
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                            0.833f,
                                        },
                                        {
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                            0.833f,
                                        },
                                        {
                                            0.417f,
                                            0.667f,
                                            0.667f,
                                            0.667f,
                                            0.944f,
                                        },
                                        {
                                            1.000f,
                                            0.500f,
                                            0.500f,
                                            0.500f,
                                            0.306f,
                                        },
                                        {
                                            1.000f,
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                        },
                                        {
                                            1.000f,
                                            0.167f,
                                            0.167f,
                                            0.167f,
                                            0.139f,
                                        },
                                        {
                                            0.972f,
                                            1.000f,
                                            1.000f,
                                            1.000f,
                                            0.944f,
                                        },
                                    },
                                    {
                                        {
                                            0.972f,
                                            1.000f,
                                            1.000f,
                                            1.000f,
                                            0.917f,
                                        },
                                        {
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                            1.000f,
                                        },
                                        {
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                            1.000f,
                                        },
                                        {
                                            0.000f,
                                            0.583f,
                                            0.667f,
                                            0.694f,
                                            0.917f,
                                        },
                                        {
                                            0.000f,
                                            0.306f,
                                            0.333f,
                                            0.444f,
                                            0.972f,
                                        },
                                        {
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                            1.000f,
                                        },
                                        {
                                            0.111f,
                                            0.167f,
                                            0.167f,
                                            0.167f,
                                            1.000f,
                                        },
                                        {
                                            1.000f,
                                            1.000f,
                                            1.000f,
                                            1.000f,
                                            0.778f,
                                        },
                                    },
                                    {
                                        {
                                            0.944f,
                                            0.167f,
                                            0.000f,
                                            0.111f,
                                            0.028f,
                                        },
                                        {
                                            1.000f,
                                            0.167f,
                                            0.000f,
                                            0.806f,
                                            0.167f,
                                        },
                                        {
                                            1.000f,
                                            0.167f,
                                            0.000f,
                                            0.833f,
                                            0.167f,
                                        },
                                        {
                                            1.000f,
                                            0.167f,
                                            0.000f,
                                            0.833f,
                                            0.167f,
                                        },
                                        {
                                            1.000f,
                                            0.750f,
                                            0.667f,
                                            0.944f,
                                            0.556f,
                                        },
                                        {
                                            0.333f,
                                            0.333f,
                                            0.333f,
                                            0.889f,
                                            0.306f,
                                        },
                                        {
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                            0.833f,
                                            0.167f,
                                        },
                                        {
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                            0.833f,
                                            0.167f,
                                        },
                                    },
                                    {
                                        {
                                            0.167f,
                                            1.000f,
                                            1.000f,
                                            1.000f,
                                            0.833f,
                                        },
                                        {
                                            0.167f,
                                            0.833f,
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                        },
                                        {
                                            0.167f,
                                            0.833f,
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                        },
                                        {
                                            0.167f,
                                            0.944f,
                                            0.667f,
                                            0.667f,
                                            0.333f,
                                        },
                                        {
                                            0.083f,
                                            0.500f,
                                            0.500f,
                                            0.583f,
                                            0.944f,
                                        },
                                        {
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                            0.167f,
                                            1.000f,
                                        },
                                        {
                                            0.472f,
                                            0.194f,
                                            0.167f,
                                            0.306f,
                                            1.000f,
                                        },
                                        {
                                            0.639f,
                                            0.917f,
                                            1.000f,
                                            1.000f,
                                            0.611f,
                                        },
                                    },
                                    {
                                        {
                                            0.972f,
                                            0.444f,
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                        },
                                        {
                                            1.000f,
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                        },
                                        {
                                            1.000f,
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                        },
                                        {
                                            1.000f,
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                        },
                                        {
                                            1.000f,
                                            0.694f,
                                            0.667f,
                                            0.667f,
                                            0.667f,
                                        },
                                        {
                                            1.000f,
                                            0.333f,
                                            0.333f,
                                            0.333f,
                                            1.000f,
                                        },
                                        {
                                            1.000f,
                                            0.167f,
                                            0.167f,
                                            0.167f,
                                            1.000f,
                                        },
                                        {
                                            0.889f,
                                            1.000f,
                                            1.000f,
                                            1.000f,
                                            0.944f,
                                        },
                                    },
                                    {
                                        {
                                            1.000f,
                                            1.000f,
                                            1.000f,
                                            1.000f,
                                            1.000f,
                                        },
                                        {
                                            0.306f,
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                            1.000f,
                                        },
                                        {
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                            0.028f,
                                            1.000f,
                                        },
                                        {
                                            0.000f,
                                            0.000f,
                                            0.083f,
                                            0.750f,
                                            0.722f,
                                        },
                                        {
                                            0.000f,
                                            0.000f,
                                            0.833f,
                                            0.639f,
                                            0.028f,
                                        },
                                        {
                                            0.000f,
                                            0.000f,
                                            1.000f,
                                            0.000f,
                                            0.000f,
                                        },
                                        {
                                            0.000f,
                                            0.000f,
                                            1.000f,
                                            0.000f,
                                            0.000f,
                                        },
                                        {
                                            0.000f,
                                            0.000f,
                                            1.000f,
                                            0.000f,
                                            0.000f,
                                        },
                                    },
                                    {
                                        {
                                            0.000f,
                                            0.972f,
                                            1.000f,
                                            1.000f,
                                            0.139f,
                                        },
                                        {
                                            0.000f,
                                            1.000f,
                                            0.000f,
                                            0.833f,
                                            0.167f,
                                        },
                                        {
                                            0.000f,
                                            1.000f,
                                            0.000f,
                                            0.833f,
                                            0.167f,
                                        },
                                        {
                                            0.333f,
                                            1.000f,
                                            0.667f,
                                            0.944f,
                                            0.556f,
                                        },
                                        {
                                            0.972f,
                                            0.500f,
                                            0.500f,
                                            0.500f,
                                            0.917f,
                                        },
                                        {
                                            1.000f,
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                            0.833f,
                                        },
                                        {
                                            1.000f,
                                            0.167f,
                                            0.167f,
                                            0.167f,
                                            0.861f,
                                        },
                                        {
                                            0.639f,
                                            1.000f,
                                            1.000f,
                                            1.000f,
                                            0.778f,
                                        },
                                    },
                                    {
                                        {
                                            0.944f,
                                            1.000f,
                                            1.000f,
                                            1.000f,
                                            0.889f,
                                        },
                                        {
                                            0.861f,
                                            0.167f,
                                            0.167f,
                                            0.167f,
                                            1.000f,
                                        },
                                        {
                                            0.889f,
                                            0.333f,
                                            0.333f,
                                            0.333f,
                                            1.000f,
                                        },
                                        {
                                            0.667f,
                                            0.667f,
                                            0.667f,
                                            0.694f,
                                            1.000f,
                                        },
                                        {
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                            1.000f,
                                        },
                                        {
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                            1.000f,
                                        },
                                        {
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                            1.000f,
                                        },
                                        {
                                            0.000f,
                                            0.000f,
                                            0.000f,
                                            0.472f,
                                            0.972f,
                                        },
                                    }};

static int usecase;  // only for DEBUG

static void debug_image_export(const char* filename, Image* img);
static void binarize(Image* img);
static void detect_digitboxes(Image* img);
static void resize_digit_image_nnr(const Image* src, Image* dst);
static void calc_digit_features(void);
static int classify(int k, bool* maybe_wrong);
char* ocr(Image* image);

static void debug_image_export(const char* filename, Image* img) {
  FILE* f = fopen(filename, "w");
  fprintf(f, "P2\n# Export\n%d %d\n255\n", img->width, img->height);
  for (int y = 0; y < img->height; y++) {
    for (int x = 0; x < img->width; x++) {
      fprintf(f, "%u\n", img->pixels[y * img->width + x]);
    }
  }
  fclose(f);
}

static void binarize(Image* img) {
  long pixsum = 0;
  for (int y = 0; y < img->height; y++) {
    for (int x = 0; x < img->width; x++) {
      pixsum += img->pixels[y * img->width + x];
    }
  }
  unsigned pixavg;
  unsigned pixavg_orig = pixsum / (img->height * img->width);
  if (pixavg_orig > 220)
    pixavg = pixavg_orig - 50;
  else
    pixavg = pixavg_orig - 30;
  if (DEBUG)
    printf("binarize: pixavg_orig = %u, pixavg = %u\n", pixavg_orig, pixavg);
  for (int y = 0; y < img->height; y++) {
    for (int x = 0; x < img->width; x++) {
      img->pixels[y * img->width + x] =
          img->pixels[y * img->width + x] < pixavg ? 0 : IMAGE_MAX;
    }
  }
}

static void detect_digitboxes(Image* img) {
  digitboxes_count = 0;
  bool found = false;
  for (int x = 0; x < img->width; x++) {
    long avg = 0;
    for (int y = 0; y < img->height; y++) {
      avg += img->pixels[y * img->width + x];
    }
    avg /= img->height;
    if (!found && avg < 255) {
      found = true;
      digitboxes_count++;
      digitboxes[digitboxes_count - 1].xleft = x;
    } else if (found && avg > 254) {
      found = false;
      digitboxes[digitboxes_count - 1].xright = x;
      digitboxes[digitboxes_count - 1].width =
          digitboxes[digitboxes_count - 1].xright -
          digitboxes[digitboxes_count - 1].xleft + 1;
    }
  }
  if (found) {
    digitboxes[digitboxes_count - 1].xright = img->width - 1;
    digitboxes[digitboxes_count - 1].width =
        digitboxes[digitboxes_count - 1].xright -
        digitboxes[digitboxes_count - 1].xleft + 1;
  }
  for (int k = 0; k < digitboxes_count; k++) {
    found = false;
    for (int y = 0; y < img->height; y++) {
      long avg = 0;
      for (int x = digitboxes[k].xleft; x <= digitboxes[k].xright; x++) {
        avg += img->pixels[y * img->width + x];
      }
      avg /= digitboxes[k].width;
      if (!found && avg < 255) {
        found = true;
        digitboxes[k].ytop = y;
      } else if (found && avg > 254) {
        digitboxes[k].ybottom = y;
        digitboxes[k].height = digitboxes[k].ybottom - digitboxes[k].ytop + 1;
        found = false;
        break;
      }
    }
    if (found) {
      digitboxes[k].ybottom = img->height - 1;
      digitboxes[k].height = digitboxes[k].ybottom - digitboxes[k].ytop + 1;
    }
    digitboxes[k].image_copy = malloc(sizeof(Image));
    digitboxes[k].image_copy->pixels =
        malloc(sizeof(unsigned) * digitboxes[k].width * digitboxes[k].height);
    digitboxes[k].image_copy->width = digitboxes[k].width;
    digitboxes[k].image_copy->height = digitboxes[k].height;
    for (int y = 0; y < digitboxes[k].height; y++) {
      for (int x = 0; x < digitboxes[k].width; x++) {
        digitboxes[k].image_copy->pixels[y * digitboxes[k].width + x] =
            img->pixels[(digitboxes[k].ytop + y) * img->width + x +
                        digitboxes[k].xleft];
      }
    }
    digitboxes[k].image_30x48 = malloc(sizeof(Image));
    digitboxes[k].image_30x48->pixels = malloc(sizeof(unsigned) * 30 * 48);
    digitboxes[k].image_30x48->width = 30;
    digitboxes[k].image_30x48->height = 48;
    resize_digit_image_nnr(digitboxes[k].image_copy, digitboxes[k].image_30x48);
  }
  if (DEBUG) {
    printf("%d digits found:\n", digitboxes_count);
    for (int k = 0; k < digitboxes_count; k++) {
      printf("%d: xleft=%d, xright=%d, w=%d / ytop=%d, ybottom=%d, h=%d\n",
             k + 1, digitboxes[k].xleft, digitboxes[k].xright,
             digitboxes[k].width, digitboxes[k].ytop, digitboxes[k].ybottom,
             digitboxes[k].height);
      char filename[100];
      sprintf(filename, "./ocr_files/debug/digitboxes_case_%d_char_%d_orig.pgm",
              usecase, k);
      debug_image_export(filename, digitboxes[k].image_copy);
      sprintf(filename,
              "./ocr_files/debug/digitboxes_case_%d_char_%d_resized.pgm",
              usecase, k);
      debug_image_export(filename, digitboxes[k].image_30x48);
    }
  }
}

static void resize_digit_image_nnr(const Image* src, Image* dst) {
  // Nearest-Neighbor Resize
  for (int y = 0; y < dst->height; y++) {
    int sy = y * src->height / dst->height;
    for (int x = 0; x < dst->width; x++) {
      int sx = x * src->width / dst->width;
      dst->pixels[y * dst->width + x] = src->pixels[sy * src->width + sx];
    }
  }
}

static void calc_digit_features(void) {
  for (int k = 0; k < digitboxes_count; k++) {
    for (int m = 0; m < 8; m++) {
      for (int n = 0; n < 5; n++) {
        float sum = 0;
        for (int x = 0; x < 6; x++) {
          for (int y = 0; y < 6; y++) {
            sum +=
                digitboxes[k].image_30x48->pixels[n * 6 + x + (m * 6 + y) * 30];
          }
        }
        digitboxes[k].features[m][n] = 1.f - (sum / 36.f / 255.f);
      }
    }
  }
}

static int classify(int k, bool* maybe_wrong) {
  int best = -1;
  float avg_dist = 0.f;
  float best_d = 1e30f;
  for (int d = 0; d < 10; d++) {
    float dist = 0;
    for (int m = 0; m < 8; m++) {
      for (int n = 0; n < 5; n++) {
        float diff = digitboxes[k].features[m][n] - templates[d][m][n];
        dist += diff * diff;
      }
    }
    avg_dist += dist;
    if (DEBUG)
      printf("%d = %f, ", d, dist);
    if (dist < best_d) {
      best_d = dist;
      best = d;
    }
  }
  avg_dist = avg_dist / 10;
  float percentage = best_d / avg_dist * 100.f;
  if (DEBUG)
    printf("BEST = %d = %f (%f %% of avg: %f)\n", best, best_d, percentage,
           avg_dist);
  *maybe_wrong = (percentage > 55.f || avg_dist < 5.f);
  return best;
}

char* ocr(Image* image) {
  bool maybe_wrong = false;  // not used
  if (DEBUG)
    usecase++;
  char* result = calloc(CHAR_MAX, sizeof(char));
  binarize(image);
  detect_digitboxes(image);
  calc_digit_features();
  for (int k = 0; k < digitboxes_count; k++) {
    result[k] = (char)('0' + classify(k, &maybe_wrong));
    free(digitboxes[k].image_30x48->pixels);
    free(digitboxes[k].image_30x48);
    free(digitboxes[k].image_copy->pixels);
    free(digitboxes[k].image_copy);
  }
  return result;
}
