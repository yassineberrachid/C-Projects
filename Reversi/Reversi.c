//#include "project_reversi_skeleton.h" // DO NOT modify this line
#include <stdio.h>
#include <stdbool.h>

// Note: You may want to add more function declarations here
// =========   Function declaration  ==========
/* None for now */


// ========= Function implementation ==========
/*
 * Function:  printBoard 
 * --------------------
 * Print the whole board to the terminal window.
 */
void boardInitialization(char board[][26], int n){ // This function initializes the board and sets the black tiles, whte tiles and unoccupied boxes
        for (int i=0; i<n; i++){
            for (int j=0; j<n;j++){ // For all rows and columns (two nested for loops)
                if (i==n/2){ // This sets the initial configuration of the board with the W,B and U placed correctly at the center of the board
                    if (j==n/2)
                        board[i][j]='W'; // In this case, we place a white tile
                    else if (j==n/2-1)
                        board[i][j]='B'; // In this case we place a black tile 
                    else 
                        board [i][j]='U'; // If a box is not occupied by a black or white tile, it is unnocupied and we print U
                }
                else if(i==n/2-1){
                    if (j==n/2-1)
                        board[i][j]='W'; // In this case, the tile is white
                    else if (j==n/2)
                        board[i][j]='B'; // In this case, we place a black tile
                    else
                        board[i][j]='U';
                }
                else 
                    board [i][j]='U';

            
            
            }
        }
}

void printBoard(char board[][26], int n) {
    (void)board;
    (void)n;
    int letterPrinted=(int) 'a'; // We take the ASCII value of the character 
    
    printf("  "); // We print two spaces at the beginning according to the handout
    for(int i=0; i<n;i++){
        printf("%c",letterPrinted); // 97 is the ASCII number of a, so this will print the labels of the rows, a,b,c,d,e,f...
        letterPrinted++; // We move to the next ASCII value
    }
    

    letterPrinted=(int) 'a';
    for (int i=0;i<n;i++){
        printf("\n%c ", letterPrinted);
        for (int j=0;j<n;j++){
            printf("%c", board[i][j]); // Here, we print the different letters corresponding to the tile (or not) present on each box 
        }
        letterPrinted++; // We move to the next ASCII value
    }
   
  printf("\n");  // Print a new line at the end of each iteration of the for loop
    
    
}

/*
 * Function:  positionInBounds 
 * --------------------
 * Checks whether the specified (row, col) lies within the board dimensions.
 */
bool positionInBounds(int n, int row, int col) {
    (void)n;
    (void)row;
    (void)col;
    if (row>=0 && row<n && col>=0 && col<n) // If the row and column positions of the tile are both greater than zero and smaller than n, then the position is within the bounds of the board.
        return true;
    else 
        return false; // If not, then the position is out of bouds and the function returns false.
}


