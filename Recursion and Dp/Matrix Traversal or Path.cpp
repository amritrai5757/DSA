// In recursion of matrix validity is checked first unlike graph & all directions are written separetly to easilly convert them into tabulation.
// IN reursion intialisze dp with -1 & in tabulation with 0.
// If asked about min or max path sum to reach from a cell to another cell, then grid values is considered as cost like in knapsack.

int f(int i,int j,vector<vector<int>>&dp){
   if(i==0 && j==0)return 1; //For min/max path sum : return mat[i][j]// Fpr any row to anu colum : either if(i==0) or if(j==0) as per que
   //int temp= grid[i][j]; grid[i][j]=0; 
   if(dp[i][j]!=-1) return dp[i][j];
   int up=0,left=0;
   if(i-1>=0 && j>=0 && mat[i-1][j]!=-1)up=f(i-1,j,dp) ;  // For : min/max path sum : f(i-1,j..) + mat[i][j] 
   if(i>=0 && j-1>=0 && mat[i][j-1]!=-1)left=f(i,j-1,dp); // For : min/max path sum : f(..) +mat[i][j]
  
   //grid[i][j]=temp; // 1  2  3  If dfs is running from 1. If we dont use it : if its visited path 1->2->5->8 ,it will not visit any path in which any of this nodes come like 1->2->3
                         // 4  5  6     Basically it will become code for checking whether graph is connected or not i,e once a node visited,we dont visit it again.
                         // 7  8  9  To check all paths coming from node 1, we maintain all nodes in its original state after using it. So now u can check 1->2->3 even after visting 1->2->5->8.
                         // Note: U cant use this code with every dfs to maintain matrix because every dfs dont check each paths eg: code for checing connected graph or not.
   
  return dp[i][j]=up+left;
}

int solve(int m,int n){
  vector<vector<int>>dp(m,vector<int>(n,-1));
  //if Asked max/min path from any node of 1st row/colum to any node of last row / colum
  // just run this loop till row acordin to que for(i -0 ton n-1) (max(ans,f(m-1,n-1,dp)) no reinst of dp same dp & same time compl o(nm) magic
  return f(m-1,n-1,dp);  
}


//READ BINARY SEARCH FOR THIS AFTER RECURSION AND DP DONE

// Tabulation : Write two for loops 0 to m-1 & 0 to n-1 & copy whole recursion inside it & ignore boundry conditions like if(i<0) because loop will run till inside for loop only,no need to check it.
//For any non cyclical traversal whose traversal is other or more than right & down : use simple recursion & memozise it
//Non cyclical directions means once a cell is visited is impossible to visit it again
//     eg:1)mover can move only in 2 direction right and down.
//        2)mover can move only in any 4 direction right,down,diagonal between right & downward and diagonal between upward and right.
//This algorithm is used for : 1) Printing the max/min emerging from 1 cell to a target where movement is non cylical
//                             2) Total ways to reach target from 1 cell where movement is non cylical
//PATH QUE CAN NEVER ASK PERMUTATION. ex; 1->2->3 you cant permute it like first go 3 then 1 then 2 (3->1->1)wrong  

int solve(int m,int n){
  vector<vector<int>>dp(m,vector<int>(n,0));
  for(int i=0;i<m;i++){
    for(int j=0;i<n;j++){
      if(mat[i][j]==-1)dp[i][j]=0;
      else if(i==0 && j==0) dp[i][j]=1; //=grid[i][j]
      else{
        int up=0,left=0; //For min/max : up=grid[i][j],left=grid[i][j]
        if(i>0)up+=dp[i-1][j];
        //For min/max : else up+= /= INT_MAX;
        if(j>0)left+=dp[i][j-1];
        //For min/max : else left+= /= INT_MAX;
        dp[i][j]=up+left;//For min/max : min(left,up)
      }
    }
  }
  return dp[m-1][n-1];
}






// Dfs is used for 1)For printing all paths emerging from 1 cell whether movement is cyclical or non-cyclical.
//                 2)For finding min/max path emerging from a cell,if movement is cyclical i,e once visisted cell can be visted again by mover. [note: This can be done by dp using map in same tc as dfs but too hectic]
// For any dp which whose has other than right & down use simple memoziation
