// Owen Grimaldi - ogrimald
// Life: lifefunc.h

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define MAXBOARDSIZE 40
#define MAXCOMMANDSIZE 20
#define MAXFILENAME 20
#define MAXCOMMANDNUM 100

void displayBoard(char currentBoard[MAXBOARDSIZE][MAXBOARDSIZE]);
void setFreshBoard(char currentBoard[MAXBOARDSIZE][MAXBOARDSIZE]);
int interactiveCommand(char testArray[MAXBOARDSIZE][MAXBOARDSIZE]);
int inBoard(int xPos, int yPos);
void nextGameTurn(char currentBoard[MAXBOARDSIZE][MAXBOARDSIZE]);
void playContinuous(char currentBoard[MAXBOARDSIZE][MAXBOARDSIZE]);
int batchCommand(char currentBoard[][MAXBOARDSIZE], char fileName[MAXFILENAME]);