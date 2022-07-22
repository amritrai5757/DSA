// FIrst do this at last if problem occurs in shortes common ,min inset delt then again striver dp
// Wildcard matching 
// Wildcard matching 
// Wildcard matching by STTRRIVERRRRRRRRRRRRRRRRR
int f(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        if(i==0||j==0)return 0;    // Base condition
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i-1]==t[j-1])return dp[i][j] = 1+f(i-1,j-1,s,t,dp);//or s[i]==t[j]
        else dp[i][j]=max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));
        return dp[i][j];
}
int lcs(string s,string t){
        int n=s.size(),m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(n,m,s,t,dp);   //If we take n-1,m-1 instead of n,m then it cant be converted into tabulation simply & become hectic.
}


Tabulation:

int lcs(string s,string t){
        int n=s.size(),m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
       //for(int j=0;j<=m;j++)dp[0][j]=0;
        //for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                        if(s[i-1]==t[j-1])dp[i][j]=1+dp[i-1][j-1];
                        else dp[i][j]=max(dp[i-1][j],dp[i][j-1];
                 }
         }
         return dp[n][m];                               
}



                                          
                                          
LONGEST COMMON SUBSEQUENCE OR SUBARRAY OF 2 ARRAYS : tc(o(n*m)  where n=arr1.size() & m=arr2.size()

int lcs(string X, string Y) {
        int m = X.size(),n = Y.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){                                                                                                                                 // SInce we are checking if whole X can be suubsquence of Y
                if(X[i-1] == Y[j-1]) dp[i][j] = dp[i-1][j-1] + 1;                      //For substring after ... + 1 : ans=max(ans,dp[i][j]);    //For total no of occur of X in Y as subsequence : dp[i][j]=dp[i][j-1]+dp[i-1][j-1]
                else dp[i][j] = max(dp[i][j-1]/*insert*/, dp[i-1][j]/*remove*/);       //For substring : dp[i][j]=0;                             //For total no of occur of X in Y as subsequence : dp[i][j]=dp[i][j-1];
                                                                                       //OR here For substring : ans=max(ans,dp[i][j]);          
            }
        }
        return dp[m][n];
}


// Backtracking:
int i=m,j=n; string s;
while(i>0 && j>0){
    if(X[i-1]==Y[j-1]){s.push_back(X[i-1]);i--;j--;}
    else if(dp[i][j-1]>dp[i-1][j])j--; //For shortest common superseq : s.push_back(X[j-1]; j--;
    else i--;                          //For shortest common superseq : s.push_back(Y[i-1]); i--;
}
reverse(s.begin(),s.end());


// Shortest common superseq = x.size()+y.size()-longest common subsequence
// Min no of insertion and deletion to make string x to string y :  insertion(x.size()-lcs)  +  deletion(y.size()-lcs)   lcs:longest common subsequence
// Min no insertion and deletion and replacement to make string x to y:EDIT DISTANCE  for..{for..
                                                                                         //if(i==0)dp[i][j]=j; 
                                                                                         //else if(j==0)dp[i][j]=i;    
                                                                                         //else if(x[i-1]==y[i-1])dp[i][j]=dp[i-1][j-1];
                                                                                         //else dp[i][j]= 1+ min(dp[i][j-1]insert,min(dp[i-1][j]remove,dp[i-1][j-1]replace));
// LPS:Longest palindromic subsequence of an arr : x=a & y=reverse(a);  lcs(x,y)    Follow up que: Min no of deletion to make array palindrom: arr.size()-lps
// Min no insertion and deletion to make string palindrom : no of insertion = no of deletion = s.size()-lps(s)
// LRS:Longest repeting subsequence of an arr : aabbdd =3 abd coming 2times: x=arr,y=arr; lcs(x,y) with restriction if(X[i-1]==Y[j-1] && i!=j).....
// Check if x is a subsequence of y : if(lcs(x,y)==x.size()) cout<<"yes"; 


// REGULAR STRING MATCHING
// class Solution {
//    public boolean isMatch(String s, String p) {

//     boolean[][] dp = new boolean[s.length()+1][p.length()+1];
//     dp[0][0] = true;
//     for (int i = 0; i < p.length(); i++) {
//         if (p.charAt(i) == '*' && dp[0][i-1]) {
//             dp[0][i+1] = true;
//         }
//     }
//     for (int i = 1 ; i <= s.length(); i++) {
//         for (int j = 1; j <= p.length(); j++) {
//             if (p.charAt(j-1) == s.charAt(i-1) || p.charAt(j-1) == '.') {
//                 dp[i][j] = dp[i-1][j-1];
//             }
//             else if (p.charAt(j-1) == '*') {
//                 dp[i][j]=dp[i][j-2];
//                 if (p.charAt(j-2) == s.charAt(i-1) || p.charAt(j-2) == '.')
//                     dp[i][j] = (dp[i][j-1] || dp[i-1][j] || dp[i][j-2]);
//             }
            
//         }
//     }
//     return dp[s.length()][p.length()];
// }
// }
