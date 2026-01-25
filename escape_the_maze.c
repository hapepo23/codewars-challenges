/*
4 kyu
Escape the maze
https://www.codewars.com/kata/5877027d885d4f6144000404
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUEUE_MAX_SIZE 10000

typedef enum { N = 0, E, S, W } Direction;

typedef struct {
  unsigned height, width;
  char** grid;
} Maze;

typedef struct {
  int x, y;
} Point;

typedef struct {
  Point items[QUEUE_MAX_SIZE];
  int front;
  int rear;
} Queue;

char* move[4][4] = {
    {"F", "RF", "BF", "LF"},  // olddir = N, newdir = NESW
    {"LF", "F", "RF", "BF"},  // olddir = E, newdir = NESW
    {"BF", "LF", "F", "RF"},  // olddir = S, newdir = NESW
    {"RF", "BF", "LF", "F"}   // olddir = W, newdir = NESW
};

static void initializeQueue(Queue* q) {
  q->front = -1;
  q->rear = 0;
}

static bool isEmpty(Queue* q) {
  return (q->front == q->rear - 1);
}

static bool isFull(Queue* q) {
  return (q->rear == QUEUE_MAX_SIZE);
}

static void enqueue(Queue* q, Point value) {
  if (isFull(q)) {
    printf("Queue is full\n");
    return;
  }
  q->items[q->rear] = value;
  q->rear++;
}

static Point dequeue(Queue* q) {
  if (isEmpty(q)) {
    printf("Queue is empty\n");
    return (Point){0, 0};
  }
  q->front++;
  return q->items[q->front];
}

static bool inside_maze(const Maze* maze, Point p) {
  return p.x >= 0 && p.x <= ((int)maze->width - 1) && p.y >= 0 &&
         p.y <= ((int)maze->height - 1);
}

static bool is_exit(const Maze* maze, Point p) {
  return !(p.x > 0 && p.x < ((int)maze->width - 1) && p.y > 0 &&
           p.y < ((int)maze->height - 1)) &&
         maze->grid[p.y][p.x] == ' ';
}

static int breadth_first_search(const Maze* maze, Point* start) {
  if (maze == NULL)
    return -1;
  if (maze->grid == NULL)
    return -1;
  bool found = false;
  bool visited[maze->height][maze->width];
  for (unsigned i = 0; i < maze->height; i++) {
    for (unsigned j = 0; j < maze->width; j++) {
      visited[i][j] = false;
      if (maze->grid[i][j] != '#' && maze->grid[i][j] != ' ') {
        start->y = i;
        start->x = j;
      }
    }
  }
  Point parent[maze->height][maze->width];
  Queue* q = (Queue*)malloc(sizeof(Queue));
  initializeQueue(q);
  enqueue(q, *start);
  visited[start->y][start->x] = true;
  Point p;
  while (!isEmpty(q)) {
    p = dequeue(q);
    if (is_exit(maze, p)) {
      maze->grid[p.y][p.x] = '.';
      found = true;
      break;  // am Rand
    }
    for (int k = 1; k <= 4; k++) {
      int dx, dy;
      switch (k) {
        case 1:
          dx = 1;
          dy = 0;
          break;
        case 2:
          dx = -1;
          dy = 0;
          break;
        case 3:
          dx = 0;
          dy = 1;
          break;
        case 4:
          dx = 0;
          dy = -1;
          break;
      }
      Point n = (Point){p.x + dx, p.y + dy};
      if (inside_maze(maze, n) && maze->grid[n.y][n.x] == ' ' &&
          !visited[n.y][n.x]) {
        visited[n.y][n.x] = true;
        parent[n.y][n.x] = p;
        enqueue(q, n);
      }
    }
  }
  int steps;
  if (found) {
    steps = 1;
    while (!(p.x == start->x && p.y == start->y)) {
      maze->grid[p.y][p.x] = '.';
      p = parent[p.y][p.x];
      steps++;
    }
  } else
    steps = -1;
  free(q);
  return steps;
}

static char* create_path(const Maze* maze, Point* start, char* path) {
  Point p = *start;
  Point np;
  Direction nd;
  char c = maze->grid[p.y][p.x];
  Direction d = (c == '^' ? N : (c == '>' ? E : (c == '<' ? W : S)));
  while (!is_exit(maze, p)) {
    if (maze->grid[p.y][p.x - 1] == '.') {
      nd = W;
      np = (Point){p.x - 1, p.y};
    } else if (maze->grid[p.y][p.x + 1] == '.') {
      nd = E;
      np = (Point){p.x + 1, p.y};
    } else if (maze->grid[p.y - 1][p.x] == '.') {
      nd = N;
      np = (Point){p.x, p.y - 1};
    } else if (maze->grid[p.y + 1][p.x] == '.') {
      nd = S;
      np = (Point){p.x, p.y + 1};
    } else {
      printf("Something went wrong in create_path\n");
      return path;
    }
    strcat(path, move[d][nd]);
    d = nd;
    p = np;
    if (maze->grid[p.y][p.x] == '.')
      maze->grid[p.y][p.x] = ' ';
  }
  return path;
}

char* escape(const Maze* maze) {
  Point start;
  int steps = breadth_first_search(maze, &start);
  if (steps == -1)
    return NULL;
  char* path = calloc(steps * 2 + 1, sizeof(char));
  return create_path(maze, &start, path);
}
