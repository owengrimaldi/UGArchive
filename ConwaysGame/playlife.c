// Owen Grimaldi - ogrimald
// Life: playlife.c

#include <stdio.h>
#include "lifefunc.h"

int main(int argc, char *argv[]) {

  char currentBoard[MAXBOARDSIZE][MAXBOARDSIZE];
  int keepGoing = 1;

  if (argc == 1) {
    setFreshBoard(currentBoard);
    while (keepGoing) {
      system("clear");
      displayBoard(currentBoard);
      keepGoing = interactiveCommand(currentBoard);
    }
  }

  if (argc == 2) {
    char fileName[MAXFILENAME];
    int i;
    int valid;
    setFreshBoard(currentBoard);

    for (i = 0; i < strlen(argv[1]); i++) {
      fileName[i] = argv[1][i];
    }
    valid = batchCommand(currentBoard, fileName);
    if (valid) displayBoard(currentBoard);
  }

  if (argc == 3) {
    printf("Too many arguments!\n");
  }

  return 0;
}