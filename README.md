# FinalPRO
Contact Info

Corbin Kems: crkems@iastate.edu | 515-468-9593 (text me)






The Game

Scenario: You are to create a battleship game that will be played between you and the
computer. You will not need the controller for this option. See the code requirements below for
the rest of the instructions.

Code Requirements:
1. Use of 2 2D arrays for your playing field and the computer’s playing field
2. The size of the 2D array should be a minimum of 4x4
3. Have 3 different battleships that are the following sizes (given in ROWSxCOLUMNS)
    Carrier: 3x1
    Destroyer: 2x1
    Patrol Boat: 1x1
4. Have the computer randomly position its ships each game
5. Prompt the user for their ship placement each game
6. Have the computer randomly generate a coordinate to fire on for each round
7. Prompt the user for a coordinate to fire on each round
    This should be done on 1 line, simply clear the old input once the user enters it
    so that way you do not end up with a list of attempts at the bottom of the screen
8. Show the user’s hits and misses on a grid of the 2D array on the screen
    Continually update board
9. Show the user’s boats in the 2D array on the screen
    Continually update this if a boat is hit
    Represent the boats as O’s
    If one of the coordinates is hit, replace the O with an X
10. Have a way to check the status of the game (i.e. if the user or the computer has won)
    You may want to use structs for this and the ships, they are not required but
    simply a development suggestion
    You will need to keep track of the user’s status as well as the computer’s since
    the computer has the potential to win
11. Use of a minimum of 3 functions outside of the main() function
12. Please include comments in your code


Rubric:
● Randomly generate and assign the computer’s ship placement: 20 pts
● Prompting the user for and assign their ship placement: 20 pts
● Continuously updating the user’s attempts at firing on the computer: 20 pts
● Continuously updating the user’s ships status (i.e. if they have been hit or not): 20 pts
● Keeping track of the game status: 15 pts
● Comments in your code 5 pts
● Total Possible Points: 100 pts