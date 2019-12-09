//uncomment one of these includes depending on the computer you're using
//(add one if you have something different)
//#include <ncurses/ncurses.h> //lab computers
#include <curses.h> //corbin's laptop
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <Windows.h>
//uncomment one of these includes depending on the computer you're using
//(add one if you have something different)
//#include <ncurses/ncurses.h> //lab computers

#define BOARD_LENGTH 10
#define BOARD_WIDTH 10
#define SHIP_CHAR '$'
#define SHIP_HIT 'X'
#define SHIP_MISS '0'
#define BLANK '*'
//structs are used to check if parts of the boats are hit.
//using int {varible} = 1 or 0 depending if it is true or false
/*
struct carrier
{
    int points[3][2];
};

struct patrol
{
    int points[2][2];
};

struct boat
{
    int points[1][2];
};

struct ships
{
    struct carrier c;
    struct patrol p;
    struct boat b;
};
*/

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

    char tmp = 'P'; //placeholder representing starting reference location
    draw_character(y,x,tmp); //can take out later
    
    //print border info
    char *temp1 = " 1 2 3 4 5 6 7 8 9 10";
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
                printf("ERROR IN gridData");
            }
            draw_character(y+2+i,x+4+j*2,displayChar); //draw switched character
		}       
    }
}
/*
void placeShips(int *gridData, struct carrier c, struct patrol p, struct boat b){
    //

    /*
    //Starting ship placement at [0][0]
	int x = 0, y = 0;
    
	
    //moving the ships on keypress are hopefully FINISHED
    //Still need to check if the ships are on top of each other.
    //(The current numbers(0,7,9) are trying to be the limits of the 10x10 board)
    //place carrier while loop
    while (1){
        int ch = getch();
        if (ch == 'w'){
            if(y == 0){
                y = 7;
                
                gridData[0][x] = '*';
                gridData[1][x] = '*';
                gridData[2][x] = '*';
            }
            else{
                gridData[y][x] = '*';
                gridData[y+1][x] = '*';
                gridData[y+2][x] = "*";
                y--;
        
            }
        }
        else if (ch == 's'){
            if (y == 7){
                y = 0;
                
                gridData[7][x] = '*';
                gridData[8][x] = '*';
                gridData[9][x] = '*';
            }
            else{
                gridData[y][x] = '*';
                gridData[y+1][x] = '*';
                gridData[y+2][x] = "*";
                y++;
                
            }
        }
        else if (ch == 'd'){
            if (x == 9){
                x = 0;
                
                gridData[y][9] = '*';
                gridData[y+1][9] = '*';
                gridData[y+2][9] = '*';
            }
            else{
                gridData[y][x] = '*';
                gridData[y+1][x] = '*';
                gridData[y+2][x] = "*";;
                x++;
                
            }
        }
        else if (ch == 'a'){
            if (x == 0){
                x = 9;
                
                gridData[y][0] = '*';
                gridData[y+1][0] = '*';
                gridData[y+2][0] = '*';
            }
            else{
                gridData[y][x] = '*';
                gridData[y+1][x] = '*';
                gridData[y+2][x] = "*";
                x--
                
            }
        }
        else if (ch == 'k'){
            
            break;
        }
    c.points[0] = {x,y};
	c.points[1] = {x,y+1};
    c.points[2] = {x,y+2};
    gridData[y][x] = shipChar;
    gridData[y+1][x] = shipChar;
    gridData[y+2][x] = shipChar;
    displayCurrentBoard(gridData);
    }
    if(gridData[0][0] == shipChar && gridData[1][0] == shipChar){
        x = 1;
        y = 0;
    }
    else{
        x = 0;
        y = 0;
    }
    //patrol while loop
    while (1){
        int ch = getch();
        if (ch == 'w'){
            if(y == 0){
                y = 7;
                
                gridData[0][x] = '*';
                gridData[1][x] = '*';
            }
            else{
                gridData[y][x] = '*';
                gridData[y+1][x] = '*';
                y--;
                
            }
        }
        else if (ch == 's'){
            if (y == 7){
                y = 0;
                
                gridData[7][x] = '*';
                gridData[8][x] = '*';
            }
            else{
                gridData[y][x] = '*';
                gridData[y+1][x] = '*';
                y++;
                
            }
        }
        else if (ch == 'd'){
            if (x == 9){
                x = 0;
                
                gridData[y][9] = '*';
                gridData[y+1][9] = '*';
            }
            else{
                gridData[y][x] = '*';
                gridData[y+1][x] = '*';
                x++;
                
            }
        }
        else if (ch == 'a'){
            if (x == 0){
                x = 9;
                
                gridData[y][0] = '*';
                gridData[y+1][0] = '*';
            }
            else{
                gridData[y][x] = '*';
                gridData[y+1][x] = '*'; 
                x--
                
            }
        }
        else if (ch == 'k'){
            
            break;
        }
    p.points[0] = {x,y};
	p.points[1] = {x,y+1};
    gridData[y][x] = shipChar;
    gridData[y+1][x] = shipChar;
    displayCurrentBoard(gridData);
    }
    y = 0;
    if(gridData[0][0] == shipChar){
        if(gridData[0][1] == shipChar){
            x = 2;
        }
        else{
            x = 1;
        }
        
    }
    else{
        x = 0;
    }
    //boat while loop
    while (1){
        int ch = getch();
        if (ch == 'w'){
            if(y == 0){
                y = 7;
                gridData[0][x] = '*';
            }
            else{
                gridData[y][x] = '*';
                y--;
            }
        }
        else if (ch == 's'){
            if (y == 7){
                y = 0;
                gridData[7][x] = '*';
            }
            else{
                gridData[y][x] = '*';;
                y++;
            }
        }
        else if (ch == 'd'){
            if (x == 9){
                x = 0;
                gridData[y][9] = '*';
            }
            else{
                gridData[y][x] = '*';
                x++;
            }
        }
        else if (ch == 'a'){
            if (x == 0){
                x = 9;
                
                gridData[y][0] = '*';
            }
            else{
                gridData[y][x] = '*';
                x--
                
            }
        }
        else if (ch == 'k'){
            break;
        }
    b.points[0] = {x,y};
    gridData[y][x] = shipChar;
    displayCurrentBoard(gridData);
    }
	
}
*/