bool checkLegalInDirection(char board[][26], int n, int row,int col, char colour, int deltaRow, int deltaCol) {
    (void)board;
    (void)n;
    (void)row;
    (void)col;
    (void)colour;
    (void)deltaRow;
    (void)deltaCol;
    
    if (positionInBounds(n,row+deltaRow, col+deltaCol)==true){ // We first check that the given position is within the bounds of the board. If true, we proceed to the rest of the code.
        if (board[row][col]=='U' && board[row+deltaRow][col+deltaCol]!='U' && board[row+deltaRow][col+deltaCol]!=colour){ 
            // Here, we're checking if the position where we want to palce the tile is unoccupied, if the second position in the direction we're moving is the opposite colour of our tile
            
            if (deltaRow==0 && deltaCol==1){ // That's the first direction (from left to right)
            
                int numberBoxesMoved=1; // This plays the role of a counter, which goes to the next box at the end of each iteration
                while (2>1){ // Infinite while loop
                    
                    int rowMovedTo=row+(numberBoxesMoved*deltaRow); // The row that we move to is simply the current row added to the number of rows we want to move in the specified direction
                    int colMovedTo=col+(numberBoxesMoved*deltaCol); // The column that we move to is simply the current column added to the number of columns we want to move in the specified direction
                    if (positionInBounds(n,rowMovedTo,colMovedTo)==false) 
                        return false; // If the position we are moving to is out of the bounds of the board, then we cannot move in this direction
                    else if (board[rowMovedTo][colMovedTo]==colour)
                        return true;
                    else if (board[rowMovedTo][colMovedTo]=='U')
                        return false; // If it is unnocupied we cannot move in this direction
                    else
                        numberBoxesMoved++; // Here, if the function does not print true or false after an iteration, we move to the next box and check, until the function returns true or false
                }
            }
            
            else if (deltaRow==1 && deltaCol==0){
                    int numberBoxesMoved=1; // This plays the role of a counter, which goes to the next box at the end of each iteration
                    while (2>1){
                        int rowMovedTo=row+(numberBoxesMoved*deltaRow); // The row that we move to is simply the current row added to the number of rows we want to move in the specified direction
                        int colMovedTo=col+(numberBoxesMoved*deltaCol);
                        if (positionInBounds(n,rowMovedTo,colMovedTo)==false)
                            return false;
                        else if (board[rowMovedTo][colMovedTo]==colour)
                            return true;
                        else if (board[rowMovedTo][colMovedTo]=='U')
                            return false;
                        else
                            numberBoxesMoved++;

                    }
            }
            

            else if (deltaRow==1 && deltaCol==1){
                    int numberBoxesMoved=1; // This plays the role of a counter, which goes to the next box at the end of each iteration
                    while (2>1){
                        int rowMovedTo=row+(numberBoxesMoved*deltaRow); // The row that we move to is simply the current row added to the number of rows we want to move in the specified direction
                        int colMovedTo=col+(numberBoxesMoved*deltaCol);
                        if (positionInBounds(n,rowMovedTo,colMovedTo)==false)
                            return false;
                        else if (board[rowMovedTo][colMovedTo]==colour)
                            return true;
                        else if (board[rowMovedTo][colMovedTo]=='U')
                            return false;
                        else
                            numberBoxesMoved++;
                    }
            }
            else if (deltaRow==0 && deltaCol==-1){
                int numberBoxesMoved=1; // This plays the role of a counter, which goes to the next box at the end of each iteration
                while (2>1){
                    
                    int rowMovedTo=row+(numberBoxesMoved*deltaRow); // The row that we move to is simply the current row added to the number of rows we want to move in the specified direction
                    int colMovedTo=col+(numberBoxesMoved*deltaCol);
                    if (positionInBounds(n,rowMovedTo,colMovedTo)==false)
                        return false;
                    else if (board[rowMovedTo][colMovedTo]==colour)
                        return true;
                    else if (board[rowMovedTo][colMovedTo]=='U')
                        return false;
                    else
                        numberBoxesMoved++;
                }
            }
            
            else if (deltaRow==-1 && deltaCol==0){
                int numberBoxesMoved=1; // This plays the role of a counter, which goes to the next box at the end of each iteration
                while (2>1){
                    
                    int rowMovedTo=row+(numberBoxesMoved*deltaRow); // The row that we move to is simply the current row added to the number of rows we want to move in the specified direction
                    int colMovedTo=col+(numberBoxesMoved*deltaCol);
                    if (positionInBounds(n,rowMovedTo,colMovedTo)==false)
                        return false;
                    else if (board[rowMovedTo][colMovedTo]==colour)
                        return true;
                    else if (board[rowMovedTo][colMovedTo]=='U')
                        return false;
                    else
                        numberBoxesMoved++;
                }
            }
            
            else if (deltaRow==-1 && deltaCol==1){
                int numberBoxesMoved=1; // This plays the role of a counter, which goes to the next box at the end of each iteration
                while (2>1){
                    int rowMovedTo=row+(numberBoxesMoved*deltaRow); // The row that we move to is simply the current row added to the number of rows we want to move in the specified direction
                    int colMovedTo=col+(numberBoxesMoved*deltaCol);
                    if (positionInBounds(n,rowMovedTo,colMovedTo)==false)
                        return false;
                    else if (board[rowMovedTo][colMovedTo]==colour)
                        return true;
                    else if (board[rowMovedTo][colMovedTo]=='U')
                        return false;
                    else
                        numberBoxesMoved++;
                }
            }
            
            else if (deltaRow==1 && deltaCol==-1){
                int numberBoxesMoved=1; // This plays the role of a counter, which goes to the next box at the end of each iteration
                while (2>1){
                    
                    int rowMovedTo=row+(numberBoxesMoved*deltaRow); // The row that we move to is simply the current row added to the number of rows we want to move in the specified direction
                    int colMovedTo=col+(numberBoxesMoved*deltaCol);
                    if (positionInBounds(n,rowMovedTo,colMovedTo)==false)
                        return false;
                    else if (board[rowMovedTo][colMovedTo]==colour)
                        return true;
                    else if (board[rowMovedTo][colMovedTo]=='U')
                        return false;
                    else
                        numberBoxesMoved++;
                }
            }
            
            else if (deltaRow==-1 && deltaCol==-1){
                int numberBoxesMoved=1; // This plays the role of a counter, which goes to the next box at the end of each iteration
                while (2>1){
                    
                    int rowMovedTo=row+(numberBoxesMoved*deltaRow); // The row that we move to is simply the current row added to the number of rows we want to move in the specified direction
                    int colMovedTo=col+(numberBoxesMoved*deltaCol);
                    if (positionInBounds(n,rowMovedTo,colMovedTo)==false)
                        return false;
                    else if (board[rowMovedTo][colMovedTo]==colour)
                        return true;
                    else if (board[rowMovedTo][colMovedTo]=='U')
                        return false;
                    else
                        numberBoxesMoved++;
                }
            }
                
    
    
    
        
        }
        
    }
    return false;
}


