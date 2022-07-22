// Gives all subset of size 3(if 3sum),4(if 4sum) with sum given in que
// When we need to return index of element we use multimap<int,int> otherwise sorting : multimap because there may be 2 same elements

vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        while(nums.size()<4)return result;
        
        for(int i=0;i<nums.size()-3;i++){
            if(i>0 && nums[i]==nums[i-1])continue;

            for(int j=i+1;j<nums.size()-2;j++){ //For 3 Sum
                if(j>i+1 && nums[j]==nums[j-1])continue;
                int left=j+1;
                int right=nums.size()-1;
                
                while(left<right){  //For 2 Sum  2 Pointer. If questions asked only 2 sum u can also use map without sorting to solve in nlogn but in 3,4 sum only sorting
                    int sum=nums[i]+nums[j]+nums[left]+nums[right]; 
                    if(sum==target){
                        result.push_back({nums[i],nums[j],nums[left],nums[right]});
                        while(left<right && nums[left]==nums[left+1]) left++;
                        while(left<right && nums[right]==nums[right-1]) right--;
                        left++;
                        right--;
                    }
                    else if(sum>target) right--;
                    else left++;
                }
            } 
        }
        return result;
}
