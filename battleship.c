//uncomment one of these includes depending on the computer you're using
//(add one if you have something different)
//#include <ncurses/ncurses.h> //lab computers
#include <curses.h> //corbin's laptop
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//#include <Windows.h>
//uncomment one of these includes depending on the computer you're using
//(add one if you have something different)
//#include <ncurses/ncurses.h> //lab computers

#define BOARD_LENGTH 10
#define BOARD_WIDTH 10
#define SHIP_CHAR '0'
#define SHIP_HIT 'X'
#define SHIP_MISS '$'
#define BLANK '*'

void draw_character(int row, int column, char use)
{
    mvaddch(row, column, use);
    refresh();
}

void draw_string(int row, int column, char *string){
    mvprintw(row, column, string);
    refresh();
}

void displayCurrentBoard(int gridData[BOARD_LENGTH][BOARD_WIDTH], int x, int y)
{
    /*
    board looks like
    $ = ship
    X = ship hit
    O = misses from other player
    P = position of x and y (for testing)
 P  1 2 3 4 5 6 7 8 9 10
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

PLACE SHIP (1): (input)  (ex D4)
ship types:
    */
    
    //print border info
    char *temp1 = " 0 1 2 3 4 5 6 7 8 9";
	char *temp2 = "--------------------";
    draw_string(y, x + 3,temp1);
    draw_string(y + 1, x + 3,temp2);

    char *temp3 = " |";

    char displayChar = BLANK;

    //display everything inside border
    for(int i = 0; i < BOARD_LENGTH; i++){
        draw_character(y+2+i,x,65+i);       //print A, B, C, etc
        draw_string(y+2+i,x+1,temp3);       //print " |"
		for (int j = 0; j < BOARD_WIDTH; j++) {
	        //print information based on arrays
            //switch to detect current value to print
            switch(gridData[i][j]){
                case 0:
                    displayChar = BLANK;
                    break;
                case 1:
                    displayChar = SHIP_CHAR;
                    break;
                case 2:
                    displayChar = SHIP_HIT;
                    break;
                case 3:
                    displayChar = SHIP_MISS;
                    break;
                default:
                printf("ERROR in gridData");
            }
            draw_character(y+2+i,x+4+j*2,displayChar); //draw switched character
		}       
    }
}

int placeShip(int gridData[BOARD_LENGTH][BOARD_WIDTH],int x, int y, int shipNum){
    //ship number size is 1,2, or 3
    switch(shipNum){
        case 1: //1x1 - boat
            if(gridData[x][y] == 1) return 0; //if already a boat don't do anything
            gridData[x][y] = 1;
            break;
        case 2: //2x1 - patrol
            if(gridData[x][y] == 1 || gridData[x+1][y] == 1) return 0;
            if(x >= 9) return 0;
            gridData[x][y] = 1;
            gridData[x+1][y] = 1;
            break;
        case 3: //3x1 - carrier
            if(gridData[x][y] == 1 || gridData[x+1][y] == 1 || gridData[x+2][y] == 1) return 0;
            if(x >= 8) return 0;
            gridData[x][y] = 1;
            gridData[x+1][y] = 1;
            gridData[x+2][y] = 1;
            break;
    }
    return 1;
}
//shoot function duh!
int shoot(int gridData[BOARD_LENGTH][BOARD_WIDTH],int x, int y){
    if(gridData[x][y] == 1){ //If there is a ship hidden there
        return 1;
    } else if (gridData[x][y] == 2 || gridData[x][y] == 3){ //If the spot has already been guessed
		return 2;
    } else{ //If there is no ship there
		return 0;
	}
}

//tests user input if it fits certain constraints
//for DEMO, comment out return 0's
int testInput(char ch[]){
    //if user enters a letter not within range (65 to 74)
    if(!(ch[0] > 64 && ch[0] < 75)){
        return 0;   
    }

    //if user enters a number not within range (48 to 57)
    if(!(ch[1] > 47 && ch[1] < 58)){
        return 0;
    }
        
    //if ch is longer or less then 2
    if(strlen(ch) != 2){
        return 0;
    }
    return 1;
}

