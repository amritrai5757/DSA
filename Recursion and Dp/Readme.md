ALways check if(i-1)>0 so that avoid errror of grid[i][j]+ fdf






👉Write boundry conditions i,e variable value either at starting or before calling recursion or half at starting & half before calling recursion. 

eg : if(i<0 && mat[i][j]==0)return;   

eg : if(vis[i]==0) dfs();

👉Write base condition i,e static value where to return something. eg: if(i==0)return 0;

👉Marking visited & backtracking for checking all possible solutions -:

  •In graph represent as adjacency && in matrix path (directions)finding list u can only mark visited in starting i,e before for loop && unmark it for backtracking to get all solutions after loop ends.
  
  Else if u will not mark firstly it will go again to its own vertex. Since for (all child)

  •In normal matrix like chessboard & in graph represented as matrix u can only mark visited inside the loop && unmark it for backtracking also inside the loop.
  
  Because if u mark it firstly outside it will check  for(i=0 to n rows) then whole 0th row will be not itracted . Since it is marked.
      
  •In rest question you can either outside loop or inside loop


👉Permutation & Matrix combinationn/permutation matrix repre asgraph does not depend on whats upper can come again  to place a thing is similar & 
but in combination & path (both matrix, graph & tree)depends on upper

👉Checking visited inside loop is fixed in matrix combination & graph represented as matrix only but we check in normal graph(adjacency list) as well. 


👉 In comination subset eg:knapsack u need to check before calling if(wt-wiei >0) becuae erroe if push_back(temp[i]) & only 

& so u can  return in starting only on i==0 push-back + return  not if(i<0) return

👉whenever u write int funt in binary tree all memoization & tabulation is also possibile becuae of it u need to return at last something of function like in binary tree & combination subset

