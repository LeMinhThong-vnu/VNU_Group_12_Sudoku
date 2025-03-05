#include <iostream>
#include <algorithm>
#include <vector>
#include "util.h"
using namespace std;

// I accidentally wrote this section in English, sorry ;(

/*
    For debugging purposes: Displays available numbers in that row and column
*/
void completeCellDebug(int grid[9][9], int x, int y, int n) {
    int availR[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int availC[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    getAvailableRow(grid, y, availR);
    getAvailableCol(grid, x, availC);
    cout << "- Checking value: " << n << endl;
    cout << "- Available in Row: ";
    for (int i = 0; i < 9; i++) {
        if (availR[i] == 0) continue;
        cout << availR[i] << " ";
    }
    cout << endl;
    cout << "- Available in Col: ";
    for (int i = 0; i < 9; i++) {
        if (availC[i] == 0) continue;
        cout << availC[i] << " ";
    }
    cout << endl;
    cout << endl;
}

/*
    Recursive function: Completes a 9x9 sudoku puzzle, only 2 possibilities:
    1. The function has reached the end of the grid 
        => The grid has been completed 
        => Return true
    2. Position (x, y) has no valid number
        => Return false
        => Go back to previous to check other numbers
*/
bool completeGrid(int grid[9][9], int x = 0, int y = 0) {
    // If x >= 9 then move to the row below
    if (x >= 9) { 
        x = 0;  // Goto start of row
        y += 1; // Goto next row
    }
    
    // If y >= 9 then function has reached end of grid, end function
    if (y >= 9) return true;

    // If the current cell is occupied (!= 0) then go to the next cell
    if (grid[y][x] != 0) return completeGrid(grid, x + 1, y);

    // Check values 1~9
    for (int i = 1; i <= 9; i++) {
        grid[y][x] = i;
        // completeCellDebug(grid, x, y, i); // Debugging
        // If value <i> is valid
        if (checkCell(grid, x, y)) { 
            // If yes, complete the next cell: See above
            if (completeGrid(grid, x + 1, y)) return true;
        }
        grid[y][x] = 0;
    }
    return false;
}

int main() {
    int grid[9][9] = {
        // VD1:
        // { 0, 6, 9, 0, 5, 0, 3, 0, 0 } ,
        // { 0, 8, 1, 0, 9, 3, 0, 0, 5 } ,
        // { 0, 0, 5, 4, 8, 0, 0, 1, 0 } ,
        // { 9, 2, 6, 0, 0, 0, 7, 0, 8 } ,
        // { 0, 5, 0, 0, 0, 0, 0, 4, 9 } ,
        // { 0, 0, 0, 0, 0, 9, 6, 0, 1 } ,
        // { 0, 0, 4, 0, 3, 8, 0, 2, 7 } ,
        // { 0, 0, 0, 0, 4, 5, 0, 0, 0 } ,
        // { 5, 1, 0, 2, 7, 6, 8, 0, 4 }
        // VD2:
        { 0, 0, 0, 2, 6, 0, 7, 0, 1 } ,
        { 6, 8, 0, 0, 7, 0, 0, 9, 0 } ,
        { 1, 9, 0, 0, 0, 4, 5, 0, 0 } ,
        { 8, 2, 0, 1, 0, 0, 0, 4, 0 } ,
        { 0, 0, 4, 6, 0, 2, 9, 0, 0 } ,
        { 0, 5, 0, 0, 0, 3, 0, 2, 8 } ,
        { 0, 0, 9, 3, 0, 0, 0, 7, 4 } ,
        { 0, 4, 0, 0, 5, 0, 0, 3, 6 } ,
        { 7, 0, 3, 0, 1, 8, 0, 0, 0 }
        // VD3:
        // { 1, 0, 6, 0, 7, 8, 0, 3, 0 } ,
        // { 0, 5, 7, 3, 4, 9, 0, 6, 2 } ,
        // { 2, 9, 3, 6, 0, 5, 0, 0, 7 } ,
        // { 0, 0, 0, 8, 0, 1, 6, 0, 4 } ,
        // { 4, 6, 1, 0, 0, 0, 2, 8, 9 } ,
        // { 5, 8, 0, 0, 6, 4, 3, 0, 0 } ,
        // { 7, 3, 4, 1, 9, 6, 5, 0, 8 } ,
        // { 6, 1, 8, 7, 0, 2, 4, 9, 3 } ,
        // { 0, 0, 0, 0, 8, 0, 0, 1, 0 }
    };
    cout << "Input:" << endl;
    printGrid(grid);
    completeGrid(grid, 0, 0);
    cout << endl << "Final result:" << endl;
    printGrid(grid);
}