bool checkRow(int grid[9][9], int row);

bool checkCol(int grid[9][9], int col);

bool checkCell(int grid[9][9], int x, int y);

int findFirstEmptyRow(int grid[9][9], int row);

int findFirstEmptyCol(int grid[9][9], int col);

void printGrid(int grid[9][9]);

void getAvailableRow(int grid[9][9], int row, int* available);

void getAvailableCol(int grid[9][9], int col, int* available);

bool checkSubGrid(int grid[9][9], int x, int y);