// Either subarrays are :
// 1.Nested subarrays : We need to check all subarrays along with subarrays formed by solving original subarrays .eg :Matrix chain multiplication (mcm), boolean parenthesization (ways we can solve the an array like 1^0&1|0 to get 1 : (((1^0)&1)|0) or (1^((0&1)|0) etc)
// 2.Dependent on external factor. eg: egg dropping (floors partitioning is also dependent on eggs)
// Combination or Ways ques= boolean parenthesization else all are min max question


int f(int i,int j,vector<int> &arr, vector<vector<int>>&dp){
    if(i==j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    dp[i][j]=INT_MAX;
    for(int k=i;k<j;k++){
        dp[i][j]=min(dp[i][j] , arr[i-1]*arr[k]*arr[j] +f(i,k,arr,dp) + f(k+1,j,arr,dp));// operaton assuming left subarray solved & becomes 1 sized & right solved + calling left and right subaarray
    }
    return dp[i][j];
}

int solve(vector<int>&arr,int N){
    vector<vector<int>>dp(N,vector<int>(N,-1));
    return f(1,N-1,arr,dp);
}

TABULATION :
int solve(vector<int>&arr,int N){
    int dp[N][N];
    for(int i=N-1;i>=1;i++){         
        for(int j=i+1;j<N;j++){   //j =0-n-1 accordin to recursion but we know j must be always in right of j in recursion so it doesnt make sense to run j from 0 to n-1 =i+1 to n-1 
            int mini=1e9;  dp[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                dp[i][j]=min(dp[i][j] , arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j]);
            }
        }
    }
    return dp[1][N-1];
}

    
    
    
// BOOLEAN PARENTHESIS : Ways/combinations to get true
int dp[101][101][2];
int parenthesis_count(string s, int i, int j, int isTrue){
    if (i > j) return false;
    if (i == j) {
        if (isTrue == 1) return s[i] == 'T';
        else return s[i] == 'F';
    }
 
    if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
    int ans = 0;
    for (int k = i + 1; k <= j-1; k = k + 2){
        int leftF, leftT, rightT, rightF;
        // RECURSION ON LEFT SUBARRAY & RIGHT SUBARRAY :
        
        if (dp[i][k - 1][1] == -1) leftT = parenthesis_count(s, i, k - 1, 1); // Count no. of T in left partition
        else leftT = dp[i][k - 1][1];
 
        if (dp[k + 1][j][1] == -1) rightT = parenthesis_count(s, k + 1, j, 1);// Count no of T in right partition
        else rightT = dp[k + 1][j][1];
        
        if (dp[i][k - 1][0] == -1) leftF = parenthesis_count(s, i, k - 1, 0);  // Count no. of F in left partition
        else leftF = dp[i][k - 1][0];
 
        if (dp[k + 1][j][0] == -1) rightF = parenthesis_count(s, k + 1, j, 0);  // Count no. of F in right partition
        else rightF = dp[k + 1][j][0];
        
        // OPERATIONS ASSUMING LEFT SUBARRAY & RIGHT SUBARRAY SOLVED :
        if (s[k] == '&'){
            if (isTrue == 1) ans += leftT * rightT;   // ways to get true with & operator
            else ans += leftF * rightF + leftT * rightF + leftF * rightT; //ways to get false with & operator
        }
        else if (s[k] == '|'){
            if (isTrue == 1) ans += leftT * rightT + leftT * rightF + leftF * rightT;
            else ans = ans + leftF * rightF;
        }
        else if (s[k] == '^'){
            if (isTrue == 1)ans = ans + leftF * rightT + leftT * rightF;
            else ans = ans + leftT * rightT + leftF * rightF;
        }
        dp[i][j][isTrue] = ans;
    }
    return ans;
}
