#include <iostream>
#include "util.h"
using namespace std;

/*
    Kiểm tra nếu ô 3x3 chứa điểm (x,y) có hợp lý không (Kiểm tra xem nếu ô 3x3 có lặp giá trị nào)
*/
bool checkSubGrid(int grid[9][9], int x, int y) {
    /*
        Tìm (x,y) thuộc ô 3x3 nào 
        (VD: Tọa độ (1,4) thuộc ô 3x3 (0,1))

        | - - - | - - - | - - - |
        | - - - | - - - | - - - |
        | - - - | - - - | - - - |
        -------------------------
        | - - - | - - - | - - - |
        | - X - | - - - | - - - |
        | - - - | - - - | - - - |
        -------------------------
        | - - - | - - - | - - - |
        | - - - | - - - | - - - |
        | - - - | - - - | - - - |
    */
    int gx = x / 3; // 0~2
    int gy = y / 3; // 0~2

    /*
        Mảng <available>: Mảng chứa các giá trị đã tồn tại trong ô 3x3
    */
    int available[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    
    // Tìm kiếm ô nào lặp
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int val = grid[gx * 3 + i][gy * 3 + j]; // Lấy giá trị trong ô 3x3
            if (val == 0) continue; // Nếu giá trị đó = 0 thì bỏ qua
            /*
                Nếu giá trị đó khác 0
                => Kiểm tra vị trí (giá trị ô đó - 1) trong mảng <available>:
                   + Nếu khác 0 
                     => Đã tồn tại giá trị đó trong ô 3x3
                     => return false
                   + Nếu bằng 0
                     => Thêm số đó vào trong mảng <available>

                VD:
                   - Ô có giá trị 3
                   > Kiểm tra nếu tại vị trí (3 - 1) có phải 0 ko:
                     > Có? 
                       => Giá trị được cho vào mảng <available>, nếu trong tương lai hàm tìm được số 3 khác thì sẽ return false
                     > Không?
                       => Giá trị đã tồn tại trong ô 3x3, return false
            */
            if (available[val - 1] == 0) {
                available[val - 1] = val;
            }
            else {
                return false;
            }
        }
    }
    return true;
}

/*
    Kiểm tra xem nếu trong cột <x> và hàng <y> có chứa số lặp ko

    @param
        + x: Từ 0-8
        + y: Từ 0-8
*/
bool checkCell(int grid[9][9], int x, int y) {
    for (int i = 0; i < 9; i++) {
        // Xét các ô trong hàng <y>
        if (grid[y][i] == grid[y][x] && i != x) return false;
        // Xét các ô trong cột <x>
        if (grid[i][x] == grid[y][x] && i != y) return false;
    }
    // Kiểm tra nếu ô 3x3 chứa điểm (x,y) có hợp lý
    return checkSubGrid(grid, x, y);
}

/*

    LƯU Ý: Các hàm từ điểm này là chưa có ứng dụng cụ thể nào trong code chính, có thể sẽ ứng dụng được để tối ưu hóa nhưng chưa implement.

*/

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