bool canPlaceTile(char board[][26], int n, int row, int col, char colour){ // This function checks if at least one direction is possible, and if so, the player can place his tile there
    if (checkLegalInDirection(board,n,row,col,colour,1,0)==true || checkLegalInDirection(board,n,row,col,colour,0,1)==true || checkLegalInDirection(board,n,row,col,colour,1,1)==true || checkLegalInDirection(board,n,row,col,colour,0,-1)==true || checkLegalInDirection(board,n,row,col,colour,-1,0)==true || checkLegalInDirection(board,n,row,col,colour,-1,1)==true || checkLegalInDirection(board,n,row,col,colour,1,-1)==true || checkLegalInDirection(board,n,row,col,colour,-1,-1)==true)
        return true; // Here, we can place a tile in a position if it is legal in any of the eight directions, so we only check if one of the condition is verified 
    else
        return false;
}



bool flipTile(char board[][26], int n, int rowTile, int colTile, char colour, int deltaRow, int deltaCol){
    
    if (positionInBounds(n,rowTile+deltaRow, colTile+deltaCol)==true){
        if (board[rowTile+deltaRow][colTile+deltaCol]!='U' && board[rowTile+deltaRow][colTile+deltaCol]!=colour){ 
        // We check for the same conditions as for checkLegalInDirection
            
            if (deltaRow==0 && deltaCol==1){ // Checks if the direction of is this one and flips (or not) tiles accordingly
                 int positionChecked[n][2]; // This array stores the different positions that were checked by the program when looking for tiles to flip
                 int numberBoxesMoved=1; // That's the increment, the number of boxes that we advance for each iteration
                 while(2>1){ // Infinite loop
                     
                     int rowBeingChecked=rowTile+numberBoxesMoved*deltaRow;
                     int colBeingChecked=colTile+numberBoxesMoved*deltaCol;
                     
                     if (board[rowBeingChecked][colBeingChecked]==colour){
                         for (int r=1; r<numberBoxesMoved;r++){
                             int rowPositionFlipped=positionChecked[r][0]; // We store the positions of the flipped tiles
                             int colPositionFlipped=positionChecked[r][1];
                             if (colour=='B')
                                 board[rowPositionFlipped][colPositionFlipped]='B'; // It's either the tile is flipped if it was white or it stays the same if it was already black
                             else if (colour=='W')
                                board[rowPositionFlipped][colPositionFlipped]='W'; // It's either the tile is flipped if it was black or it stays the same if it was already white
                             
                         }
                         return true;
                    }
                    else if (positionInBounds(n,rowBeingChecked,colBeingChecked)==false)
                        return false; // If the position being check (row/column) is not in bounds, we don't flip any tile and the function just returns false
                        
                    else if (board[rowBeingChecked][colBeingChecked]=='U')
                        return false; // If it's unnocupied we don't flip the tiles 
                        
                    else{
                        positionChecked[numberBoxesMoved][0]=rowBeingChecked; // This array is going to store the row and column that has just been checked (meaning the position that was checked)
                        positionChecked[numberBoxesMoved][1]=colBeingChecked;
                        numberBoxesMoved++; // We check the next position
                    }
                    
                }
                 
                 
            }
            
            else if (deltaRow==1 && deltaCol==0){ // Checks if the direction of is this one and flips (or not) tiles accordingly
                 int positionChecked[n][2]; // This array stores the different positions that were checked by the program when looking for tiles to flip
                 int numberBoxesMoved=1; // That's the increment, the number of boxes that we advance for each iteration
                 
                 while(2>1){

                     int rowBeingChecked=rowTile+numberBoxesMoved*deltaRow;
                     int colBeingChecked=colTile+numberBoxesMoved*deltaCol;
                     
                     if (board[rowBeingChecked][colBeingChecked]==colour){
                         for (int r=1; r<numberBoxesMoved;r++){
                             int rowPositionFlipped=positionChecked[r][0];
                             int colPositionFlipped=positionChecked[r][1];
                             if (colour=='B')
                                 board[rowPositionFlipped][colPositionFlipped]='B'; // Here we flip the tiles 
                             else if (colour=='W')
                                board[rowPositionFlipped][colPositionFlipped]='W';
                             
                         }
                         return true;
                    }
                    else if (positionInBounds(n,rowBeingChecked,colBeingChecked)==false)
                        return false;
                        
                    else if (board[rowBeingChecked][colBeingChecked]=='U')
                        return false;
                        
                    else{
                        positionChecked[numberBoxesMoved][0]=rowBeingChecked;
                        positionChecked[numberBoxesMoved][1]=colBeingChecked;
                        numberBoxesMoved++;
                    }
                    
                }
                 
                 
            }
            else if (deltaRow==1 && deltaCol==1){ // Checks if the direction of is this one and flips (or not) tiles accordingly
                 int positionChecked[n][2]; // This array stores the different positions that were checked by the program when looking for tiles to flip
                 int numberBoxesMoved=1; // That's the increment, the number of boxes that we advance for each iteration
                 
                 while(2>1){
                     int rowBeingChecked=rowTile+numberBoxesMoved*deltaRow;
                     int colBeingChecked=colTile+numberBoxesMoved*deltaCol;
                     
                     if (board[rowBeingChecked][colBeingChecked]==colour){
                         for (int r=1; r<numberBoxesMoved;r++){
                             int rowPositionFlipped=positionChecked[r][0];
                             int colPositionFlipped=positionChecked[r][1];
                             if (colour=='B')
                                 board[rowPositionFlipped][colPositionFlipped]='B'; // Here we flip the tiles 
                             else if (colour=='W')
                                board[rowPositionFlipped][colPositionFlipped]='W';
                             
                         }
                         return true;
                    }
                    else if (positionInBounds(n,rowBeingChecked,colBeingChecked)==false)
                        return false;
                        
                    else if (board[rowBeingChecked][colBeingChecked]=='U')
                        return false;
                        
                    else{
                        positionChecked[numberBoxesMoved][0]=rowBeingChecked;
                        positionChecked[numberBoxesMoved][1]=colBeingChecked;
                        numberBoxesMoved++;
                    }
                    
                }
                 
                 
            }
            else if (deltaRow==0 && deltaCol==-1){ // Checks if the direction of is this one and flips (or not) tiles accordingly
                 int positionChecked[n][2]; // This array stores the different positions that were checked by the program when looking for tiles to flip
                 int numberBoxesMoved=1; // That's the increment, the number of boxes that we advance for each iteration
                 
                 while(2>1){
                     
                     int rowBeingChecked=rowTile+numberBoxesMoved*deltaRow;
                     int colBeingChecked=colTile+numberBoxesMoved*deltaCol;
                     
                     if (board[rowBeingChecked][colBeingChecked]==colour){
                         for (int r=1; r<numberBoxesMoved;r++){
                             int rowPositionFlipped=positionChecked[r][0];
                             int colPositionFlipped=positionChecked[r][1];
                             if (colour=='B')
                                 board[rowPositionFlipped][colPositionFlipped]='B'; // Here we flip the tiles 
                             else if (colour=='W')
                                board[rowPositionFlipped][colPositionFlipped]='W';
                             
                         }
                         return true;
                    }
                    else if (positionInBounds(n,rowBeingChecked,colBeingChecked)==false)
                        return false;
                        
                    else if (board[rowBeingChecked][colBeingChecked]=='U')
                        return false;
                        
                    else{
                        positionChecked[numberBoxesMoved][0]=rowBeingChecked;
                        positionChecked[numberBoxesMoved][1]=colBeingChecked;
                        numberBoxesMoved++;
                    }
                    
                }
                 
                 
            }
            else if (deltaRow==-1 && deltaCol==0){ // Checks if the direction of is this one and flips (or not) tiles accordingly
                 int positionChecked[n][2]; // This array stores the different positions that were checked by the program when looking for tiles to flip
                 int numberBoxesMoved=1; // That's the increment, the number of boxes that we advance for each iteration
                 
                 while(2>1){
                     
                     int rowBeingChecked=rowTile+numberBoxesMoved*deltaRow;
                     int colBeingChecked=colTile+numberBoxesMoved*deltaCol;
                     
                     if (board[rowBeingChecked][colBeingChecked]==colour){
                         for (int r=1; r<numberBoxesMoved;r++){
                             int rowPositionFlipped=positionChecked[r][0];
                             int colPositionFlipped=positionChecked[r][1];
                             if (colour=='B')
                                 board[rowPositionFlipped][colPositionFlipped]='B'; // Here we flip the tiles 
                             else if (colour=='W')
                                board[rowPositionFlipped][colPositionFlipped]='W';
                             
                         }
                         return true;
                    }
                    else if (positionInBounds(n,rowBeingChecked,colBeingChecked)==false)
                        return false;
                        
                    else if (board[rowBeingChecked][colBeingChecked]=='U')
                        return false;
                        
                    else{
                        positionChecked[numberBoxesMoved][0]=rowBeingChecked;
                        positionChecked[numberBoxesMoved][1]=colBeingChecked;
                        numberBoxesMoved++;
                    }
                    
                }
                 
                 
            }
            else if (deltaRow==-1 && deltaCol==1){ // Checks if the direction of is this one and flips (or not) tiles accordingly
                 int positionChecked[n][2]; // This array stores the different positions that were checked by the program when looking for tiles to flip
                 int numberBoxesMoved=1; // That's the increment, the number of boxes that we advance for each iteration
                 
                 while(2>1){
                     
                     int rowBeingChecked=rowTile+numberBoxesMoved*deltaRow;
                     int colBeingChecked=colTile+numberBoxesMoved*deltaCol;
                     
                     if (board[rowBeingChecked][colBeingChecked]==colour){
                         for (int r=1; r<numberBoxesMoved;r++){
                             int rowPositionFlipped=positionChecked[r][0];
                             int colPositionFlipped=positionChecked[r][1];
                             if (colour=='B')
                                 board[rowPositionFlipped][colPositionFlipped]='B'; // Here we flip the tiles 
                             else if (colour=='W')
                                board[rowPositionFlipped][colPositionFlipped]='W';
                             
                         }
                         return true;
                    }
                    else if (positionInBounds(n,rowBeingChecked,colBeingChecked)==false)
                        return false;
                        
                    else if (board[rowBeingChecked][colBeingChecked]=='U')
                        return false;
                        
                    else{
                        positionChecked[numberBoxesMoved][0]=rowBeingChecked;
                        positionChecked[numberBoxesMoved][1]=colBeingChecked;
                        numberBoxesMoved++;
                    }
                    
                }
                 
                 
            }
            else if (deltaRow==1 && deltaCol==-1){ // Checks if the direction of is this one and flips (or not) tiles accordingly
                 int positionChecked[n][2]; // This array stores the different positions that were checked by the program when looking for tiles to flip
                 int numberBoxesMoved=1; // That's the increment, the number of boxes that we advance for each iteration
                 
                 while(2>1){
                     
                     int rowBeingChecked=rowTile+numberBoxesMoved*deltaRow;
                     int colBeingChecked=colTile+numberBoxesMoved*deltaCol;
                     
                     if (board[rowBeingChecked][colBeingChecked]==colour){
                         for (int r=1; r<numberBoxesMoved;r++){
                             int rowPositionFlipped=positionChecked[r][0];
                             int colPositionFlipped=positionChecked[r][1];
                             if (colour=='B')
                                 board[rowPositionFlipped][colPositionFlipped]='B'; // Here we flip the tiles 
                             else if (colour=='W')
                                board[rowPositionFlipped][colPositionFlipped]='W';
                             
                         }
                         return true;
                    }
                    else if (positionInBounds(n,rowBeingChecked,colBeingChecked)==false)
                        return false;
                        
                    else if (board[rowBeingChecked][colBeingChecked]=='U')
                        return false;
                        
                    else{
                        positionChecked[numberBoxesMoved][0]=rowBeingChecked;
                        positionChecked[numberBoxesMoved][1]=colBeingChecked;
                        numberBoxesMoved++;
                    }
                    
                }
                 
                 
            }
            else if (deltaRow==-1 && deltaCol==-1){ // Checks if the direction of is this one and flips (or not) tiles accordingly
                 int positionChecked[n][2]; // This array stores the different positions that were checked by the program when looking for tiles to flip
                 int numberBoxesMoved=1; // That's the increment, the number of boxes that we advance for each iteration
                 
                 while(2>1){
                     
                     int rowBeingChecked=rowTile+numberBoxesMoved*deltaRow;
                     int colBeingChecked=colTile+numberBoxesMoved*deltaCol;
                     
                     if (board[rowBeingChecked][colBeingChecked]==colour){
                         for (int r=1; r<numberBoxesMoved;r++){
                             int rowPositionFlipped=positionChecked[r][0];
                             int colPositionFlipped=positionChecked[r][1];
                             if (colour=='B')
                                 board[rowPositionFlipped][colPositionFlipped]='B'; // Here we flip the tiles 
                             else if (colour=='W')
                                board[rowPositionFlipped][colPositionFlipped]='W';
                             
                         }
                         return true;
                    }
                    else if (positionInBounds(n,rowBeingChecked,colBeingChecked)==false)
                        return false;
                        
                    else if (board[rowBeingChecked][colBeingChecked]=='U')
                        return false;
                        
                    else{
                        positionChecked[numberBoxesMoved][0]=rowBeingChecked;
                        positionChecked[numberBoxesMoved][1]=colBeingChecked;
                        numberBoxesMoved++;
                    }
                    
                }
                 
                 
            }
            
        }
        
    }
    return false;
}

    
    
    
    
    

    



