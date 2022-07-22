//Count Square Submatrices with All ones in a binary matrix
// No recursion available for this✔
int countSquares(vector<vector<int>>& matrix) {
		int count =0;

		for(int i=0;i<matrix.size();++i)
			for(int j=0;j<matrix[0].size();++j)
				if(i!=0 && j!=0 && matrix[i][j])  
					matrix[i][j] = 1 + min(matrix[i-1][j],min(matrix[i][j-1],matrix[i-1][j-1]));
        
				 ans +=matrix[i][j];                //For max area square submatrix with all ones : ans = max(matrix[i][j], ans);
        
		return ans;
}
