// #include "project_reversi_skeleton.h" // DO NOT modify this line
#include <stdio.h>
#include <stdbool.h>




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
bool positionInBounds(int n, int row, int col) { // This function checks if the row and column positions of the tile are in the bounds of the board or not
    (void)n;
    (void)row;
    (void)col;
    if (row<0 || row>=n || col<0 || col>=n) // If one of the conditions these conditions occurs, then the tile is not in the bounds of the board
        return false;
    else 
        return true; // If none of the above conditions happen, then the position is in the bounds of the board
}


bool checkLegalInDirection(char board[][26], int n, int row,int col, char colour, int deltaRow, int deltaCol) {
    (void)board;
    (void)n;
    (void)row;
    (void)col;
    (void)colour;
    (void)deltaRow;
    (void)deltaCol;
    
    if (positionInBounds(n,row+deltaRow, col+deltaCol)==false){
        return false;
    }
    
    if (board[row][col]=='U' && board[row+deltaRow][col+deltaCol]!='U' && board[row+deltaRow][col+deltaCol]!=colour){ 
    // Here, we're checking if the position where we want to palce the tile is unoccupied, if the second position in the direction we're moving is the opposite colour of our tile
            
            int numberBoxesMoved=2; // This plays the role of a counter, which goes to the second next box at the end of each iteration
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
    return false;
}


bool canPlaceTile(char board[][26], int n, int row, int col, char colour){ // This function checks if at least one direction is possible, and if so, the player can place his tile there
    if (checkLegalInDirection(board,n,row,col,colour,1,0)==true || checkLegalInDirection(board,n,row,col,colour,0,1)==true || checkLegalInDirection(board,n,row,col,colour,1,1)==true || checkLegalInDirection(board,n,row,col,colour,0,-1)==true || checkLegalInDirection(board,n,row,col,colour,-1,0)==true || checkLegalInDirection(board,n,row,col,colour,-1,1)==true || checkLegalInDirection(board,n,row,col,colour,1,-1)==true || checkLegalInDirection(board,n,row,col,colour,-1,-1)==true)
        return true; // Here, we can place a tile in a position if it is legal in any of the eight directions, so we only check if one of the condition is verified 
    else
        return false;
}

bool movesAvailable(char board[26][26], int n, char turn){
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (canPlaceTile(board,n,i,j,turn)==true)
                return true;
        }
    }
    return false;
    
}


