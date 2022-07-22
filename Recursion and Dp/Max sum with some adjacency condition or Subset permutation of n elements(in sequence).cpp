// [note: Number of permutations is not equal to number of combinations but permutations with max/min sum = combination with max/min sum = subsequence with max/min sum ]
// Note : Since it is unbounded no of combinations = no of permutations. eg: Unbounded combination of 1,2 doesn't mean combination of 1..∞ 2..∞ , it means combination of 1..∞,2...∞,1..∞,2..∞..∞. 
//                                                                            So ultimately their is no differnce between unbounded combination and permutation.
// Gives combination/permutation/sequence with respect to max/min cost because because while finding min/max cost u can call it combination/permutation/sequence .
// Cost is similar to knapsack which doesnt contribute to main sum.
// We need to choose between adjacent elements : dp[n] 

// Initialize according to question and your observation
// We need to choose between adjacent elements or 2,3 or 4 choices & also at for each element there is some choice/cost like 2 or 3 choices :dp[n][choices]

//https://www.geeksforgeeks.org/count-minimum-number-of-fountains-to-be-activated-to-cover-the-entire-garden
// https://www.geeksforgeeks.org/count-minimum-number-of-fountains-to-be-activated-to-cover-the-entire-garden/
// Two conditions at each step     /..//??????????????



   eg: Paint house with min cost with any of 3 colors without having same adjacent house same colored. dp[n][3]
   // We need to choose between adjacent or 2,3 or 4 choices & 1 cost at each element : dp[n]
   eg: Max sum when we cant take 2 adjacent elements OR House Robber
       Decode ways : No of ways to decode a string given in number form to alphabet
       Ways of painting the fence such that at most 2 adjacent fences have the same color
          dp[0] = k, dp[1] = k*k;
          for(int i =2; i<n; i++) dp[i] = dp[i-1]*(k-1) + dp[i-2])*(k-1);
       Domino Tiling
   
   
   
// Gives total no combinations/permutations of unbounded elements when element are sequential like 1,2,3...k like n stairs & fibonnic.
// n stairs with steps 1,2,3..k(in sequential order) i,e Total combination/permutations that sum up to n with unbounded element 1,2..k(sequential)
// fibonnic : If u observe it is n stairs with step 1,2. It gives no of combination/permutation that sum up to n with element unbouned 1,2.
int countWays(int n, int k){
    int res[n + 1];
    int temp = 0;
    res[0] = 1;
    for (int i = 1; i <= n; i++){
        int s = i - k - 1;
        int e = i - 1;
        if (s >= 0){
            temp -= res[s];
        }
        temp += res[e];
        res[i] = temp;
    }
    return res[n];
}
