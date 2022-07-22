//Comparing and swapping neighbouring elements. After every iteration largest element from unsorted/left part goes behind sorted part of array.
//t.c=o(n^2) s.c=o(1)
for(int i = 0; i< n-1; i++)
    for(int j = 0; j < n-i-1; j++) 
        if(A[j] > A[j+1] ) {
           temp = A[j];
           A[j] = A[j+1];
           A[j+1] = temp;
         }
