LONGEST INCREASING SUBSEQUENCE :
// Count of LIS asked mostly i,e if LIS is 4 then what is no of increasing subsequences with size 4. NOTE :Count of increasing subsequences never asked. So dont do it


int solve(int arr[], int n){
    vector<int>dp(n,1);             
                                    // To count LIS : vector<int>cnt(n,1);
                                    // To print LIS : vector<int>par(n);
    int ans = 1;
                                    // To print LIS : int k=0;
    for (int i = 0; i < n; i++){
                                    // To print LIS : par[i]=i;
        for (int j = 0; j < i; j++){
            if (arr[i] > arr[j] && dp[i]<(1+dp[j])){
                dp[i] = 1+dp[j];
                                    // To print LIS : par[i]=j;
                                    // To count LIS : cnt[i]=cnt[j];
            }
                                    // To count LIS : else if (arr[j]<arr[i] && 1+dp[j]==dp[i]) {cnt[i]+=cnt[j];}  //another found with same sum as previous
        }
        if(dp[i]>ans){
            ans=dp[i];
                                    // To print LIS : k=i;
        }
    }
    return ans;
    // To print LIS:
    // vector<int>temp;
    // temp.push_back(arr[k]);
    // while(par[k] != k){
    //     k=par[k];
    //    temp.push_back(arr[k]);
    // }
    // reverse(temp.begin(),temp.end());
    
    // To count LIS :
    // int totalLIS=0;
    // for(int i=0;i<n;i++)if(dp[i]==ans) totalLIS+=cnt[i];
}







//Binary Search : U can only find length of LIS , u cant print it & u cant find count of all LIS (tc:nlogn)

int solve(int arr[],int n){
  vector<int>temp;
  temp.push_back(arr[0]);
  for(int i=1;i<n;i++){
    if(arr[i] > temp[temp.size()-1] )
      temp.push_back(arr[i]);
    else{
      int ii = lower_bound(temp.begin(),temp.end(), arr[i] ) -temp.begin();
      temp[ii]=arr[i];
    }
  }
  return temp.size();
}
      

// Longest Bitonic Subsequence (Subsequence which first increases & then decreases) : 
             Find LIS till each element of array & then find LIS of each element by reversing the array.
             Then for each element sum up their LIS of both normal array & revesed array & element having max sum has max bitonic subsequence.

NOTE : If question asked longest subset of anything firstly sort the array. Else if asked subsequence dont sort the array.
// Largest Divisible Subset (Subset whose every element are gives remainder 0 when divided a%b=0) :
            Sort the arr. Then inside code to print LIS, instead of checking if(arr[i]>arr[j] && dp..) check if(arr[i] % arr[j]==0 && dp..)

// Longest String Chain Subset(chain in which adding 1 char in prev string makes cur string): 
             Sort the array using customized compare function. In code of LIS, instead of checking if(arr[i]>arr[j] && dp..) , check if((checkpossible(arr[i],arr[j])) && dp..) ,where 
             bool checkpossible(string &s1,string &s2){
                 if(s1.size() !=s2.size()+1) return false;
                 int i=0,j=0;
                 while(i<s1.size()){
                    if(s1[i]==s2[j]){i++,j++;}
                    else i++:
                 }
                 if(i==s1.size() && j==s2.size()) return true;
                 return false; 
             }
