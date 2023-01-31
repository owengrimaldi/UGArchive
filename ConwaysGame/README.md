## Conway's Game of Life

In the same semester as Engineering Computing (Spring 2022), I also took a class called Fundamentals of Computing. This class was meant to be taken a semester later, but I opted to take it early to better mesh my knowledge of Python with fundamentals from C. The class covered much of the basics also taught in Engineering Computing, such as basic loops but also went into depth about memory management, external libraries, and even graphics libraries made in-house.

Conway's Game of Life was by far one of the most difficult programs I had ever written in up to this point. The goal of the project was to recreate a fully functional version of the classic Conway's Game of Life in C, a mathematical game revolving around tiles on a board acting through stages of natural selection. Each tile has conditions as to whether or not they become alive, stay alive, and die set about how many alive tiles surround them. With these conditions, you can create cool scenes where tiles generate other tiles, make flying ships, flicker in cool patterns, move around like cells, and more!

# Usage

Using the Makefile in the directory, you can compile an executable of playlife. This executable can be run with or without arguments at the command line.

Without arguments, the game opens with an empty board prompting you for a command from the following:
1. Add a Tile
    * "a #x #y"
    * #x and #y can be replaced with any value from 0 to MAXBOARDSIZE-1 (default 40), acting like a coordinate system from the tiles from top left to bottom right. X relates to columns and Y to rows.

2. Remove a Tile
    * "r #x #y"
    * #x and #y can be replaced with any value from 0 to MAXBOARDSIZE-1 (default 40), acting like a coordinate system from the tiles from top left to bottom right. X relates to columns and Y to rows.

3. Next Turn
    * "n"
    * Runs a turn of the Game of Life, enacting the rules of the game on every tile and presenting you with the aftermath board.

4. Run Continuous Turns
    * "p"
    * Runs turns continuously until the user stops the program with CTRL-C. Most effective with scenes and larger, more involved boards.

5. Quit
    * "q"
    * Quits the program from any board state, except when the program is running continuously.