int placeShip(int gridData[BOARD_LENGTH][BOARD_WIDTH],int x, int y, int shipNum){
    //ship number is 1,2, or 3
    switch(shipNum){
        case 1: //1x1 - boat
            if(gridData[x][y] == 1) return 0; //if already a boat don't do anything
            gridData[x][y] = 1;
            break;
        case 2: //2x1 - patrol
            if(gridData[x][y] == 1 || gridData[x+1][y] == 1) return 0;
            gridData[x][y] = 1;
            gridData[x+1][y] = 1;
            break;
        case 3: //3x1 - carrier
            if(gridData[x][y] == 1 || gridData[x+1][y] == 1 || gridData[x+2][y] == 1) return 0;
            gridData[x][y] = 1;
            gridData[x+1][y] = 1;
            gridData[x+2][y] = 1;
            break;
    }
    return 1;
}

int shoot(int gridData[BOARD_LENGTH][BOARD_WIDTH],int x, int y){
    if(gridData[x][y] == 1){
        return 1;
    }else{
        return 0;
    }
}

void main()
{
	//Initialize screen
	initscr();
	//noecho();
	//cbreak();
	//nodelay(stdscr, TRUE);
	//scrollok(stdscr, TRUE);
    time_t t;
	srand((unsigned) time(&t));

	//1 = ship
	//2 = miss
	int playerGrid[BOARD_LENGTH][BOARD_WIDTH];
	int playerGuessGrid[BOARD_LENGTH][BOARD_WIDTH];
	int computerGrid[BOARD_LENGTH][BOARD_WIDTH];
	int computerGuessGrid[BOARD_LENGTH][BOARD_LENGTH];
	//struct ships compShips;
	//struct ships playerShips;

	//location of displays
	int playerBoardX = 5;
	int playerBoardY = 1;
	int playerGuessX = 35;
	int playerGuessY = 1;
	int cpuBoardX = 65;
	int cpuBoardY = 1;
	int cpuGuessX = 95;
	int cpuGuessY = 1;

    //short flag = 1;

	//set everything to 0 (for sanity's sake) Might not need this
	for (int i = 0; i < BOARD_LENGTH; i++) {
		for (int j = 0; j < BOARD_WIDTH; j++) {
			playerGrid[i][j] = 0;
			computerGrid[i][j] = 0;
            playerGuessGrid[i][j] = 0;
			computerGuessGrid[i][j] = 0;
		}
	}

	/* //testing
	playerGrid[1][10] = 2;
	playerGrid[2][4] = 1;
	playerGrid[9][3] = 1;
	*/

	//initial displays 
	displayCurrentBoard(playerGrid, playerBoardX, playerBoardY);
	displayCurrentBoard(playerGuessGrid, playerGuessX, playerGuessY);
	displayCurrentBoard(computerGrid, cpuBoardX, cpuBoardY);
	displayCurrentBoard(computerGuessGrid, cpuGuessX, cpuGuessY);

    int placeX, placeY;

	//place user ships
	char* ch;
	for (int i = 1; i < 4; i++) {
		mvprintw(14, 0, "Input where to put your ship %d; Example D4: ", i);
		getstr(ch);

        //if user enters nothing
        if(!ch[0]){
            i -= 1;
            continue;
        }

        //if user enters a letter not within range (64 to 75)
        if(!(ch[0] > 64 && ch[0] < 75)){
            mvprintw(14, 44, "    "); //remove previous input
            i -= 1;
            continue;
        }

        //48 to 56
        //if user enters a number not within range (1 to 9)
        if(!(ch[1] > 48 && ch[1] < 56)){
            mvprintw(14, 44, "    "); //remove previous input
            i -=1;
            continue;
        }

        //mvprintw(20,0,"%d, %d ",ch[0]-64-1,ch[1]-48-1); //testing
        if(ch[1] == '1' && ch[2] == '0'){ //when user enters 10 (quick fix)
            placeX = ch[0]-64-1;
            placeY = 9;
        }else{ //otherwise print normally
            placeX = ch[0]-64-1;
            placeY = ch[1]-48-1;
        }

        if(!placeShip(playerGrid, placeX, placeY, i)){//if it failes to place
            i = i - 1;  //redo last step
        } 
	
        mvprintw(14, 44, "    "); //remove previous input
        //update board every time
        displayCurrentBoard(playerGrid, playerBoardX, playerBoardY);
	}

	mvprintw(14, 0, "                                             ");
    
    //place bot ships (randomly)
    for(int j = 1; j < 4; j++){
        placeShip(computerGrid,rand()%10,rand()%10,j);
        displayCurrentBoard(computerGrid, cpuBoardX, cpuBoardY);
    }
    
    //Main loop (game start)
    while (1){
        //loop through player and ship picking locations to shoot
        
        //player shoot
        mvprintw(14,0, "Pick a location to shoot: ");
        getstr(ch);
        
        //if(shoot(computerGrid,ch[0]-64-1,ch[1]-48-1)){ //if it hits
            
        //}
    }

    //Exit screen
    endwin();
}