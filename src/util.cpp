#include <iostream>
#include "util.h"
using namespace std;

/*
    Kiểm tra xem nếu trong hàng <row> có chứa số lặp ko

    @param
        + row: Từ 0-8
*/
bool checkRow(int grid[9][9], int row) {
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == 0) continue;
        for (int j = i + 1; j < 9; j++) {
            if (grid[row][j] == grid[row][i]) return false;
        }
    }
    return true;
}

/*
    Kiểm tra xem nếu trong cột <col> có chứa số lặp ko
    
    @param
        + col: Từ 0-8
*/
bool checkCol(int grid[9][9], int col) {
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == 0) continue;
        for (int j = i + 1; j < 9; j++) {
            if (grid[j][col] == grid[i][col]) return false;
        }
    }
    return true;
}

/*
    Kiểm tra xem nếu trong cột <x> và hàng <y> có chứa số lặp ko (CHƯA SỬA XONG, TẠM THỜI DÙNG checkCol() && checkRow() ĐỂ KIỂM TRA)

    @param
        + x: Từ 0-8
        + y: Từ 0-8
*/
bool checkCell(int grid[9][9], int x, int y) {
    // for (int i = 0; i < 9; i++) {
    //     for (int j = i + 1; j < 9; j++) {
    //         if (grid[y][j] == grid[y][i]) return false;
    //         if (grid[j][x] == grid[i][x]) return false;
    //     }
    // }
    return true;
}

/*
    Tìm ô trống (là số 0) đầu tiên trong hàng <row>
    
    @param
        + row: Từ 0-8
    
    => Trả index từ 0-8
       Nếu ko tìm được thì trả gtri -1
*/
int findFirstEmptyRow(int grid[9][9], int row) {
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == 0) return i;
    }
    return -1;
}

/*
    Tìm ô trống (là số 0) đầu tiên trong cột <col>
    
    @param
        + col: Từ 0-8
    
    => Trả index từ 0-8
       Nếu ko tìm được thì trả gtri -1
*/
int findFirstEmptyCol(int grid[9][9], int col) {
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == 0) return i;
    }
    return -1;
}

/*
    In ra grid
*/
void printGrid(int grid[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] == 0) cout << "-  ";
            else cout << grid[i][j] << "  ";
        }
        cout << endl;
    }
}

/*
    Lấy tất cả các giá trị còn dùng được trong hàng
    ( VD: Hàng { 1, 0, 0, 3, 2, 5, 0, 6, 7 } => { 0, 0, 0, 4, 0, 0, 0, 8, 9 } )
*/
void getAvailableRow(int grid[9][9], int row, int* available) {
    for (int i = 0; i < 9; i++) {
        int val = grid[row][i];
        if (val != 0) {
            available[val - 1] = 0;
        }
    }
}

/*
    Lấy tất cả các giá trị còn dùng được trong cột
    ( VD: Hàng { 1, 0, 0, 3, 2, 5, 0, 6, 7 } => { 0, 0, 0, 4, 0, 0, 0, 8, 9 } )
*/
void getAvailableCol(int grid[9][9], int col, int* available) {
    for (int i = 0; i < 9; i++) {
        int val = grid[i][col];
        if (val != 0) {
            available[val - 1] = 0;
        }
    }
}