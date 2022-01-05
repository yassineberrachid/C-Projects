// This program prints asks the user to enter a number of rows, and then prints the Pascal triangle that has the number of rows entered
// by the user. The Pascal triangle is a representation of the binomial coefficients nCr in a triangle, in a particular order.

#include <stdio.h>

int factorial(int n){ // This is the function that calculates the factorial of a number 
    int nextInteger=0;
    int resultFactorial=1;
    for (nextInteger=1; nextInteger<=n;nextInteger++){
        resultFactorial=resultFactorial*nextInteger; // For loop that multiplies the previous product to the next integer (factorial calculation)
    }
    return resultFactorial; // The function returns the factorial of the number entered
}

int choose (int n, int r){ // This function calculates the result of nCr, meaning the binomial coefficients 
    int resultChoose= (factorial(n))/(factorial(r)*factorial(n-r)); // Formula to calculate nCr
    return resultChoose;
}

void triangle(int numberRowsUser){ // this is the function that print the Pascal triangle 
    
  for (int row = 0; row < numberRowsUser; row++) // Outer loop that controls the rows of the triangle 
  {
    for (int spaces =1; spaces < (numberRowsUser - row); spaces++){ // First inner loop that prints the spaces before the first column in each row
        printf("   "); // We print 3 spaces because the number of spaces before the first column in each line is (numberRowsUser-row)*3
    }
      
 
    for (int column = 0 ; column <= row; column++){ // Second inner loop that controls that prints the binomial coefficients nCr
        printf("%-6d", choose(row,column)); // The -6 comes from the fact that 
    }
    
    printf("\n"); // This prints a new line at the end of each iteration of the for loop, to go to the next row of the triangle
  }  
  
}

int main() // main function in which we will call the triangle function
{
    int numberRowsUser;
    while (numberRowsUser>=0){ // This is because the program should terminate if the user enters a negative number of rows
        printf("Enter the number of rows: ");
        scanf("%d",&numberRowsUser);
        triangle(numberRowsUser); // Here, we call the function triangle with parameter being the number of rows entered by the user
    }
   
}

