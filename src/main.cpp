#include <iostream>
#include <algorithm>
#include <vector>
#include "util.h"
using namespace std;

/*
    Chỉ để debug, ko cần quan tâm đến
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
    Recursive function: Hoàn thiện bảng Sudoku 9x9, 
    
    Hàm có 2 đoạn:
    - (I)  : Tìm kiếm ô trống:
         + Nếu x >= 9 thì sẽ di chuyển sang hàng dưới
         + Nếu y >= 9 thì đã đến cuối bảng
           => Return true
         + Nếu (x,y) ko trống (khác 0) thì di chuyển sang ô bên phải (x + 1)
    - (II) : Tìm kiếm

    Hàm chỉ có 2 trường hợp kết quả:
    1. Hàm di chuyển đến cuối bảng (Ô (9,9))
        => Bảng đã được hoàn thiện
        => Return true
    2. Tại điểm (x,y) ko có giá trị hợp lý
        => Return false
        => Sẽ di chuyển về hàm trước
*/
bool completeGrid(int grid[9][9], int x = 0, int y = 0) {
    // (I)
    // Nếu x >= 9 thì sẽ di chuyển sang hàng dưới
    if (x >= 9) { 
        x = 0;  // Trở về đầu hàng
        y += 1; // Di chuyển đến hàng tiếp theo
    }
    
    // Nếu y >= 9 thì hàm đã đến cuối bảng, nên return true
    if (y >= 9) return true;

    // Nếu ô hiện tại (x,y) khác 0 (nghĩa là không trống) thì sẽ di chuyển sang ô bên cạnh
    if (grid[y][x] != 0) return completeGrid(grid, x + 1, y);

    // (II)
    // Nếu ô (x,y) hiện tại đang trống, thì thử thay giá trị từ 1~9 vào ô đó
    for (int i = 1; i <= 9; i++) {
        grid[y][x] = i;
        // completeCellDebug(grid, x, y, i); // Debugging
        // Nếu giá trị <i> hợp lý, sẽ kiểm tra tiếp ô bên cạnh
        if (checkCell(grid, x, y)) { 
            /*
                Nếu hàm completeGrid trả true
                > Thì nghĩa là hàm đó (hoặc các hàm từ nó) đã đến cuối bảng
                > Nghĩa là bảng đã được hoàn thiện
                > Trả true
            */
            if (completeGrid(grid, x + 1, y)) return true;
        }
        // Nếu giá trị <i> ko hợp lý thì xóa giá trị đấy khỏi ô (x,y)
        grid[y][x] = 0;
    }
    /* 
        Nếu không giá trị nào từ 1~9 hợp lý tại ô (x,y), trả false để di chuyển sang hàm trước đó
        > Hoặc nếu là hàm đầu tiên thì nghĩa là bảng không thể giải được
    */
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
    bool result = completeGrid(grid, 0, 0);
    cout << endl << "Final result:" << endl;
    if (result) printGrid(grid);
    else cout << "Cannot solve grid";
}