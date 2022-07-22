//Inserting the 1st element of unsorted/right part to its correct position in sorted part.
//t.c=o(n^2) s.c=o(1)
for( int i = 0 ;i <n ; i++ ) {
      int temp = A[ i ];    
      int j = i;
      while(j>0  && temp<A[j-1]) { //Moving all elements greater than leftmost element of unsorted part 1 position forward.
                A[j] = A[j-1];   
                j--;
      }
      A[j] = temp;       
}  
