// ALL QUESTIONS ARE BOUNED unlike unbounded subset & on SQUARE MATRIX

void queensPermutations(int qpsf, int tq, int[][] chess){
        if(qpsf == tq){
            for(int row = 0; row < chess.length; row++){
                for(int col = 0; col < chess.length; col++){
                    System.out.print(chess[row][col] != 0? "q"+ chess[row][col] + "\t": "-\t");
                }
                System.out.println();
            }
            System.out.println();
            return;
        }
        
        for(int row = 0; row < chess.length; row++){
            for(int col = 0; col < chess.length; col++){
                if(chess[row][col] == 0){
                    chess[row][col] = qpsf + 1;
                    queensPermutations(qpsf + 1, tq, chess);
                    chess[row][col] = 0;
                }
            }
        }
}





//CROSSWORD PUZZLE : A matrix is provided with + - sign and there is vector of strings which need to filled in matrix. Only - can be filled. eg : car should remain car while filling it cant be filled in arc.

vector<string> checkHorizontal(int x, int y, vector<string> matrix, string currentWord){
    int n = currentWord.length();
    for (int i = 0; i < n; i++) {
        if (matrix[x][y + i] == '#' || matrix[x][y + i] == currentWord[i]) matrix[x][y+i] = currentWord[i];
        else {
            matrix[0][0] = '@';
            return matrix;
        }
    }
    return matrix;
}

vector<string> checkVertical(int x, int y, vector<string> matrix, string currentWord){
    int n = currentWord.length();
    for (int i = 0; i < n; i++) {
        if (matrix[x + i][y] == '#' || matrix[x + i][y] == currentWord[i]) matrix[x + i][y] = currentWord[i];
        else {
            matrix[0][0] = '@';
            return matrix;
        }
    }
    return matrix;
}
  
void solvePuzzle(vector<string>& words, vector<string> matrix, int index, int n){
    if (index < words.size()) {
        string currentWord = words[index];
        int maxLen = n - currentWord.length();
  
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= maxLen; j++) {
                vector<string> temp = checkVertical(j, i, matrix, currentWord);
                if (temp[0][0] != '@') solvePuzzle(words, temp, index + 1, n);
            }
        }
  
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= maxLen; j++) {
                vector<string> temp = checkHorizontal(i, j, matrix, currentWord);
                if (temp[0][0] != '@') solvePuzzle(words, temp, index + 1, n);
            }
        }
    }
    else {
        cout << (ways + 1) << " way to solve the puzzle "<< endl;
        printMatrix(matrix, n);
        cout << endl;
        ways++;
        return;
    }
}
