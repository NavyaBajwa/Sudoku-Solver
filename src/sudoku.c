#include "sudoku.h"

int UNSOLVED = 81;
int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;

int main()
{
    int ** puzzle;
    int progress = 0;
    Sudoku * sudoku;

    puzzle = createPuzzle();

    sudoku = setUpPuzzle(puzzle);

    printPuzzle(sudoku->squares);
    //printf("hewy dawg");


   while (UNSOLVED > 0)
    {
        //printf("UNSOLVED before the check %d\n", UNSOLVED);
       
        progress = checkPuzzle(sudoku->squares, sudoku->boxes);
       
        //printf("progress %d\n", progress);
        //printf("UNSOLVED after the check %d\n", UNSOLVED);

        if (progress == 0)
        {
            printf("\nFailed to solve the puzzle!\n\n");
            break;
        }
    }


    //for (i = 0; i < 100; i++) 
    //{
     //   checkPuzzle(sudoku->squares, sudoku->boxes);
    //}

printf("Final Puzzle State:\n");
printPuzzle(sudoku->squares);

    return 0;
}