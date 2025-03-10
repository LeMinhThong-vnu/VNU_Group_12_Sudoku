# Nhóm-12 0 Sudoku
## 1. Thông tin thành viên
| STT | Họ và tên | MSSV | Vai trò |
|---|---|---|---|
| 1 | Lê Minh Thông | 24022835 | Nhóm trưởng |
| 2 | Đỗ Anh Khoa | 24022805 | Thành viên |
| 3 | Trịnh Văn Sơn | 24022829 | Thành viên |
| 4 | Nguyễn Tú Tài | 24022830 | Thành viên |
| 5 | Nguyễn Tiến Đạt | 24022774 | Thành viên |

## 2. Thông tin bài tập
**Sudoku:** Cho bảng Sudoku 9x9. Một số ô đã điền số. Dùng đệ quy + quay lui để điền đủ bảng.

***(Nếu bạn đã biết luật chơi Sudoku bạn có thể bỏ qua phần này)***

*Sudoku* có 3 quy luật chính để hoàn thiện bảng:

1. Mỗi hàng chỉ có thể chứa các số từ 1~9 và không thể lặp
2. Mỗi cột chỉ có thể chứa các số từ 1~9 và không thể lặp
3. Mỗi ô 3x3 làm nên bảng chỉ có thể chứa số từ 1~9 và không thể lặp

