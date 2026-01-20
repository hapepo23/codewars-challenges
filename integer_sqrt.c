/*
2 kyu
Integer Square Root
https://www.codewars.com/kata/58a3fa665973c2a6e80000c4
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static char* xstrdup(const char* s);
static void multiply_single_char(char a, char b, char oco, char* r, char* co);
static void add_single_char(char a, char b, char oco, char* r, char* co);
static char* multiply(const char* a, const char* b);
static char* add(const char* a, const char* b);
static void remove_leading_zeros(char* r);
static char* subtract(const char* a, const char* b);
static char** divide_with_remainder(const char* a, const char* b);
static bool equal(const char* a, const char* b);
static bool less_equal(const char* a, const char* b);
static char* square(const char* a);
static char* divide(const char* a, const char* b);

char* integerSquareRoot(char* x);

static char* xstrdup(const char* s) {
  size_t len = strlen(s) + 1;
  char* p = malloc(len);
  if (p)
    memcpy(p, s, len);
  return p;
}

static void multiply_single_char(char a, char b, char oco, char* r, char* co) {
  int product = ((int)(a - '0') * (int)(b - '0')) + (int)(oco - '0');
  *co = (char)(product / 10 + '0');
  *r = (char)(product % 10 + '0');
}

static void add_single_char(char a, char b, char oco, char* r, char* co) {
  int sum = (int)(a - '0') + (int)(b - '0') + (int)(oco - '0');
  *co = (char)(sum / 10 + '0');
  *r = (char)(sum % 10 + '0');
}

static char* multiply(const char* a, const char* b) {
  int la = strlen(a), lb = strlen(b);
  int l = la + lb, ltemp = la + 1;
  char* result = calloc(l + 1, sizeof(char));
  for (int i = 0; i < l; i++)
    result[i] = '0';
  char* temp = calloc(ltemp + 1, sizeof(char));
  for (int j = lb - 1, pos = 0; j >= 0; j--, pos++) {
    temp[ltemp - 1] = '0';
    for (int i = la - 1, k = ltemp - 1; i >= 0; i--, k--) {
      multiply_single_char(a[i], b[j], temp[k], &temp[k], &temp[k - 1]);
    }
    char co = '0';
    for (int k = ltemp - 1, m = l - 1; k >= 0; k--, m--) {
      add_single_char(result[m - pos], temp[k], co, &result[m - pos], &co);
    }
  }
  free(temp);
  char* pr = result;
  while (*pr == '0' && pr < result + l - 1)
    pr++;
  if (result < pr)
    memmove(result, pr, strlen(pr) + 1);
  return result;
}

static char* add(const char* a, const char* b) {
  unsigned la = strlen(a), lb = strlen(b);
  unsigned l = ((la > lb) ? la : lb) + 1;
  char* result = calloc(l + 1, sizeof(char));
  char* prlast;
  char* pr;
  if (la == 0 || lb == 0) {
    if (la)
      strcpy(result, a);
    else
      strcpy(result, b);
    prlast = result + strlen(result) - 1;
    pr = result;
  } else {
    for (unsigned i = 0; i < l; i++)
      result[i] = '0';
    prlast = result + l - 1;
    pr = prlast;
    const char* pa = a + la - 1;
    const char* pb = b + lb - 1;
    unsigned summand1 = 0, summand2 = 0, carryover = 0;
    while ((pa >= a) || (pb >= b)) {
      summand1 = (pa >= a) ? (*pa - '0') : 0;
      summand2 = (pb >= b) ? (*pb - '0') : 0;
      unsigned sum = summand1 + summand2 + carryover;
      carryover = sum / 10;
      sum = sum % 10;
      *pr = sum + '0';
      pa--;
      pb--;
      pr--;
    }
    if (carryover > 0)
      *pr = carryover + '0';
  }
  while (*pr == '0' && pr < prlast)
    pr++;
  if (result < pr)
    memmove(result, pr, strlen(pr) + 1);
  return result;
}

static void remove_leading_zeros(char* r) {
  char* prlast = r;
  while (*prlast)
    prlast++;
  prlast--;
  char* pr = r;
  while (*pr == '0' && pr < prlast)
    pr++;
  if (r < pr)
    memmove(r, pr, strlen(pr) + 1);
}

static char* subtract(const char* a, const char* b) {
  char* result;
  int la = strlen(a);
  int lb = strlen(b);
  int l = ((la > lb) ? la : lb);
  char* aa = calloc(l + 1, sizeof(char));
  char* bb = calloc(l + 1, sizeof(char));
  for (int i = 0; i < l; i++) {
    aa[i] = '0';
    bb[i] = '0';
  }
  strcpy(aa + l - la, a);
  strcpy(bb + l - lb, b);
  int cmp = strcmp(aa, bb);
  if (cmp == 0) {
    result = calloc(2, sizeof(char));
    strcpy(result, "0");
  } else {
    int lr = l + 1;
    result = calloc(lr + 1, sizeof(char));
    bool neg = false;
    if (cmp < 0) {
      neg = true;
      char* temp = aa;
      aa = bb;
      bb = temp;
    }
    for (int i = 0; i < lr; i++)
      result[i] = '0';
    char* prlast = result + lr - 1;
    char* pr = prlast;
    char* pa = aa + l - 1;
    char* pb = bb + l - 1;
    int carryover = 0;
    while (pa >= aa) {
      int diff = *pa - *pb - carryover;
      if (diff < 0) {
        diff += 10;
        carryover = 1;
      } else
        carryover = 0;
      *pr = diff + '0';
      pa--;
      pb--;
      pr--;
    }
    if (carryover > 0)
      *pr = carryover + '0';
    while (*pr == '0' && pr < prlast)
      pr++;
    if (neg) {
      pr--;
      *pr = '-';
    }
    if (result < pr)
      memmove(result, pr, strlen(pr) + 1);
  }
  free(aa);
  free(bb);
  return result;
}

static char** divide_with_remainder(const char* a, const char* b) {
  int la = strlen(a);
  int lb = strlen(b);
  char** result = malloc(2 * sizeof(char*));
  result[0] = calloc(la + 1, sizeof(char));
  result[1] = calloc(la + 1, sizeof(char));
  result[0][0] = '0';
  result[1][0] = '0';
  if (strcmp(a, "0") == 0 || strcmp(b, "0") == 0)
    return result;
  if (lb > la) {
    strcpy(result[1], a);
    return result;
  }
  if (strcmp(a, b) == 0) {
    result[0][0] = '1';
    return result;
  }
  char* aa = calloc(la + 2, sizeof(char));
  char* diff;
  int pos = 0;
  strncpy(aa, a, lb);
  for (int i = 0; i < la - lb + 1; i++) {
    int count = 0;
    while (true) {
      diff = subtract(aa, b);
      if (diff[0] == '-') {
        free(diff);
        break;
      }
      count++;
      strcpy(aa, diff);
      free(diff);
    }
    result[0][pos] = count + '0';
    int laa = strlen(aa);
    if (i + lb < la) {
      aa[laa] = a[i + lb];
      aa[laa + 1] = '\0';
    }
    pos++;
  }
  result[0][pos] = '\0';
  strcpy(result[1], aa);
  free(aa);
  remove_leading_zeros(result[0]);
  remove_leading_zeros(result[1]);
  return result;
}

static bool equal(const char* a, const char* b) {
  return strcmp(a, b) == 0;
}

static bool less_equal(const char* a, const char* b) {
  bool result;
  char* diff = subtract(a, b);
  result = (diff[0] == '-' || strcmp(diff, "0") == 0);
  free(diff);
  return result;
}

static char* square(const char* a) {
  return multiply(a, a);
}

static char* divide(const char* a, const char* b) {
  char** both = divide_with_remainder(a, b);
  char* result = xstrdup(both[0]);
  free(both[0]);
  free(both[1]);
  free(both);
  return result;
}

char* integerSquareRoot(char* x) {
  // Algorithm see
  // https://en.wikipedia.org/wiki/Integer_square_root#Algorithm_using_binary_search
  char* rm1 = NULL;
  char* lpr = NULL;
  char* m = NULL;
  char* mm = NULL;
  char* l = xstrdup("0");
  char* r = add(x, "1");
  while (true) {
    if (rm1 != NULL)
      free(rm1);
    rm1 = subtract(r, "1");
    if (equal(l, rm1))
      break;
    if (lpr != NULL)
      free(lpr);
    lpr = add(l, r);
    if (m != NULL)
      free(m);
    m = divide(lpr, "2");
    if (mm != NULL)
      free(mm);
    mm = square(m);
    if (less_equal(mm, x)) {
      free(l);
      l = xstrdup(m);
    } else {
      free(r);
      r = xstrdup(m);
    }
  }
  free(r);
  free(rm1);
  free(lpr);
  free(m);
  free(mm);
  return l;
}
