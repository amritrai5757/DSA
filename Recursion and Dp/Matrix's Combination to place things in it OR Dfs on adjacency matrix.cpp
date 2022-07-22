TC: o(n!) // NOTE : ALL QUESTIONS ARE on SQUARE MATRIX & BOUNDED
// Que : Print all combinations(not 1 combination) to place n queen in n*n board. eg: 4*4
// Ans : in form of [2,3,1,4],  [ 1,2,4,3]  (it means there are 2 combinations in 2,3,1,4 denotes that we can put 1st queen in 2 column in 1st row and 2nd q in 3 col of 2nd row and so on

bool isQueenSafe(int row,int col,vector<vector<int>> chess){
    for(int i=row-1,j=col;i>=0;i--)if(chess[i][j]==1) return false;  // Check upper row
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--) if(chess[i][j]==1) return false;  // Check diagonals
    for(int i=row-1,j=col+1;i>=0 && j< chess.size();i--,j++) if(chess[i][j]==1) return false; // Check diagonals
    return true;
}

void printNQueens(vector<vector<int>> chess,string qsf,int row){
    if(row==chess.size()){              //Base condition
        cout << qsf << ". "<<endl;    
        return;
    }
    for(int col=0;col<chess.size();col++){     
        if(isQueenSafe(row,col,chess)){ //Boundry conditions
            chess[row][col]=1;          
            printNQueens(chess,qsf+to_string(row)+"-"+to_string(col)+", ",row+1);
            chess[row][col]=0;          //Backtracking to explore all solutions
        }
    }
}


//For printing all combination of nKnight so that they cant attack each-other
      void isKnightSafe(int i, int j, char a,char** board){
           if ((i + 2) < m && (j - 1) >= 0) board[i + 2][j - 1] = a;
           if ((i - 2) >= 0 && (j - 1) >= 0)board[i - 2][j - 1] = a;
           if ((i + 2) < m && (j + 1) < n)  board[i + 2][j + 1] = a;
           if ((i - 2) >= 0 && (j + 1) < n) board[i - 2][j + 1] = a;
           if ((i + 1) < m && (j + 2) < n)  board[i + 1][j + 2] = a;
           if ((i - 1) >= 0 && (j + 2) < n) board[i - 1][j + 2] = a;
           if ((i + 1) < m && (j - 2) >= 0) board[i + 1][j - 2] = a;
           if ((i - 1) >= 0 && (j - 2) >= 0)board[i - 1][j - 2] = a;
      }


Sudoku:-

bool isSafe(int grid[N][N], int row, int col, int num){
    for (int x = 0; x <= 8; x++) if (grid[row][x] == num) return false;
    for (int x = 0; x <= 8; x++) if (grid[x][col] == num) return false;
    
    int startRow = row - row % 3; 
    int startCol = col - col % 3;
   
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num) return false;
 
    return true;
} 

bool solveSudoku(int grid[N][N], int row, int col){
    if (row == N - 1 && col == N)
        return true;
    if (col == N) { 
        row++;
        col = 0;
    }
   
    if (grid[row][col] > 0) return solveSudoku(grid, row, col + 1);
 
    for (int num = 1; num <= N; num++) {
        if (isSafe(grid, row, col, num)){
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1))
                return true;
        }
        grid[row][col] = 0;
    }
    return false;
}
