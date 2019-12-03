#include<stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <Windows.h>
//uncomment one of these includes depending on the computer you're using 
//(add one if you have something different)
//#include <ncurses/ncurses.h> //lab computers
#include<curses.h> //corbin's laptop

#define BOARD_LENGTH 10
#define BOARD_WIDTH 10
//structs are used to check if parts of the boats are hit.
//using int {varible} = 1 or 0 depending if it is true or false
struct carrier{
    int point1;
    int point2;
    int point3;
};

struct patrol{
    int point1;
    int point2;
};

struct boat{
    int point1;
};

struct ships{
    struct carrier c;
    struct patrol p;
    struct boat b;
};

void main(){
    int playerGrid[BOARD_LENGTH][BOARD_WIDTH];
    int computerGrid[BOARD_LENGTH][BOARD_WIDTH];
    struct ships compShips;
    struct ships playerShips;

}