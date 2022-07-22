//Selecting & swapping smallest element of unsorted/right part of array with the 1st element of unsorted array. [trick: sss:selection swapping smallest]
//t.c=o(n^2) s.c=o(1)
for(int i = 0; i < n-1 ; i++)  {
    minimum = i ;
    for(int j = i+1; j < n ; j++ ) {
        if(A[ j ] < A[ minimum ])  { //finds the minimum element
        minimum = j ;
        }
    }
    swap (A[minimum], A[i]) ; 
}
