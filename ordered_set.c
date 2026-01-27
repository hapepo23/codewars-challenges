/*
4 kyu
Ordered set
https://www.codewars.com/kata/5c0c5ec84e8f1804b9000296
*/

#include <stddef.h>
#include <stdlib.h>

typedef int (*Comparator)(const void*, const void*);
typedef char* (*Stringizer)(const void*);

typedef struct Node {
  const void* key;
  struct Node* left;
  struct Node* right;
  int height;
} Node;

typedef struct Set {
  Node* root;
  size_t size;
  Comparator cmp;
  Stringizer str;
} Set;

Set* set_initialize(Comparator, Stringizer);
void set_destroy(Set*);
size_t set_size(const Set*);
int set_includes(const Set*, const void*);
void set_insert(Set*, const void*);
void set_remove(Set*, const void*);

// Helpers

static int height(Node* n) {
  return n ? n->height : 0;
}

static int max(int a, int b) {
  return a > b ? a : b;
}

static int balance_factor(Node* n) {
  return n ? height(n->left) - height(n->right) : 0;
}

static Node* node_create(const void* key) {
  Node* n = malloc(sizeof(Node));
  if (!n)
    return NULL;
  n->key = key;
  n->left = NULL;
  n->right = NULL;
  n->height = 1;
  return n;
}

static Node* rotate_right(Node* y) {
  Node* x = y->left;
  Node* t2 = x->right;
  x->right = y;
  y->left = t2;
  y->height = 1 + max(height(y->left), height(y->right));
  x->height = 1 + max(height(x->left), height(x->right));
  return x;
}

static Node* rotate_left(Node* x) {
  Node* y = x->right;
  Node* t2 = y->left;
  y->left = x;
  x->right = t2;
  x->height = 1 + max(height(x->left), height(x->right));
  y->height = 1 + max(height(y->left), height(y->right));
  return y;
}

static void node_destroy(Node* n) {
  if (!n)
    return;
  node_destroy(n->left);
  node_destroy(n->right);
  free(n);
}

static int node_includes(Node* n, Comparator cmp, const void* key) {
  if (!n)
    return 0;
  int c = cmp(key, n->key);
  if (c == 0)
    return 1;
  if (c < 0)
    return node_includes(n->left, cmp, key);
  return node_includes(n->right, cmp, key);
}

static Node* node_insert(Node* n,
                         Comparator cmp,
                         const void* key,
                         int* inserted) {
  if (!n) {
    *inserted = 1;
    return node_create(key);
  }
  int c = cmp(key, n->key);
  if (c == 0) {
    *inserted = 0;
    return n;
  } else if (c < 0) {
    n->left = node_insert(n->left, cmp, key, inserted);
  } else {
    n->right = node_insert(n->right, cmp, key, inserted);
  }
  n->height = 1 + max(height(n->left), height(n->right));
  int bf = balance_factor(n);
  if (bf > 1 && cmp(key, n->left->key) < 0)
    return rotate_right(n);
  if (bf < -1 && cmp(key, n->right->key) > 0)
    return rotate_left(n);
  if (bf > 1 && cmp(key, n->left->key) > 0) {
    n->left = rotate_left(n->left);
    return rotate_right(n);
  }
  if (bf < -1 && cmp(key, n->right->key) < 0) {
    n->right = rotate_right(n->right);
    return rotate_left(n);
  }
  return n;
}

static Node* node_min(Node* n) {
  while (n->left)
    n = n->left;
  return n;
}

static Node* node_remove(Node* n,
                         Comparator cmp,
                         const void* key,
                         int* removed) {
  if (!n)
    return NULL;
  int c = cmp(key, n->key);
  if (c < 0) {
    n->left = node_remove(n->left, cmp, key, removed);
  } else if (c > 0) {
    n->right = node_remove(n->right, cmp, key, removed);
  } else {
    *removed = 1;
    if (!n->left || !n->right) {
      Node* tmp = n->left ? n->left : n->right;
      free(n);
      return tmp;
    }
    Node* min = node_min(n->right);
    n->key = min->key;
    n->right = node_remove(n->right, cmp, min->key, removed);
  }
  n->height = 1 + max(height(n->left), height(n->right));
  int bf = balance_factor(n);
  if (bf > 1 && balance_factor(n->left) >= 0)
    return rotate_right(n);
  if (bf > 1 && balance_factor(n->left) < 0) {
    n->left = rotate_left(n->left);
    return rotate_right(n);
  }
  if (bf < -1 && balance_factor(n->right) <= 0)
    return rotate_left(n);
  if (bf < -1 && balance_factor(n->right) > 0) {
    n->right = rotate_right(n->right);
    return rotate_left(n);
  }
  return n;
}

// Public API

Set* set_initialize(Comparator cmp, Stringizer str) {
  if (!cmp)
    return NULL;
  Set* set = malloc(sizeof(Set));
  if (!set)
    return NULL;
  set->root = NULL;
  set->size = 0;
  set->cmp = cmp;
  set->str = str;
  return set;
}

void set_destroy(Set* set) {
  if (!set)
    return;
  node_destroy(set->root);
  free(set);
}

size_t set_size(const Set* set) {
  return set ? set->size : 0;
}

int set_includes(const Set* set, const void* key) {
  if (!set)
    return 0;
  return node_includes(set->root, set->cmp, key);
}

void set_insert(Set* set, const void* key) {
  if (!set)
    return;
  int inserted = 0;
  set->root = node_insert(set->root, set->cmp, key, &inserted);
  if (inserted)
    set->size++;
}

void set_remove(Set* set, const void* key) {
  if (!set)
    return;
  int removed = 0;
  set->root = node_remove(set->root, set->cmp, key, &removed);
  if (removed)
    set->size--;
}
