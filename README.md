# C-Projects

This repository contains some of the programs I have written in C. You will find 4 project: the Pascal Triangle, Battleship, Reversi, and the Contact List. You will find below a brief description of what each of these programs do:
## **The Contact List (implemented with linked lists):**
This Contact List serves as a digital phone book utility which allows you to search contacts with their phone numbers. An entry in the phone book consists in a name and several phone numbers. In the name of the contact we store the string of characters that the user enters which may be of the form "Last name First name", as in "Chen Johnny", or “First name Last name” as in "Jane Dunne”. The user may enter a contact two or more times without realizing it and the program will help the user detect and delete duplicates, which are defined as contacts that have a phone number in common.

![image](https://user-images.githubusercontent.com/95399226/147927560-86c20a4b-dcf9-4b73-b315-69a46149d618.png)

                                Figure 1: All commands available to the user
                                                      
![image](https://user-images.githubusercontent.com/95399226/147928135-4c7aa09e-3abf-45ec-9e2d-f19393acaa56.png)
                      
                     Figure 2: Example of a user input and program output for alphabetical order print
                     
## **Reversi Game**
This program implements a Reversi game with error checking, move validity checking, functions, 2D arrays representing the board etc. The player plays against the computer, which finds the most strategically adequate move corresponding to the player's move. The computer determines its move based on the maximum number of tiles it can flip by playing a move.
![image](https://user-images.githubusercontent.com/95399226/148216406-a8639143-f20a-4051-8d6c-e71d358b8ab8.png)
                    
                    Figure 3: Demonstration of how the program prompts the user for input and what it outputs
                    
## **Battleship**
This program implements a simple game of battleship which uses 2D arrays, move validity checking, input error checking. The input from the player for each ship size will be: Row, Colulmn, Orientation. The Ship Size will be 1-5, Row will be 1-9, Column will be 1-11, Orientation will be 0 for horizontal (going to the right from the Row/Column position) or 1 (going down from the Row/Column position). There is also a function that makes sure there is no ship overlapping on the board.

## **Pascal's triangle**

This program uses for loops, if loops and while loops to draw a Pascal Triangle (https://en.wikipedia.org/wiki/Pascal%27s_triangle) with size given by the user.

![image](https://user-images.githubusercontent.com/95399226/148217665-0e065d44-b2b9-45f9-85ae-3cf7cc087bc5.png)
                   
                   Figure 4: Example of input and output
