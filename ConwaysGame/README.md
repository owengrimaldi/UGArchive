# Conway's Game of Life

In the same semester as Engineering Computing (Spring 2022), I also took a class called Fundamentals of Computing. This class was meant to be taken a semester later, but I opted to take it early to better mesh my knowledge of Python with fundamentals from C. The class covered much of the basics also taught in Engineering Computing, such as basic loops but also went into depth about memory management, external libraries, and even graphics libraries made in-house.

Conway's Game of Life was by far one of the most difficult programs I had ever written in up to this point. The goal of the project was to recreate a fully functional version of the classic Conway's Game of Life in C, a mathematical game revolving around tiles on a board acting through stages of natural selection. Each tile has conditions as to whether or not they become alive, stay alive, and die set about how many alive tiles surround them. With these conditions, you can create cool scenes where tiles generate other tiles, make flying ships, flicker in cool patterns, move around like cells, and more!

## Usage

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


    
With a command line argument, you can initiate a scene in the progam like so:
```
./playlife /scenes/scene3.txt
```
Doing so loads the game with every command listed in the scene text file. The provided 5 scenes conclude with the "p" command, meaning they start in a continuous state of play as a demonstration of the more in-depth parts of Conway's. Here are 3 of the provided scenes, involving movement into static states, flyers, and repetitive patterns:


https://user-images.githubusercontent.com/67028882/215893553-8faada96-ad0e-4bb6-bf53-bac80c1160cf.mp4

https://user-images.githubusercontent.com/67028882/215893559-79077958-9b77-4e88-9e6b-22f35e44e109.mp4

https://user-images.githubusercontent.com/67028882/215893572-4ae6d3a3-177b-4e08-87de-11fbd9b109d5.mp4


  
