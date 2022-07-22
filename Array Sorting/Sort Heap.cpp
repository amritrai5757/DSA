//Tc=o(n*logn=> n*logk)  n for loop and logk for sorting caz there are only k elements in heap
//MINHEAP sorts in ascending order
vector<int> sort(vector<int>arr,int k){
    vector<int>ans;
    priority_queue<int, vector<int>,greater<int>> minheap;         //priority_queue<int> maxheap for sorting in descending order or for kth smallest
    for(int i=0;i<arr.size();i++){
        minheap.push(arr[i]);
        if(minheap.size()>k){ans.push_back(minheap.top());  minheap.pop(); }  //Removing this line will completely sort arr in nlogn //In k sorted array we know that when heap size exceeds k size the smallest must be at top
    }
    //Here minheap.top() gives kth greatest element
    while(minheap.size()){
        ans.push_back(minheap.top());  minheap.pop();
    }
    return ans;
}



Print k closest numbers to given number: priority_queue<pair<int,int>>  and  maxheap.push({abs(arr[i]-x),arr[i]});
Top k most frequent element Frequency sort: map[i]++;  minheap.push({i->second,i->first});
Print k closest points from origin:  priority_queue<pair<int, pair<int,int>>maxheap;    maxheap.push({arr[i][0]*arr[i][0]+arr[i][1]*arr[i][1] , {arr[i][0],arr[i][1]}};   //dis of point (x,y) from (0,0)=root(x^2 +y^2)

