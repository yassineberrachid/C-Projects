void populateBoard(bool getUserInput, int board[BOARDROWS+1][BOARDCOLS+1]){
    
    bool validRowInput(int row){ // Checks that the user inputs a valid number of rows (between 1 and 9)
        if (row>=1 && row<=BOARDROWS)
            return true;
        else 
            return false;
    }
    
    bool validColumnInput(int column){ // Checks that the user inputs a valid number of columns (between 1 and 11)
        if (column>=1 && column <=BOARDCOLS)
            return true;
        else 
            return false;
    }
    
    bool validDirectionInput(int direction){ // Checks that the user inputs a valid direction (0 or 1)
        if (direction==0 || direction==1)
            return true;
        else 
            return false;
    }
    bool shipWithinEdges(int row, int column, int size, int direction){ // Checks that the ship does not extend over the board's edges
        if (direction==1){
            if (row+size>=11){ // case where the ship extends past the top and bottom edges (since there are 9 rows)
                return false;
            }
           
        }
        else if (direction==0){
            if (column+size>=13){ // Case where the ship extends past the right or left edges
                return false;
            }
        }
        return true;
    }

    
    bool validUserInput(int row, int column, int size, int direction){ // Checks that the overall inout from the user is valid (row, column and orientation)
        if (validRowInput (row)==true && validColumnInput(column)==true && validDirectionInput(direction)==true && shipWithinEdges(row, column,size,direction)==true){
            return true;
        }
        else 
            return false;
    }
    bool noOverlap(int row, int column, int size, int direction){ // Checks that there is no overlap between ships
            
        for (int i=row; i<row+size; i++){
            if (board[row][column]!=0){ // case where there is ship overlap, since the element of the array is different than 0, which is the initial alue of all elements of the array
                return false;
            }
        }
        for (int j=column; j<column+size; j++){
            if (board[row][column]!=0){
                return false;
            }
        }
    
        return true;
    }
    
    void placeShip(int startingRow, int startingColumn, int size, int direction){ // This places the ship in the position chosen by the user
        if (direction==1){
            for (int row=startingRow; row<startingRow+size; row++){
                board[row][startingColumn]=size; // We stay on the same column and we move vertically, meaning the rows change
            }
        }
        else if (direction==0){
            for (int column=startingColumn; column<startingColumn+size; column++){
                board[startingRow][column]=size; // We stay on the same row and we move horizontally, meaning the columns change
            }
        }
    }
    
    
    if (getUserInput==true){ // This is the case where the user chooses where to place his ships
        int startingRow,startingColumn,directionShip;
        printf("Rows are 1 - 9, Columns are 1 - 11\n");
        printf("Orientation is 0 for across, 1 for down\n");
        for ( int shipSize=5; shipSize>=1; shipSize--){ // The ship sizes go from 5 to 1
            printf("Give starting row, starting column and orientation (3 inputs) for ship of size=%d:", shipSize); // User input statement 
            scanf("%d %d %d", &startingRow, &startingColumn, &directionShip); 
            if (validUserInput(startingRow,startingColumn, shipSize,directionShip)==true){ // This is if the row, the column, and the direction are valid 
                if (noOverlap(startingRow,startingColumn,shipSize, directionShip)==true){ // This is the case where there is no overlap
                    placeShip(startingRow, startingColumn, shipSize, directionShip); // We place the ship is the row, column and direction are valid AND if there is no overlap
                }
                else{
                    printf("Conflicts with ship already placed\n"); // This is the case where there is overlap
                    shipSize++; // We add 1 to the ship size so that when it goes in the for loop again it's going to substract one from shipsize++ and so the same size will go in the 
                    // loop again, every time the user input is invalid or there is overlap
                }
            }
                
            else{ 
                printf("Invalid Input\n"); // This is the case where the user input is invalid
                shipSize++;
            }                
        }
            
        
    }

    else { // Here, we treat the case where we populate the board of the computer, randomly
        
        int rowComputer, columnComputer, directionComputer; // We initialize the variables 
        for ( int shipSize=5; shipSize>=1; shipSize--){
            
            rowComputer=getRand(1,9); // We generate the rows, columns, and direction randomly for the computer using the function getRand
            columnComputer=getRand(1,11);
            directionComputer=getRand(0,1);
            
            if (validUserInput(rowComputer,columnComputer, shipSize,directionComputer)==true){ // Same nested if loops for the computer part, this time with random numbers and not user input
                if (noOverlap(rowComputer,columnComputer,shipSize, directionComputer)==true){
                    placeShip(rowComputer, columnComputer, shipSize, directionComputer);
                }
                else{
                    shipSize++;
                }
            }  
            else{
                shipSize++;
                }
                
        }
            
        
            
        
    }
                
            

    
}