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
#define shipChar '$'
#define shipHit 'X'
#define shipMiss '0'
#define blank '*'
//structs are used to check if parts of the boats are hit.
//using int {varible} = 1 or 0 depending if it is true or false
struct carrier{
	int points[3][2];
};

struct patrol{
	int points[2][2];
};

struct boat{
	int points[1][2];
};

struct ships{
    struct carrier c;
    struct patrol p;
	struct boat b;
};

void draw_character(int row, int column, char use)
{
	mvaddch(row, column, use);
	refresh();
}

void draw_string(int row, int column, char *string){
    mvprintw(row, column, string);
    refresh();
}

void displayCurrentBoard(int gridData[BOARD_LENGTH][BOARD_WIDTH], int x, int y){
    /*
    board looks like
    X = ship parts
    O = misses from other player
    P = position of x and y
 P	1 2 3 4 5 6 7 8 9 10
    --------------------
 A | * * * * * * * * * *
 B | * * * * * * * * * *
 C | * * * * * * * * * *
 D | * * * * * * * * * *
 E | * * * * * * * * * *
 F | * * * * * * * * * *
 G | * * * * * * * * * *
 H | * * * * * * * * * *
 I | * * * * * * * * * *
 J | * * * * * * * * * *


    printf("%d\n",gridData[1][1]);
    printf("%d\n",gridData[0][1]);
    printf("%d\n",gridData[2][3]);
	*/

    char tmp = 'P'; //placeholder representing starting reference location
    draw_character(x,y,tmp);

    
    //print border info
    char *temp1 = "1 2 3 4 5 6 7 8 9 10";
	char *temp2 = "--------------------";
    draw_string(y, x + 3,temp1);
    draw_string(y + 1, x + 3,temp2);

    char *temp3 = " |";

    char empty = '*';

    //display everything inside border
    for(int i = 0; i < BOARD_LENGTH; i++){
        draw_character(y+2+i,x,65+i);       //print A, B, C, etc
        draw_string(y+2+i,x+1,temp3);       //print " |"
		for (int j = 0; j < BOARD_WIDTH; j++) {
			//print the empty areas
		}
    }
}

void placeShips(int *gridData, struct carrier c, struct patrol p, struct boat b){
	//Starting ship placement at [0][0] 
	//int x y;
	//placing down the Carrier
	/*
	if (y+2)
	gridData[y][x] = shipChar;
	gridData[y+1][x] = shipChar;
	gridData[y+2][x] = shipChar;
	*/
}

void main(){
	//Initialize screen
	initscr();
	
	//1 = ship
    //2 = miss
    int playerGrid[BOARD_LENGTH][BOARD_WIDTH];
    int computerGrid[BOARD_LENGTH][BOARD_WIDTH];
    struct ships compShips;
    struct ships playerShips;

    //set everything to 0 (for sanity's sake)
    for(int i = 0; i < BOARD_LENGTH; i++){
        for(int j = 0; j < BOARD_WIDTH; j++){
            playerGrid[i][j] = 0;
            computerGrid[i][j] = 0;
        }
    }

	//initial displays
	displayCurrentBoard(playerGrid, 1, 1);
	displayCurrentBoard(computerGrid, 30, 1);

	//Main loop
	while (1) {

	}

	//Exit screen
	endwin();
}
