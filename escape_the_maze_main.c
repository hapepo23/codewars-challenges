/*
4 kyu
Escape the maze
https://www.codewars.com/kata/5877027d885d4f6144000404
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_Maze {
  unsigned height, width;
  char** grid;
} Maze;

char* escape(const Maze* maze);

Maze* newEmptyMaze(void) {
  Maze* m = calloc(1, sizeof(Maze));
  return m;
}

Maze* loadMaze(Maze* m, unsigned height, unsigned width, char* grid) {
  if (m->grid) {
    for (unsigned i = 0; i < m->height; i++) {
      free(m->grid[i]);
    }
    free(m->grid);
  }
  m->height = height;
  m->width = width;
  m->grid = calloc(height, sizeof(char*));
  for (unsigned i = 0; i < height; i++) {
    m->grid[i] = calloc(width + 1, sizeof(char));
  }
  unsigned k = 0;
  for (unsigned i = 0; i < height; i++)
    for (unsigned j = 0; j < width; j++)
      m->grid[i][j] = grid[k++];
  return m;
}

void printMaze(Maze* m) {
  for (unsigned i = 0; i < m->height; i++) {
    printf("%s\n", m->grid[i]);
  }
}

void deleteMaze(Maze* m) {
  if (m->grid) {
    for (unsigned i = 0; i < m->height; i++) {
      free(m->grid[i]);
    }
    free(m->grid);
  }
  free(m);
}

void testMaze(Maze* m, int solvable, char* expected) {
  char* your_answer = NULL;
  your_answer = escape(m);
  printMaze(m);
  if (solvable) {
    printf(
        "Your answer: %s\n"
        "Expected   : %s\n%s\n\n",
        your_answer, expected,
        strcmp(your_answer, expected) == 0 ? "OK" : "WRONG");
  } else {
    printf("Not solvable, Answer = %p, should be (nil)\n%s\n\n", your_answer,
           your_answer == expected ? "OK" : "WRONG");
  }
  if (your_answer)
    free(your_answer);
}

int main(void) {
  Maze* m;
  m = newEmptyMaze();
  m = loadMaze(m, 3, 3,
               "# #"
               " > "
               "# #");
  testMaze(m, 1, "F");
  m = loadMaze(m, 3, 10,
               "##########"
               "#>       #"
               "######## #");
  testMaze(m, 1, "FFFFFFFRF");
  m = loadMaze(m, 3, 11,
               "# #########"
               "#        >#"
               "###########");
  testMaze(m, 1, "BFFFFFFFFRF");
  m = loadMaze(m, 3, 11,
               "# #########"
               "#    ^    #"
               "######### #");
  testMaze(m, 1, "RFFFFRF");
  m = loadMaze(m, 4, 9,
               "####### #"
               "#>#   # #"
               "#   #   #"
               "#########");
  testMaze(m, 1, "RFLFFLFRFFRFLFFLFF");
  m = loadMaze(m, 8, 10,
               "##########"
               "#        #"
               "#  ##### #"
               "#  #   # #"
               "#  #^# # #"
               "#  ### # #"
               "#      # #"
               "######## #");
  testMaze(m, 1, "FRFFRFFFRFFFFRFFFFFRFFFFFFRFFFFFF");
  m = loadMaze(m, 21, 41,
               "#########################################"
               "#<    #       #     #         # #   #   #"
               "##### # ##### # ### # # ##### # # # ### #"
               "# #   #   #   #   #   # #     #   #   # #"
               "# # # ### # ########### # ####### # # # #"
               "#   #   # # #       #   # #   #   # #   #"
               "####### # # # ##### # ### # # # #########"
               "#   #     # #     # #   #   # # #       #"
               "# # ####### ### ### ##### ### # ####### #"
               "# #             #   #     #   #   #   # #"
               "# ############### ### ##### ##### # # # #"
               "#               #     #   #   #   # #   #"
               "##### ####### # ######### # # # ### #####"
               "#   # #   #   # #         # # # #       #"
               "# # # # # # ### # # ####### # # ### ### #"
               "# # #   # # #     #   #     # #     #   #"
               "# # ##### # # ####### # ##### ####### # #"
               "# #     # # # #   # # #     # #       # #"
               "# ##### ### # ### # # ##### # # ### ### #"
               "#     #     #     #   #     #   #   #    "
               "#########################################");
  testMaze(m, 1,
           "BFFFFRFFFFLFFRFFLFFLFFFFLFFRFFRFFFFFFRFFRFFLFFFFFFLFFFFLFFLFFRFFRFF"
           "FFFFRFFFFRFFLFFLFFFFLFFRFFFFLFFRFFLFFRFFRFFFFRFFLFFLFFRFFFFFFFFLFFL"
           "FFRFFFFFFLFFRFFRFFFFLF");
  m = loadMaze(m, 9, 9,
               "  #####  "
               " #     # "
               "#       #"
               "#       #"
               "#   ^   #"
               " #     # "
               "  #   #  "
               "   # #   "
               "    #    ");
  testMaze(m, 0, NULL);
  deleteMaze(m);
  return 0;
}
