#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int MagicSquare(int in[3][3]) //we want square to be 3x3
{
    int SumRow, SumCol, FirstDiagonal, SecondDiagonal;
    //sum of the 3 rows (adds up to 15 each)
    for (int row = 0; row < 3; row++)
    {
        SumRow = 0;
        for (int colu = 0; colu < 3; colu++)
        {
            SumRow += in[row][colu];
        }
    }
    //sum of the 3 columns (adds up to 15 each)
    for (int colu2 = 0; colu2 < 3; colu2++)
    {
        SumCol = 0;
        for (int row2 = 0; row2 < 3; row2++)
        {
            SumCol += in[row2][colu2];
        }
    }
    //sum of the first diagonal (15)
    FirstDiagonal = 0;
    for (int i = 0; i < 3; i++)
    {
        FirstDiagonal += in[i][i];
    }
    //sum of the second diagonal (15)
    for (int i = 2; i >= 0; i--)
    {
        SecondDiagonal = 0;
        for (int j = 0; j < 3; j++)
        {
            SecondDiagonal += in[i][j];
        }
    }
    if (SumRow == 15  && SumCol == 15 && FirstDiagonal == 15 && SecondDiagonal == 15) //they all = 15
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//main (test)
int main()
{
    //make sure it is 3x3 and numbers 1-9
    int testArray[3][3] = {
        {4, 9, 2},
        {3, 5, 7},
        {8, 1, 6},
    };
    int test = MagicSquare(testArray);
    if (test == 1)
    {
        //displaying valid magic square if rows and columns both add up to 15
        printf("This IS a valid magic square.\n");
        for (int i = 0; i < 3; i++)
        {
            //add the brackets []
            printf("[");
            for (int j = 0; j < 3; j++)
            {
                printf("%2d", testArray[i][j]);
            }
            printf("]\n");
        }
    }
    else
    {
        //displays NOT a valid square if rows/columns DO NOT add up to 15
        printf("This is NOT a valid magic square.");
    }
    time_t t; //see how long it takes to get the square 
    //this randomizes the numbers (1-9) each time the program runs it's a different set of numbers
    srand(time(NULL)); //randomizes
    int input[3][3];
    int chk = 0;
    int total = 0;
    while (chk == 0)
    {
        for (int k = 0; k < 3; k++)
        {

            for (int h = 0; h < 3; h++)
            {
                int random = (1 + rand() % 9); //check previous number for duplicate, exclude 0

                input[k][h] = random;
                // printf("%d", input[i][j]);
            }
        }
        chk = MagicSquare(input);
        total++;
    }
    if (chk == 1)
    {
        printf("Number of tries before success: %d \n", total); //print number of times it takes
        printf("This IS a NOT a valid magic square.\n"); //print if not a magic square 
        //(rows and colums do not add to 15)
        for (int i = 0; i < 3; i++)
        {
            printf("[");
            for (int j = 0; j < 3; j++)
            {
                printf("%2d", input[i][j]); //displays the numbers for the square
            }
            printf("]\n");
        }
    }
    else
    {
        printf("This is NOT a valid magic square.");
    }
}