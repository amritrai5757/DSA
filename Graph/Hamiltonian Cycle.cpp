Hamiltonian cycle is in undirected while toposort is in directed
just like toposort we can visist each node once but in hamilto cycle there must be a path between last & first node


bool isSafe(int v, bool graph[V][V],int path[], int pos){
    if (graph [path[pos - 1]][ v ] == 0)
        return false;
        
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
 
    return true;
}
 
bool hamCycleUtil(bool graph[V][V],int path[], int pos){
    if (pos == V){
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }
    for (int v = 1; v < V; v++){
        if (isSafe(v, graph, path, pos)){
            path[pos] = v;
            if (hamCycleUtil (graph, path, pos + 1) == true)
                return true;
          
            path[pos] = -1;
        }
    }
 
    return false;
}
 
bool hamCycle(bool graph[V][V]){
    int *path = new int[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;
 
    path[0] = 0;
    if (hamCycleUtil(graph, path, 1) == false ){
        cout << "\nSolution does not exist";
        return false;
    }
 
    printSolution(path);
    return true;
}








TRavelling Salesman Problem : also done on adjacency matrix  DIFFEEEENCE : in tracelling we know there is a sol in hamiltonian we find if there is solution

void tsp(int graph[][V], vector<bool>& v, int currPos, int n, int count, int cost, int& ans){
    if (count == n && graph[currPos][0]) {
        ans = min(ans, cost + graph[currPos][0]);
        return;
    }
 
    for (int i = 0; i < n; i++) {
        if (!v[i] && graph[currPos][i]) {
            v[i] = true;
            tsp(graph, v, i, n, count + 1,
                cost + graph[currPos][i], ans);
            v[i] = false;
        }
    }
}
