// if(i==nums.size()){ans.push_back(temp);return;} dont use i>nums.size return otherwise when i==nums.size  temp.push_back(nums[i]) error
// In min no of coins val[i] becomes 1 forever

// Start from n-1 for normal subset printing problems & -1 everthing accordingly.
// U can start recursion from n-1 for printing all subsets for simplicity because u wont be able to convert that recursive code in dp.
int f(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector<int>>& dp){
    if(ind<0 || W<0)return 0;                 //Boundry conditions
    if(ind == 0 || W==0 )return 0;            //Base condition But in unbounded : if(ind==0||W==0) return (W==0)?0:INT_MAX;
    
    if(dp[ind][W]!=-1) return dp[ind][W];
    // if(i<(nums.size()-1) && nums[i]==nums[i+1] && (!pre))  return; //pre to check wheter we took or not previous element// Sort the array first if it could have dulplicate
    
    dp[ind][W]=INT_MIN;
    dp[ind][W] = max(dp[ind][W] , f(wt,val,ind-1,W,dp)); 
    if(W>=wt[ind-1])                                  //Boundry conditions
        dp[ind][W] = max(dp[ind][W] , val[ind-1]+f(wt,val,ind-1,W-wt[ind-1],dp));  // for unbounded  : f(ind ,W..) 
        
    return dp[ind][W];
}


int solve(vector<int> wt, vector<int> val, int n, int W) {
    vector<vector<int>> dp(n+1,vector<int>(W+1,0));
    return f(wt, val, n, W, dp);
}


Tabulation:

int f(vector<int>wt,vector<int>val,int n,int maxWeight){
     vector<vector<int>>dp(n+1,vector<int>(maxWeight+1,0));
     for(int ind=0;ind<=n;ind++){
          for(int W=0;W<=maxWeight;W++){
               if(ind==0 || W==0) dp[ind][W]=0;
               else {
                   dp[ind][W] = INT_MIN;  // always write else
                   dp[ind][W] = max(dp[ind][W], dp[ind-1][W]);  
                   if(W>=wt[ind-1])
                      dp[ind][W] = max(dp[ind][W], val[ind-1] + dp[ind-1][W-wt[ind-1]]); //dp[ind][..] for unbounded
               }
           }
     }
     return dp[n][maxWeight];
}



//No of subsets for given sum     [note: Number of permutations is not equal to number of combinations but permutations with max/min sum = combination with max/min sum = subsequence with max/min sum ]
//For min diff between 2 subset of a set : do the dp & then run a loop (j=sum/2 to 0) to find greatest j whose sum is present
// Combination : Order of elements arranged doesnt matters. So same elements with different arrangement doesnt come again.        Permutation: Order matters
// eg : DP : no of combination of unbouded coins [1,2] suming 4 = 3   (1111 112 22)




// Rule : For bounded: If elements of input array may have same elements eg: 112, u cant remove them like , u have to necessarily use if(i>c && cand[i]==cand[i-1])continue; i,e 112 will be formed only 1 time in combination
//         eg:If frequency of element given(how much times elements has occured) it comes under bounded & use if(i>c&&..) to avoid duplicates
// Rule : For unbounded: All elements must be necessarily be unique. No question till now of unbounded asked with similar elements but if asked remove duplicate elements before recursive code.
//         eg: comb of unbounded [1,1,2] remove all same elements before running unbounded comb recursive code i,e it becomes unbounded comb of [1,2]