int makeMove(const char board[26][26], int n, char turn, int *row, int *col) { // This function computes the score for the moves made by the computer which correspond to the number of tiles that can be flipped 

    char myBoard[26][26];
    for (int row=0;row<n;row++){
        for (int col=0;col<n;col++)
            myBoard[row][col]=board[row][col];
    }
    
    int numTilesPossibleFlip[26][3]; // Array that counts the number of moves that are possible in each direction that is declared acceptable by the checkLegalInDirection function
    int rowChecked, colChecked;
    int positionValidMove=-1;
    (void)col;
    // In this function we are going to create a few arrays that store the values of the valid moves that the player can make in order to make sure that the move is valid
    
    
    for (rowChecked=0;rowChecked<n;rowChecked++){
        for (colChecked=0;colChecked<n;colChecked++){
            int checkInEveryDirection[8]; // Array that has the number of tiles that can be flipped in every direction (that's why there is an 8)
            if (canPlaceTile(myBoard,n,rowChecked,colChecked,turn)==true){
                
                int directionValid=-1; // Number of directions where the move can actually be made
                for(int deltaRow=-1;deltaRow<=1;deltaRow++){
                    for (int deltaCol=-1;deltaCol<=1;deltaCol++){
                        
                        if (deltaRow==0 && deltaCol==0){
                            deltaCol++;
                            
                            if (checkLegalInDirection(myBoard,n,rowChecked,colChecked,turn,deltaRow,deltaCol==true)){
                                int numberBoxesMoved=1;
                                int rowMovedTo=rowChecked+numberBoxesMoved*deltaRow;
                                int colMovedTo=colChecked+numberBoxesMoved*deltaCol;
                                directionValid++; // There is one more direction that is valid
                                while (myBoard[rowMovedTo][colMovedTo]!=turn && myBoard[rowMovedTo][colMovedTo]!='U'){
                                    numberBoxesMoved=numberBoxesMoved+1;
                                    rowMovedTo=rowChecked+numberBoxesMoved*deltaRow;
                                    colMovedTo=colChecked+numberBoxesMoved*deltaCol;
                                }
                                checkInEveryDirection[directionValid]=numberBoxesMoved-1; // This fills the array with the valid directions found
                                
                            }
                            
                            

                            
                        }
                        
                        else if (checkLegalInDirection(myBoard,n,rowChecked,colChecked,turn,deltaRow,deltaCol)==true){
                            int numberBoxesMoved=1;
                            int rowMovedTo=rowChecked+numberBoxesMoved*deltaRow;
                            int colMovedTo=colChecked+numberBoxesMoved*deltaCol;
                            directionValid=directionValid+1; // There is one more direction that is valid
                            while (myBoard[rowMovedTo][colMovedTo]!=turn && myBoard[rowMovedTo][colMovedTo]!='U'){
                                numberBoxesMoved=numberBoxesMoved+1;
                                rowMovedTo=rowChecked+numberBoxesMoved*deltaRow;
                                colMovedTo=colChecked+numberBoxesMoved*deltaCol;
                            }
                            checkInEveryDirection[directionValid]=numberBoxesMoved-1; // This fills the array with the valid directions found
                            
                         
                        }
                        
                    }
                }
                positionValidMove=positionValidMove+1;
                numTilesPossibleFlip[positionValidMove][0]=rowChecked;
                numTilesPossibleFlip[positionValidMove][1]=colChecked;
                numTilesPossibleFlip[positionValidMove][2]=checkInEveryDirection[0];
                
                for(int i=1; i<=directionValid;i++){ // Here we do the sum all of the scores
                    numTilesPossibleFlip[positionValidMove][2]+=checkInEveryDirection[positionValidMove];
                }
                
                
               
                
                
            }
        }
    }

    //Now we need to find the highest number of tiles that can be flipped by each move, which corresponds to the highest score.
    int highestScore=numTilesPossibleFlip[0][2];
    int positionHighest=0;
    for (int i=1; i<=positionValidMove;i++){
        if (highestScore==numTilesPossibleFlip[i][2])
            positionHighest=positionHighest;
        else if (highestScore<numTilesPossibleFlip[i][2]){
            highestScore=numTilesPossibleFlip[i][2];
            positionHighest=i;
        }
    }
    
    
    // Now we return the row and the column that the tile will be moved to according to the highest score.
    
    
    *row=numTilesPossibleFlip[positionHighest][0];
    *col=numTilesPossibleFlip[positionHighest][1];
    
    
    
    
    
    
    return 0;
    
}



bool flipTile(char board[][26], int n, int rowTile, int colTile, char colour, int deltaRow, int deltaCol){
    
    if (positionInBounds(n,rowTile+deltaRow, colTile+deltaCol)==true){
        if (board[rowTile+deltaRow][colTile+deltaCol]!='U' && board[rowTile+deltaRow][colTile+deltaCol]!=colour){ 
        // We check for the same conditions as for checkLegalInDirection
            
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
                         return false;
                     else if (board[rowBeingChecked][colBeingChecked]=='U')
                         return false;
                     else{
                         positionChecked[numberBoxesMoved][0]=rowBeingChecked; // This allows to have all the values of the rows we are checking in an array that updates at evey iteration of the loop
                         positionChecked[numberBoxesMoved][1]=colBeingChecked;
                         numberBoxesMoved++;
                     }
                 }
        }
    }
    return false;
}

void flipRowOfTiles(char board[][26],int n, int rowFlipped, int colFlipped, char colourFlipped){
    for (int deltaRow=-1;deltaRow<=1;deltaRow++){
        for (int deltaCol=-1;deltaCol<=1;deltaCol++){
            if (deltaCol==0 && deltaRow==0){
                deltaCol++;
                flipTile(board,n,rowFlipped,colFlipped,colourFlipped,deltaRow,deltaCol);
            }
            else 
                flipTile(board,n,rowFlipped,colFlipped,colourFlipped,deltaRow,deltaCol);
        }
    }
}

