//Taking a random element as pivot and placing all element lesser than that behind it and greater in front of it. (divide and conquer)
//t.c=average=o(n*logn), worst=o(n^2)   s.c=o(logn)

void partition(int arr[], int left, int right,int &pivotpos){   //Dutch national flag algorihtm tc=o(n) sc=o(1) 
        int pivot=arr[right];//Considering last element of array as pivot 
        int mid=left;
        while(mid<=right){
            if(arr[mid]<pivot) swap(arr[mid++],arr[left++]);
            else if(arr[mid]==pivot) mid++;                    //For 3way partitioning i.e, [0-pivot] comes first & [pivot-pivot2] 2nd & lastly all remaining :(a[mid]>=pivot && a[mid]<=pivot2)    For 012 sorting pivot=1  
            else swap(arr[mid],arr[right--]);
        }
        pivotpos=mid-1;
}
    
void sort(int arr[],int left, int right){
        if(left>right)return;
        int pivotpos;
        partition(arr,left,right,pivotpos);
        sort(arr,left,pivotpos-1);
        sort(arr,pivotpos+1,right);
}
