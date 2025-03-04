#include <iostream>
#include <algorithm>
#include <vector>
#include "util.h"
using namespace std;



bool completeCell(int grid[9][9], int x, int y) {
    cout << "Completing cell: (" << (x + 1) << ", " << (y + 1) << ")" << endl;
    if (grid[y][x] != 0 && checkCell(grid, x, y)) return true;
    for (int i = 1; i <= 9; i++) {
        grid[y][x] = i;
        //if (checkCell(grid, x, y)) {
        if (checkCol(grid, x) && checkRow(grid, y)) {
            cout << "Value " << i << " valid" << endl << endl;
            return true;
        }
    }
    
    // Đoạn debug
    cout << "Can't use any value" << endl;
    int availR[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int availC[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    getAvailableRow(grid, y, availR);
    getAvailableRow(grid, x, availC);
    cout << "Available in Row: ";
    for (int i = 0; i < 9; i++) {
        if (availR[i] == 0) continue;
        cout << availR[i] << " ";
    }
    cout << endl;
    cout << "Available in Col: ";
    for (int i = 0; i < 9; i++) {
        if (availC[i] == 0) continue;
        cout << availC[i] << " ";
    }
    cout << endl << endl;
    //

    grid[y][x] = 0;
    return false;
} 

int main() {
    int grid[9][9] = {
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
    
    int prv_x = 0;
    int prv_y = 0;
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            if (grid[y][x] == 0) {
                if (!completeCell(grid, x, y)) {
                    printGrid(grid);
                    cout << "Previous X: " << prv_x << endl;
                    cout << "Previous Y: " << prv_y << endl;
                    cout << endl << endl;
                }
                prv_x = x;
                prv_y = y;
            }
        }
    }
    
    cout << "Final result:" << endl;
    printGrid(grid);
}