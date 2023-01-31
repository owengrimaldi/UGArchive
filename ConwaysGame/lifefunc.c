// Owen Grimaldi - ogrimald
// Life: lifefunc.c

#include <stdio.h>
#include <string.h>
#include "lifefunc.h"

void setFreshBoard(char currentBoard[][MAXBOARDSIZE]) {

  //This func sets the initial array values to blanks and prints the board as such
  int i, j;

  for (i = 0; i < MAXBOARDSIZE; i++) {
    for (j = 0; j < MAXBOARDSIZE; j++) {
      currentBoard[i][j] = ' ';
    }
  }
}

//This function displays the current state of the board
void displayBoard(char testArray[][MAXBOARDSIZE]) {

  int i, j;

  for (i = 0; i < MAXBOARDSIZE+2; i++){ //top border
    printf("--");
  }

  for (i = 0; i < MAXBOARDSIZE; i++) { //prints side borders plus row of board
    printf("\n| ");
    for (j = 0; j < MAXBOARDSIZE; j++) {
      printf("%c ", testArray[i][j]);
    }
    printf("|");
  }

  printf("\n");
  for (i = 0; i < MAXBOARDSIZE+2; i++){ //prints bottom border
    printf("--");
  }
  printf("\n");
}


//This function handles all command line input commands
int interactiveCommand(char testArray[MAXBOARDSIZE][MAXBOARDSIZE]) {
  char commandInput[MAXCOMMANDSIZE];

  printf("Enter a command: "); //prompts command
  fgets(commandInput, MAXCOMMANDSIZE, stdin);
  commandInput[strlen(commandInput)-1] = '\0'; //removes newline char at end, makes it easier for use
  char command[1];
  int x = 99, y = 99;
  //if y is still 99, then the user didnt enter a second coordinate, prompt an error

  //Split input into three variables (string, int, int)
  sscanf(commandInput, "%s %d %d", command, &x, &y);

  //Switch for command letter
  switch(command[0]) {
    case 'a':
      if (x >= MAXBOARDSIZE || y >= MAXBOARDSIZE || x < 0 || y < 0) {
        printf("One of your coordinates was not on the board! Please try again. ((x, y) from 0-39)\n");
        interactiveCommand(testArray);
      }
      else {
        testArray[y][x] = 'x'; //changes empty cell to live at cords
      }
      break;
    case 'r':
      if (x >= MAXBOARDSIZE || y >= MAXBOARDSIZE || x < 0 || y < 0) {
        printf("One of your coordinates was not on the board! Please try again. ((x, y) from 0-39)\n");
        interactiveCommand(testArray);
      }
      else {
        testArray[y][x] = ' ';
      }
      break;
    case 'q':
      printf("Thanks for playing!\n"); //prints and makes keepGoing false
      return 0;
      break;
    case 'n':
      nextGameTurn(testArray); //plays one turn of game rules
      break;
    case 'p':
      playContinuous(testArray); //consistently plays turns on sleep timer
      break;
    default:
      printf("\nCommand not recognized.\n"); //prompts for another command
      interactiveCommand(testArray);
      break;
  }

  printf("\n");
  return 1;
}