void main()
{
	//Initialize screen
	initscr();

    time_t t;
	srand((unsigned) time(&t));

	//1 = ship
	//2 = miss
	int playerGrid[BOARD_LENGTH][BOARD_WIDTH];
	int playerGuessGrid[BOARD_LENGTH][BOARD_WIDTH];
	int computerGrid[BOARD_LENGTH][BOARD_WIDTH];
	int computerGuessGrid[BOARD_LENGTH][BOARD_LENGTH];

	//location of displays
	int playerBoardX = 5;
	int playerBoardY = 1;
	int playerGuessX = 35;
	int playerGuessY = 1;
	int cpuBoardX = 65;
	int cpuBoardY = 1;
	int cpuGuessX = 95;
	int cpuGuessY = 1;

	//set everything to 0 (for sanity's sake) Might not need this
	for (int i = 0; i < BOARD_LENGTH; i++) {
		for (int j = 0; j < BOARD_WIDTH; j++) {
			playerGrid[i][j] = 0;
			computerGrid[i][j] = 0;
            playerGuessGrid[i][j] = 0;
			computerGuessGrid[i][j] = 0;
		}
	}

	//initial displays 
	displayCurrentBoard(playerGrid, playerBoardX, playerBoardY);
	displayCurrentBoard(playerGuessGrid, playerGuessX, playerGuessY);
	displayCurrentBoard(computerGrid, cpuBoardX, cpuBoardY); //Comment when actually playing
	displayCurrentBoard(computerGuessGrid, cpuGuessX, cpuGuessY); //Comment when actually playing

    int placeX, placeY;

	//place user ships
	char* ch;
	for (int i = 1; i < 4; i++) {
		mvprintw(14, 0, "Input where to put your ship %d; Example D4: ", i);
		getstr(ch); //Gets input from the player's keyboard
        
        //if input is NOT acceptable
        if(!testInput(ch)){
            mvprintw(14, 44, "                   "); //remove previous input
            i -= 1;
            continue; 
        }
        
        //main placement
        placeX = ch[0]-64-1;
        placeY = ch[1]-48;
        
        if(!placeShip(playerGrid, placeX, placeY, i)){//if it fails to place
            i = i - 1;  //redo last step
        } 
	
        mvprintw(14, 44, "                      "); //remove previous input
        //update board every time
        displayCurrentBoard(playerGrid, playerBoardX, playerBoardY);
	}

	mvprintw(14, 0, "                                             "); //Clear line after placing ships is done
    
    //place bot ships (randomly)
    for(int j = 1; j < 4; j++){
        //if is overlapping
        if(!placeShip(computerGrid,rand()%10,rand()%10,j)){
            j -= 1;
            continue;
        }
        displayCurrentBoard(computerGrid, cpuBoardX, cpuBoardY); //Comment when actually playing
    }
    
	int playerScore = 0; //Score 1-6
	int computerScore = 0; //Score 1-6

    //Main loop (game start)
    while (playerScore < 6 && computerScore < 6){
        //loop through player and ship picking locations to shoot
        
		//If guess is valid 
		int endTurn = 0;
        //player shoot
		do {
			mvprintw(14, 0, "Pick a location to shoot: ");
			getstr(ch);

            //if input is NOT acceptable
            if(!testInput(ch)){
                mvprintw(14, 26, "              "); //remove previous input
                continue; 
            }

			if(shoot(computerGrid, ch[0] - 64 - 1, ch[1] - 48) == 1) { //if it hits
				endTurn = 1; 
				playerGuessGrid[ch[0] - 64 - 1][ch[1] - 48] = 2;
				computerGrid[ch[0] - 64 - 1][ch[1] - 48] = 2;
				playerScore++;
			}else if(shoot(computerGrid, ch[0] - 64 - 1, ch[1] - 48) == 2) { //If invalid guess
				endTurn = 0;
			}else{ //If miss
				endTurn = 1;
				playerGuessGrid[ch[0] - 64 - 1][ch[1] - 48] = 3;
				computerGrid[ch[0] - 64 - 1][ch[1] - 48] = 3;
			}
            mvprintw(14, 26, "               "); //remove previous input
		} while (!endTurn);
		
		displayCurrentBoard(playerGrid, playerBoardX, playerBoardY);
		displayCurrentBoard(playerGuessGrid, playerGuessX, playerGuessY);
		displayCurrentBoard(computerGrid, cpuBoardX, cpuBoardY); //Comment when actually playing
		displayCurrentBoard(computerGuessGrid, cpuGuessX, cpuGuessY); //Comment when actually playing

        //bot guessing
        while(1){
            int xGuess = rand() % 10;
            int yGuess = rand() % 10;
            //if that coord is a ship mark with hit and mark up the score
            if (playerGrid[xGuess][yGuess] == 1){
                playerGrid[xGuess][yGuess] = 2;
                computerGuessGrid[xGuess][yGuess] = 2;
                computerScore++;
                break;    
            }
            //if that coord is blank mark ship
            else if (playerGrid[xGuess][yGuess] == 0){
                playerGrid[xGuess][yGuess] = 3;
                computerGuessGrid[xGuess][yGuess] = 3;
                break;
            }
        }
		displayCurrentBoard(playerGrid, playerBoardX, playerBoardY);
		displayCurrentBoard(playerGuessGrid, playerGuessX, playerGuessY);
		displayCurrentBoard(computerGrid, cpuBoardX, cpuBoardY); //Comment when actually playing
		displayCurrentBoard(computerGuessGrid, cpuGuessX, cpuGuessY); //Comment when actually playing
    }

    //Exit screen
    endwin();

	if (playerScore == 6) {
		printf("You Win!\n");
	} else {
		printf("The Computer Beat You :(\n");
	}
}