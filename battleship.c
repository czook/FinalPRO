#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
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
}carrier;

struct patrol{
    int point1;
    int point2;
}patrol;

struct boat{
    int point1;
}boat;

struct Ships{
    carrier c;
    patrol p;
    boat b;
}Ships;

void main(){
    int playerGrid[BOARD_LENGTH][BOARD_WIDTH];
    int computerGrid[BOARD_LENGTH][BOARD_WIDTH];
    Ships compShips;
    Ships playerShips;

}