![alt](https://thumbs.dreamstime.com/b/background-black-white-sudoku-game-its-solution-image-depicts-183172036.jpg) 

## 3. Hướng giải quyết bài toán
Code sẽ chứa 2 bộ phận chính:

1. **Hàm kiểm tra bảng/ô "hợp lý":** Kiểm tra xem bảng hoặc ô nào đó có theo 3 quy luật Sudoku
2. **Hàm đệ quy để giải bảng**

Hàm **(1)** là hàm `checkCell` và `checkSubGrid()` và hàm **(2)** là `completeGrid()`.

Hướng giải quyết cơ bản là theo các bước sau:

1. Tìm kiếm một ô trống. Nếu không còn ô trống nào nữa (nghĩa là đã di chuyển đến cuối bảng), thì trả **`true`**

2. Thay thử vào ô trống vừa tìm được các giá trị 1~9.

    **TH1:** Nếu giá trị đó hợp lý, quay lại bước **(1)** và tìm ô trống tiếp theo.
    
    **TH2:** Nếu giá trị không hợp lý, thử giá trị khác. 
    
    **TH3:** Nếu không giá trị nào hợp lý thì sẽ trả giá trị **`false`**; Nếu đây là hàm gọi đầu tiên, có nghĩa là bảng không có cách giải

## 4. Ưu điểm - Ngược điểm

| Ưu điểm | Ngược điểm |
|---|---|
| - **Đơn giản:** Code sử dụng thuật toán đệ quy đơn giản để giải quyết bài toán Sudoku. Cách tiếp cận này dễ hiểu và dễ triển khai. | - **Hiệu suất thấp:** Phương pháp này sử dụng đệ quy và kiểm tra tất cả các giá trị có thể, dẫn đến thời gian xử lý lâu đặc biệt là với các bảng có nhiều ô trống. |
| - **Sự hiệu quả:** Hàm có thể giải quyết mọi bảng Sudoku hợp lệ bằng cách kiểm tra tất cả các khả năng. | - **Dễ gây lỗi stack overflow:** Với các bảng Sudoku lớn hoặc phức tạp, hàm đệ quy có thể gây ra stack overflow do độ sâu của đệ quy quá lớn. |

## 5. Ví dụ
### *5.1 VD1:*
+ *Input:*
```
0  0  0  2  6  0  7  0  1
6  8  0  0  7  0  0  9  0
1  9  0  0  0  4  5  0  0
8  2  0  1  0  0  0  4  0
0  0  4  6  0  2  9  0  0
0  5  0  0  0  3  0  2  8
0  0  9  3  0  0  0  7  4
0  4  0  0  5  0  0  3  6
7  0  3  0  1  8  0  0  0
```
+ *Output:*
```
4  3  5  2  6  9  7  8  1
6  8  2  5  7  1  4  9  3
1  9  7  8  3  4  5  6  2
8  2  6  1  9  5  3  4  7
3  7  4  6  8  2  9  1  5
9  5  1  7  4  3  6  2  8
5  1  9  3  2  6  8  7  4
2  4  8  9  5  7  1  3  6
7  6  3  4  1  8  2  5  9
```
### *5.2 VD2:*
+ *Input:*
```
0  0  0  2  6  0  7  0  1
6  8  0  0  7  0  0  9  0
1  9  0  0  0  4  5  0  0
8  2  0  1  0  0  0  4  0
0  0  4  6  0  2  9  0  0
0  5  0  0  0  3  0  2  8
0  0  9  3  0  0  0  7  4
0  4  0  0  5  0  0  3  6
7  0  3  0  1  8  0  0  0
```
+ *Output:*
```
4  3  5  2  6  9  7  8  1
6  8  2  5  7  1  4  9  3
1  9  7  8  3  4  5  6  2
8  2  6  1  9  5  3  4  7
3  7  4  6  8  2  9  1  5
9  5  1  7  4  3  6  2  8
5  1  9  3  2  6  8  7  4
2  4  8  9  5  7  1  3  6
7  6  3  4  1  8  2  5  9
```
### *5.3 VD3:*
+ *Input:*
```c++
// Ô (0,0) không hợp lý
1  0  0  2  6  0  7  0  1
6  8  0  0  7  0  0  9  0
1  9  0  0  0  4  5  0  0
8  2  0  1  0  0  0  4  0
0  0  4  6  0  2  9  0  0
0  5  0  0  0  3  0  2  8
0  0  9  3  0  0  0  7  4
0  4  0  0  5  0  0  3  6
7  0  3  0  1  8  0  0  0
```
+ *Output:*
```
Cannot solve grid
```

## 6. Các hàm

### `bool checkCell(int grid[9][9], int x = 0, int y = 0)`

**Ứng dụng:** Kiểm tra nếu ô (x,y) có hợp lý không. *(Kiểm tra xem hàng `y` và cột `x` có lặp giá trị nào và sau đó gọi hàm `checkSubGrid`)*

**Parameters:**
| Tên | Loại | Vai trò |
|---|---|---|
| grid | Mảng 2 chiều 9x9 | Chứa bảng; ô chứa giá trị 0 được coi là trống. |
| x | int | Vị trí x của bảng; được dùng để lấy giá trị trong hàng. |
| y | int | Vị trí y của bảng; được dùng để lấy hàng từ bảng. |

**Returns:** Giá trị `bool`, **`true`** nghiã là ô là hợp lý và ngược lại

### `bool checkSubGrid(int grid[9][9], int x = 0, int y = 0)`

**Ứng dụng:** Kiểm tra nếu miền 3x3 chứa điểm (x,y) có hợp lý không. *(Kiểm tra xem nếu ô 3x3 có lặp giá trị nào)*

**Parameters:**
| Tên | Loại | Vai trò |
|---|---|---|
| grid | Mảng 2 chiều 9x9 | Chứa bảng; ô chứa giá trị 0 được coi là trống. |
| x | int | Vị trí x của bảng; được dùng để lấy giá trị trong hàng. |
| y | int | Vị trí y của bảng; được dùng để lấy hàng từ bảng. |

**Returns:** Giá trị `bool`, **`true`** nghiã là miền 3x3 chứa ô là hợp lý và ngược lại

### `bool completeGrid(int grid[9][9], int x = 0, int y = 0)`

**Ứng dụng:** Hàm đệ quy; Hoàn thiện bảng Sudoku 9x9; thay giá trị thẳng vào mảng `grid` được chuyền vào.

**Parameters:**
| Tên | Loại | Vai trò |
|---|---|---|
| grid | Mảng 2 chiều 9x9 | Chứa bảng; ô chứa giá trị 0 được coi là trống. |
| x | int | Vị trí x của bảng; được dùng để lấy giá trị trong hàng. |
| y | int | Vị trí y của bảng; được dùng để lấy hàng từ bảng. |

**Returns:** Giá trị `bool`:

1. Nếu là hàm gọi đầu tiên; **`true`** nghĩa là bảng đã hoàn thiện; **`false`** nghĩa là bảng không thể giải được.
2. Nếu là hàm được gọi đệ quy; **`true`** nghĩa là bảng đã hoàn thiện; **`false`** nghĩa là cần thử một giá trị khác ở ô trước nào đó.

## 7. Video giới thiệu

[![Video](https://i.ytimg.com/vi/-H_QhrTp1lM/hqdefault.jpg?sqp=-oaymwFBCNACELwBSFryq4qpAzMIARUAAIhCGAHYAQHiAQoIGBACGAY4AUAB8AEB-AGKCIAC0AWKAgwIABABGGUgZShlMA8=&rs=AOn4CLDw54UPVGuG-kMrBgkmvzmuysqhGQ)](
https://youtu.be/-H_QhrTp1lM?si=MshJOAM3nO-gPqOx)

## 7. Source Code
[*Link*](https://github.com/LeMinhThong-vnu/VNU_Group_12_Sudoku/tree/main/src)
