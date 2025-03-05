#include <iostream>
#include <algorithm>
#include <vector>
#include "util.h"
using namespace std;

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
    Recursive function: Completes a 9x9 sudoku puzzle
*/
bool completeGrid(int grid[9][9], int x = 0, int y = 0) {
    if (x >= 9) { 
        x = 0;
        y += 1;
    }
    if (y >= 9) return true;
    if (grid[y][x] != 0) return completeGrid(grid, x + 1, y);

    for (int i = 1; i <= 9; i++) {
        grid[y][x] = i;
        // completeCellDebug(grid, x, y, i);
        if (checkCell(grid, x, y)) {
            if (completeGrid(grid, x + 1, y)) return true;
        }
        grid[y][x] = 0;
    }
    return false;
}

int main() {
    int grid[9][9] = {
        // { 0, 6, 9, 0, 5, 0, 3, 0, 0 } ,
        // { 0, 8, 1, 0, 9, 3, 0, 0, 5 } ,
        // { 0, 0, 5, 4, 8, 0, 0, 1, 0 } ,
        // { 9, 2, 6, 0, 0, 0, 7, 0, 8 } ,
        // { 0, 5, 0, 0, 0, 0, 0, 4, 9 } ,
        // { 0, 0, 0, 0, 0, 9, 6, 0, 1 } ,
        // { 0, 0, 4, 0, 3, 8, 0, 2, 7 } ,
        // { 0, 0, 0, 0, 4, 5, 0, 0, 0 } ,
        // { 5, 1, 0, 2, 7, 6, 8, 0, 4 }
        { 1, 0, 6, 0, 7, 8, 0, 3, 0 } ,
        { 0, 5, 7, 3, 4, 9, 0, 6, 2 } ,
        { 2, 9, 3, 6, 0, 5, 0, 0, 7 } ,
        { 0, 0, 0, 8, 0, 1, 6, 0, 4 } ,
        { 4, 6, 1, 0, 0, 0, 2, 8, 9 } ,
        { 5, 8, 0, 0, 6, 4, 3, 0, 0 } ,
        { 7, 3, 4, 1, 9, 6, 5, 0, 8 } ,
        { 6, 1, 8, 7, 0, 2, 4, 9, 3 } ,
        { 0, 0, 0, 0, 8, 0, 0, 1, 0 }
    };

    completeGrid(grid, 0, 0);
    
    cout << endl << "Final result:" << endl;
    printGrid(grid);
}