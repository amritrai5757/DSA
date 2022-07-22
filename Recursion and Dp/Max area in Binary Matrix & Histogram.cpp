Stock Span :No of consecutive days for which stocks were smaller or equal to current days price = Index of current day-NGL INDEX
vector<int> NextGreaterLeft(vector<int> nums,int n){
        stack<pair<int,int>> s;        
        vector<int> res(n); 
        for(int i=0; i<n; i++){              
            while(s.size() && s.top().first() <= arr[i])  s.pop();          
            if(!s.size())  res[i]=-1;
            else res[i]=s.top().second(); //Storing index instead of value 
            s.push({arr[i],i});
        }                                                      
        for(int i=0;i<n;i++) res[i]=i-res[i];   //Index of current day-NGL INDEX
        return res;
}











Next greater or smaller to left or right


vector<int> nextLargerElementtoright(vector<int>nums, int n){
        stack<int> s;        
        vector<int> res(n);
        for(int i=n-1; i>=0; i--){                            //For left for(i=0 to n-1)
            while(s.size() && s.top() <= nums[i]) s.pop();    //For smallest s.top()>= nums[i]
            if(!s.size()) res[i]=(-1);
            else res[i]=(s.top());
            s.push(nums[i]);
        }
        return res;
}

















Rain water trapping


int solve(vector<int>& height,int n) {
           int ans = 0;
           vector<int> leftmax(n);
           vector<int> rightmax(n);
           leftmax[0] = height[0];
           rightmax[n-1] = height[n-1];
  
           for(int i=1;i<n;i++)   left[i] = max(leftmax[i-1],height[i]);
           for(int i=n-2;i>=0;i--)right[i] = max(rightmax[i+1],height[i]);
                  
           for(int i=0;i<n;i++) ans += min(leftmax[i],rightmax[i]) - height[i];
           return ans;
}









//  Max AreaorReactangle in Binary Matrix & Histogram.cpp


//You dont need to store nsr rather store nsr index in stack and vector
vector<int> nsr(vector<int> heights, int n){
        vector<int> res(n);
        stack<int> st;      
        for(int i=n-1; i>=0; i--){
            while(st.size() && heights[st.top()]>=heights[i])st.pop();
            if(st.empty())res[i] = -1;
            else res[i] = st.top();
            st.push(i);
        }
        return res;        
}

vector<int> nsl(vector<int> heights, int n){
        vector<int> res(n);
        stack<int> st;       
        for(int i=0; i<n; i++){
            while(st.size() && heights[st.top()]>=heights[i])st.pop();
            if(st.empty())res[i] = -1;
            else res[i] = st.top();
            st.push(i);
        }
        return res;        
}

int MaxAreaInHistogram(vector<int>& heights) {
        int n = heights.size();        
        vector<int> left(n), right(n);
        right = nsr(heights,n);
        left = nsl(heights,n);

        int res = INT_MIN;        
        for(int i=0; i<n; i++){
            if(left[i]==-1) left[i]= -1;
            if(right[i]==-1) right[i]= n;
            
            int w = right[i]-left[i]-1;
            res = max(res,heights[i]*w);
        }        
        return res;
}


//MaxAreaInBinaryMatrix: THIS QUESTION SO LONG THAT IT WILL RARERLY COME IN INTERVIEWS As it uses histograms code also:-
int MaxAreaInBinaryMatrix(vector<vector<int>>&matrix){
        int n=matrix.size(),m=matrix[0].size();
        for(int i=1;i<n;i++)
            for(int j=0;j<m;j++)
                if(matrix[i][j])     
                  matrix[i][j] += matrix[i-1][j];

        int ans = 0;
        for(int i=0;i<n;i++) ans = max(ans, MaxAreaInHistogram(matrix[i]));   //Calculating ans for all n Histograms
        return ans;
}
