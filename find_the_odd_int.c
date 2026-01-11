/*
6 kyu
Find the odd int
https://www.codewars.com/kata/54da5a58ea159efa38000836
*/

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HT_MAX_LOAD_FACTOR 0.75
#define HT_INITIAL_CAPACITY 1024

typedef size_t (*hash_func)(const void* key);
typedef int (*key_eq_func)(const void* a, const void* b);
typedef void (*ht_free_func)(void* ptr);
typedef void (*ht_iter_func)(const void* key,
                             const void* value,
                             void* user_data);
typedef struct ht_entry {
  void* key;
  void* value;
  struct ht_entry* next;
} ht_entry;
typedef struct hash_table {
  size_t capacity;
  size_t size;
  ht_entry** buckets;
  hash_func hash;
  key_eq_func key_eq;
  ht_free_func free_key;
  ht_free_func free_value;
} hash_table;

static char* xstrdup(const char* s);
static hash_table* ht_create(const size_t capacity,
                             hash_func hash,
                             key_eq_func key_eq,
                             ht_free_func free_key,
                             ht_free_func free_value);
static void ht_destroy(hash_table* ht);
static int ht_insert(hash_table* ht, void* key, void* value);
static void* ht_get(const hash_table* ht, const void* key);
static void ht_foreach(const hash_table* ht,
                       ht_iter_func func,
                       const size_t limit,
                       void* user_data);
static int ht_resize(hash_table* ht, const size_t new_capacity);
static size_t str_hash(const void* key);
static int str_eq(const void* a, const void* b);
static void get_result(const void* key, const void* value, void* user_data);

int find_odd(size_t length, const int array[length]);

static char* xstrdup(const char* s) {
  size_t len = strlen(s) + 1;
  char* p = malloc(len);
  if (p)
    memcpy(p, s, len);
  return p;
}

static hash_table* ht_create(const size_t capacity,
                             hash_func hash,
                             key_eq_func key_eq,
                             ht_free_func free_key,
                             ht_free_func free_value) {
  size_t c = (capacity == 0 ? HT_INITIAL_CAPACITY : capacity);
  hash_table* ht = malloc(sizeof(hash_table));
  if (!ht)
    return NULL;
  ht->capacity = c;
  ht->size = 0;
  ht->hash = hash;
  ht->key_eq = key_eq;
  ht->buckets = calloc(c, sizeof(ht_entry*));
  ht->free_key = free_key;
  ht->free_value = free_value;
  return ht;
}

static void ht_destroy(hash_table* ht) {
  for (size_t i = 0; i < ht->capacity; i++) {
    ht_entry* e = ht->buckets[i];
    while (e) {
      ht_entry* next = e->next;
      if (ht->free_key)
        ht->free_key(e->key);
      if (ht->free_value)
        ht->free_value(e->value);
      free(e);
      e = next;
    }
  }
  free(ht->buckets);
  free(ht);
}

static int ht_insert(hash_table* ht, void* key, void* value) {
  double load = (double)ht->size / ht->capacity;
  if (load > HT_MAX_LOAD_FACTOR) {
    if (ht_resize(ht, ht->capacity * 2) != 0)
      return -1;
  }
  size_t idx = ht->hash(key) % ht->capacity;
  ht_entry* e = ht->buckets[idx];
  while (e) {
    if (ht->key_eq(e->key, key)) {
      if (ht->free_key)
        ht->free_key(key);
      if (ht->free_value)
        ht->free_value(e->value);
      e->value = value;
      return 0;
    }
    e = e->next;
  }
  ht_entry* new_entry = malloc(sizeof(ht_entry));
  if (!new_entry)
    return -1;
  new_entry->key = key;
  new_entry->value = value;
  new_entry->next = ht->buckets[idx];
  ht->buckets[idx] = new_entry;
  ht->size++;
  return 0;
}

static void* ht_get(const hash_table* ht, const void* key) {
  size_t idx = ht->hash(key) % ht->capacity;
  ht_entry* e = ht->buckets[idx];
  while (e) {
    if (ht->key_eq(e->key, key))
      return e->value;
    e = e->next;
  }
  return NULL;
}

static void ht_foreach(const hash_table* ht,
                       ht_iter_func func,
                       const size_t limit,
                       void* user_data) {
  if (!ht || !func)
    return;
  size_t count = 0;
  for (size_t i = 0; i < ht->capacity; i++) {
    ht_entry* e = ht->buckets[i];
    while (e) {
      func(e->key, e->value, user_data);
      count++;
      if (limit != 0)
        if (count >= limit)
          return;
      e = e->next;
    }
  }
}

static int ht_resize(hash_table* ht, const size_t new_capacity) {
  ht_entry** new_buckets = calloc(new_capacity, sizeof(ht_entry*));
  if (!new_buckets)
    return -1;
  /* Rehash all entries */
  for (size_t i = 0; i < ht->capacity; i++) {
    ht_entry* e = ht->buckets[i];
    while (e) {
      ht_entry* next = e->next;
      size_t idx = ht->hash(e->key) % new_capacity;
      e->next = new_buckets[idx];
      new_buckets[idx] = e;
      e = next;
    }
  }
  free(ht->buckets);
  ht->buckets = new_buckets;
  ht->capacity = new_capacity;
  return 0;
}

static size_t str_hash(const void* key) {
  const char* s = key;
  size_t h = 5381;
  while (*s)
    h = ((h << 5) + h) + (unsigned char)*s++;
  return h;
}

static int str_eq(const void* a, const void* b) {
  return strcmp((const char*)a, (const char*)b) == 0;
}

static void get_result(const void* key, const void* value, void* user_data) {
  int* result = (int*)user_data;
  const char* pkey = (const char*)key;
  const char* pcount = (const char*)value;
  int count = atoi(pcount);
  int thekey = atoi(pkey);
  if ((count % 2) != 0)
    *result = thekey;
}

int find_odd(size_t length, const int array[length]) {
  char keystring[20], valstring[20];
  hash_table* ht = ht_create(0, str_hash, str_eq, free, free);
  for (size_t i = 0; i < length; i++) {
    sprintf(keystring, "%d", array[i]);
    char* found = (char*)ht_get(ht, keystring);
    if (found == NULL) {
      ht_insert(ht, xstrdup(keystring), xstrdup("1"));
    } else {
      int x = atoi(found);
      x++;
      sprintf(valstring, "%d", x);
      ht_insert(ht, xstrdup(keystring), xstrdup(valstring));
    }
  }
  int result = 0;
  ht_foreach(ht, get_result, 0, &result);
  ht_destroy(ht);
  return result;
}
