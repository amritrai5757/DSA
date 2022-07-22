//Row : horizontal
//1 + 2 = clockwise rotation
//1 + 3 = anti-clockwise rotation
//2 + 3 = 180 degree rotation
    
    //1 : transpose : converting rows into columns & columns into rows
    void transpose(int[][] matrix) {
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {   // imp : for(j=i+1 to n-1)
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    
    //2 : reverse each row like u reverse a 1d array
    void reverseRow(int[][] matrix) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                swap(matrix[i][j],matrix[i][n-1-j]);
            }
        }
    }
    
    //3 : reverse each columns
