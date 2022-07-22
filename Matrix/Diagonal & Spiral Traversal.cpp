// Note: Whenever direction of traversal changes make another loop for that direction traversal for both diagonal and spiral traversal


//Diagonal:
vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        vector<int>v;
        if(m==0)return v;
        int n=matrix[0].size();
        int i=0,j=0;
        
        for(int i=0;i<m+n-1;i++){
            if(i%2==1)               // This if is for alternating directions , if(i%2==1) travese diagonal from bottom to up otherwise top to bottom
            for(int j=i;j>=0;j--){
                   if(j<n&&i-j<m)
                   v.push_back(matrix[i-j][j]);
            }
            else
            for(int j=i;j>=0;j--){
                    if(j<m&&(i-j)<n)
                       v.push_back(matrix[j][i-j]);
            }
            
        }
        
        return v;
}

//Spiral :
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m=matrix.size();
    int n=matrix[0].size();
    
    vector<int> res;
    
    int left=0;
    int right=n-1;
    int upper=0;
    int lower=m-1;
    
    while(left<=right && upper<=lower){
        for(int i=left;i<=right;i++){
             res.push_back(matrix[upper][i]);
        }
        upper++;
        if(upper>lower)break;
        
        for(int i=upper;i<=lower;i++){
         res.push_back(matrix[i][right]);
        }
        right--;
        if(left>right)break;
        
        for(int i=right;i>=left;i--){
            res.push_back(matrix[lower][i]);
        }
        lower--;
        if(upper>lower)break;
        
        for(int i=lower;i>=upper;i--){
            res.push_back(matrix[i][left]);
        }
        left++;
        if(left>right)break;
    }
    
    return res;
}