void endGameWinner(char board[][26], int n){ // This functions counts the number of tiles of each player at the end of the game and then prints the winner if there is one, or a draw if the scores are equal
    int whitePlayerScore=0;
    int blackPlayerScore=0;
    for (int rowChecked=0;rowChecked<n;rowChecked++){
        for (int colChecked=0;colChecked<n;colChecked++){
            if (board[rowChecked][colChecked]=='W')
                whitePlayerScore++;
            else if (board[rowChecked][colChecked]=='B')
                blackPlayerScore++;
        }
    }
    if(blackPlayerScore==whitePlayerScore)
        printf("No winner. It is a draw");
    else if(blackPlayerScore>whitePlayerScore)
        printf("B player wins.");
    else if(whitePlayerScore>blackPlayerScore)
        printf("W player wins.");
}
    



                    

/*
 * Function:  makeMove 
 * --------------------
 * The player "turn" makes a move at (row, col).
 * Note: This function MUST NOT change board, only row and col can be changed to reflect the move.
 */


#ifndef COMPETE_MODE // DO NOT DELETE THIS LINE
int main(void) {
    char board [26][26];
    int n;
    int turn;
    char tilePlayer,tileComputer;
    char rowPlayer, columnPlayer;
    int rowComputer, columnComputer;
    
    printf("Enter the board dimension: "); // Ask for the board dimension
    scanf("%d", &n);
    
    printf("Computer plays (B/W) : ");
    scanf(" %c", &tileComputer);
    
    if(tileComputer=='W') // Here we assign the player's tiles to the opposite colour of the computer's tiles
        tilePlayer='B';
    else if (tileComputer=='B')
        tilePlayer='W';
    
    boardInitialization(board,n); // We initialize the board
    printBoard(board,n); // We print the board
    turn='B';
    
    while(movesAvailable(board,n,tileComputer) || movesAvailable(board,n,tilePlayer)){
                if (turn==tileComputer){
                    if (movesAvailable(board,n,tileComputer)==true){ // If the computer has available moves
                        makeMove(board,n,tileComputer, &rowComputer, &columnComputer);
                        printf("Computer places %c at %c%c.\n", tileComputer,rowComputer+'a',columnComputer+'a');
                        board[rowComputer][columnComputer]=tileComputer; // Here we place the tile at the position chosen by the computer
                        flipRowOfTiles(board,n,rowComputer,columnComputer,tileComputer); // We flip the appropriate tiles according to the move made by the computer
                        printBoard(board,n); // We print the new board after the move
                        turn= tilePlayer; // We switch turns after the computer makes a move
                    }
                    else{
                        printf("%c player has no valid move.\n",tileComputer);
                        turn=tilePlayer; // We change turns when the computer enters an invalid move.
                    }
                }
                else if (turn==tilePlayer){
                    if (movesAvailable(board,n,tilePlayer)==true){
                        printf("Enter move for colour %c (RowCol): ",tilePlayer);
                        scanf(" %c%c", &rowPlayer, &columnPlayer);
                        if(canPlaceTile(board,n,rowPlayer-'a',columnPlayer-'a',tilePlayer)==true){
                            board[rowPlayer-'a'][columnPlayer-'a']=tilePlayer; // Here we place the tile at the position chosen by the computer
                            flipRowOfTiles(board,n,rowPlayer-'a',columnPlayer-'a',tilePlayer); // We flip the appropriate tiles according to the move made by the computer
                            printBoard(board,n); // We print the new board after the move
                            turn= tileComputer; // We switch turns after the computer makes a move
                        }
                        else{
                            printf("Invalid move.\n");
                            endGameWinner(board,n);
                            return 0;
                        }
                    }
            
                    else if(movesAvailable(board,n,turn)==false){
                        printf("%c player has no valid move.\n", tilePlayer); // If there is no available moves for the player, then it's the computer's turn
                        turn=tileComputer;
                    }
                }

        
    }
    endGameWinner(board,n);
   
    
    
    return 0;
}



#endif // DO NOT DELETE THIS LINE