void nextGameTurn(char currentBoard[MAXBOARDSIZE][MAXBOARDSIZE]) {

  int counter;
  int i, j;
  int y, x;
  char tempBoard[MAXBOARDSIZE][MAXBOARDSIZE];
  int xUpLeft, yUpLeft, xUpMid, yUpMid, xUpRight, yUpRight;
  int xMidLeft, yMidLeft, xMidRight, yMidRight;
  int  xDownLeft, yDownLeft, xDownMid, yDownMid, xDownRight, yDownRight;
  int testCount = 0;

  for (i = 0; i < MAXBOARDSIZE; i++) { //SETS TEMP BOARD
    for (j = 0; j < MAXBOARDSIZE; j++) {
      tempBoard[i][j] = currentBoard[i][j];
    }
  }

  for (y = 0; y < MAXBOARDSIZE; y++) { //CHECKS FOR NEIGHBORS
    for (x = 0; x < MAXBOARDSIZE; x++) {
      counter = 0;
      //Sets position values of neighbor cells for readability
      //Each variable is the coordinate of every surrounding cell to current cell
      xUpLeft = x - 1;
      yUpLeft = y - 1;

      xUpMid = x;
      yUpMid = y - 1;

      xUpRight = x + 1;
      yUpRight = y - 1;

      xMidLeft = x - 1;
      yMidLeft = y;

      xMidRight = x + 1;
      yMidRight = y;

      xDownLeft = x - 1;
      yDownLeft = y + 1;

      xDownMid = x;
      yDownMid = y + 1;

      xDownRight = x + 1;
      yDownRight = y + 1;

      //if in board, add to counter for each of 8 surrounding squares
      if (inBoard(xUpLeft, yUpLeft)) { 
        if (currentBoard[yUpLeft][xUpLeft] == 'x') {
          counter++;
        }
      }

      if (inBoard(xUpMid, yUpMid)) {
        if (currentBoard[yUpMid][xUpMid] == 'x') {
          counter++;
        }
      }
      if (inBoard(xUpRight, yUpRight)) {
        if (currentBoard[yUpRight][xUpRight] == 'x') {
          counter++;
        }
      }
      if (inBoard(xMidLeft, xMidLeft)) {
        if (currentBoard[yMidLeft][xMidLeft] == 'x') {
          counter++;
        }
      }
      if (inBoard(xMidRight, yMidRight)) {
        if (currentBoard[yMidRight][xMidRight] == 'x') {
          counter++;
        }
      }
      if (inBoard(xDownLeft, yDownLeft)) {
        if (currentBoard[yDownLeft][xDownLeft] == 'x') {
          counter++;
        }
      }
      if (inBoard(xDownMid, yDownMid)) {
        if (currentBoard[yDownMid][xDownMid] == 'x') {
          counter++;
        }
      }
      if (inBoard(xDownRight, yDownRight)) {
        if (currentBoard[yDownRight][xDownRight] == 'x') {
          counter++;
        }
      }
      //IF MEETS GAME RULES, CHANGE SPOT ON TEMP BOARD
      //More than two neighbors and dead, become alive
      if (counter > 2 && tempBoard[y][x] == ' ') {
        tempBoard[y][x] = 'x';
      }
      //If has 2 or 3 live neighbors and alive, stay alive
      if ((counter == 2 || counter == 3) && (tempBoard[y][x] == 'x')) {
        tempBoard[y][x] = 'x';
      }
      //If greater than 3 or less than 2 neighbors, become dead
      if ((counter > 3 || counter < 2) && (tempBoard[y][x] == 'x')) {
        tempBoard[y][x] = ' ';
      }
    }
  }

  for (i = 0; i < MAXBOARDSIZE; i++) { //SETS CURRENT BOARD TO TEMP
    for (j = 0; j < MAXBOARDSIZE; j++) {
      currentBoard[i][j] = tempBoard[i][j];
    }
  }
}

int inBoard(int xPos, int yPos) { //Checks if a value is in the board size or not
  if (xPos >= 0 && xPos < MAXBOARDSIZE && yPos >= 0 && yPos < MAXBOARDSIZE) {
    return 1;
  }
  else {
    return 0;
  }
}

//Runs nextGameTurn infinitely with a sleep pause, clears terminal
void playContinuous(char currentBoard[][MAXBOARDSIZE]) {
  while(1) {
  usleep(200000);
  system("clear");
  nextGameTurn(currentBoard);
  displayBoard(currentBoard);
  }
}

//Uses a lot of the same code as next game turn
int batchCommand(char currentBoard[][MAXBOARDSIZE], char fileName[MAXFILENAME]) {

  char commandInput[MAXCOMMANDNUM][MAXCOMMANDSIZE];
  FILE *fp;
  int p = 0;
  int numCommands = 0;

  //Takes file names
  fp = fopen(fileName, "r");
  if (!fp) {
    printf("File name not valid!\n");
    return 0;
  }
  //Until end of file, take each line of text file and add it as a command. Remove newline at end
  while (1) {
    if (feof(fp)) break;
    fgets(commandInput[p], MAXCOMMANDSIZE, fp);
    commandInput[p][strlen(commandInput[p])-1] = '\0'; //removes newline char at end, makes it easier for use
    p++;
    numCommands++;
  }

  //For number of commands from file, read command and execute based on command
  for (p = 0; p < numCommands; p++) {

    char command[1];
    int x = 99, y = 99; //if y is still 99, then the user didnt enter a second coordinate, prompt an error

    sscanf(commandInput[p], "%s %d %d", command, &x, &y);

    switch(command[0]) {
      case 'a':
        currentBoard[y][x] = 'x';
        break;
      case 'r':
        currentBoard[y][x] = ' ';
        break;
      case 'p':
        playContinuous(currentBoard);
        break;
      default:
        break;
    }
  }
  printf("\n");
  return 1;
}