/*
 * Function:  makeMove 
 * --------------------
 * The player "turn" makes a move at (row, col).
 * Note: This function MUST NOT change board, only row and col can be changed to reflect the move.
 */
int makeMove(const char board[26][26], int n, char turn, int *row, int *col) {
    (void)board;
    (void)n;
    (void)turn;
    (void)row;
    (void)col;
    return 0;
}

#ifndef COMPETE_MODE // DO NOT DELETE THIS LINE
int main(void) {
    char board [26][26];
    int n;
    char row,column,color;
    
    printf("Enter the board dimension: "); // Ask for the board dimension
    scanf("%d", &n);
    
    boardInitialization(board,n); // We initialize the board
    printBoard(board,n); // We print the board
    
    printf("Enter board configuration:\n");
    for (int i=0; (row!='!' && column!='!' && color!='!'); i++){ // Here we enter the for loop as long until the user types: "!!!'
        scanf(" %c%c%c", &color, &row, &column);
        board[row-'a'][column-'a']=color; // We place the tiles according to the configuration entered by the player
    }
    printBoard(board,n); // Here, we print the fuly configured initial board (before the playermakes any move)
    printf("Available moves for W:\n"); 
    for (int rowW=0; rowW<n; rowW++){
        for (int colW=0; colW<n; colW++){
            if (canPlaceTile(board,n,rowW,colW,'W')==true){ // If we can place the tile, the program displays the move as an available move
                printf("%c%c\n", rowW+'a', colW+'a'); //  Print the a available moves for white
            }
        }
    }
    
    printf("Available moves for B:\n");
    for (int rowB=0; rowB<n;rowB++){
        for (int colB=0; colB<n; colB++){
            if (canPlaceTile(board,n,rowB,colB,'B')==true)
                printf("%c%c\n", rowB+'a', colB+'a'); // Print the available moves for black tile
            
        }
    }
    
    printf("Enter a move:\n");
    scanf(" %c%c%c", &color, &row, &column);
    if (canPlaceTile(board,n,row-'a', column-'a',color)==true){
        printf("Valid move.\n");
        board[row-'a'][column-'a']=color; // We place the player's tile where he wants it to be placed
        flipTile(board,n,row-'a',column-'a',color,0,1); // Here, we check if we can flip tiles in all the 8 directions, and we flip tiles accordingly 
        flipTile(board,n,row-'a',column-'a',color,1,0);
        flipTile(board,n,row-'a',column-'a',color,1,1);
        flipTile(board,n,row-'a',column-'a',color,0,-1);
        flipTile(board,n,row-'a',column-'a',color,-1,0);
        flipTile(board,n,row-'a',column-'a',color,-1,1);
        flipTile(board,n,row-'a',column-'a',color,1,-1);
        flipTile(board,n,row-'a',column-'a',color,-1,-1);
        
        
    }
    else 
        printf("Invalid move.\n");
    
    printBoard(board,n);
    
    
    return 0;
}



#endif // DO NOT DELETE THIS LINE