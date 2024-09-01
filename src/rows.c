#include "sudoku.h"

int checkRows(Square *** sudoku, Box ** boxes)
{
    int i, j, k;
    int sum[9];
    int place[9];

    for (i = 0; i < 9; i++)
    {
        // Initialize the arrays
        for (j = 0; j < 9; j++)
        {
            place[j] = 0;
            sum[j] = 0;
        }

        // Loop through each square in the row
        for (j = 0; j < 9; j++)
        {
            if (sudoku[i][j]->number != 0)
            {
                continue; // Skip non-empty squares
            }

            // Loop through all possible values for the empty square
            for (k = 0; k < 9; k++)
            {
                // Check if number (k) is possible for the current square
                if (sudoku[i][j]->possible[k] == 0)
                {
                    sum[k]++;
                    place[k] = j;
                }
            }
        }

        // Check if there's only one possible value for any empty square in the row
        for (k = 0; k < 9; k++)
        {
            if (sum[k] == 1)
            {
                // Place the number and update the puzzle
                sudoku[i][place[k]]->number = k + 1;
                sudoku[i][place[k]]->solvable = 0;
                UNSOLVED--;

                // Update the Sudoku grid and boxes
                updateSudoku(sudoku, i, place[k]);
                updateBoxes(sudoku, i, place[k]);

                return 1; // Return 1 to indicate progress
            }
        }
    }

    return 0; // Return 0 to indicate no progress
}
