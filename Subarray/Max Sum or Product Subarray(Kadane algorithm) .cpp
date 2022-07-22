int maxSubArray(vector<int>& nums) {
        int MAX = INT_MIN;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            MAX = max(sum, MAX);
            if(sum < 0) sum = 0;
        }
        return MAX;
}


//In max product subarray : You need to maintain both min subarray and max subarray because min can max if any another neg is multiplied with it.
int maxProduct(vector<int>& nums) {
        int minn=1,maxx=1,ans=INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0)
                swap(minn,maxx);
                
            maxx=max(nums[i],maxx*nums[i]);
            minn=min(nums[i],minn*nums[i]);
            ans=max(ans,maxx);
        }
        return ans;
}
