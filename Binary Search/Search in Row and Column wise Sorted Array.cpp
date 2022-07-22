Time complexity =o(n)
int i=0;
int j=m-1;//m*n matrix
pair<int,int>ans;
while(i>=0 && j>=0){
  if(arr[i][j]==x){ans={i,j};return;}
  else if(arr[i][j]>x)j--;
  else i++;
}
return -1;
