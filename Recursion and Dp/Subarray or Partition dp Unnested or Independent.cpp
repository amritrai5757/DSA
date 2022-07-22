When u want to check all subarrays.
Tc:n^2 
// Word break  & Palindrome Partitioning

int f(int i,int n,string &str,vector<int>&dp){
    if(i==n) return 0;
    if(dp[i]!=-1)return dp[i];
    dp[i]=INT_MAX;
    
    for(int j=i;j<n;j++){
        if(palindrome(i,j,str))  // For word break : if(s.find(s.substr(i, j-i+1))!= s.end()){.. 
           dp[i]=min(dp[i] , 1 + f(j+1,n,str,dp));
     }
     return dp[i];
}

int solve(string str){
    int n=str.size();    // For word break store all words dictionary in a set<int>s 
    vector<int>dp(n,-1);
    return f(0,n,str,dp) -1;
}


Tabulation :
int solve(string str){
        int n=str.size();
        vector<int>dp(n+1,0);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
              dp[i]=INT_MAX;
              for(int j=i;j<n;j++){
                  if(palindrome(i,j,str)  // For word break : if(s.find(s.substr(i, j-i+1))!= s.end()){..
                      dp[i]=min(dp[i] , 1+ dp[j+1]);        
              }
         }
         return dp[0]=1;
}
