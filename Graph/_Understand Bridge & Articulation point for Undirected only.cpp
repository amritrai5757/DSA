// Bridges & articulation point can be only done using dfs just like dijkstra algorithm. //[Note : There is only question on articulation point & bridges of undirected graph]

int time=0;
int tin[N];
int low[N];
vector<pii>bridge;                         // For articulation point : bool point[N];
void dfs(int c,int p=-1){
                                           // For articulation point : int child=0;
    vis[c]=1; 
    tin[c]=low[c] = time++; 
    for(auto i: g[c]) {
        if(i == p) continue;
        if(vis[i]==0){
            dfs(i,c); 
            low[c] = min(low[c], low[i]);  
                                           // For articulation point : child++;
            if(low[i] > tin[c])            // For articulation point : if(low[i]>tin[c] && p!=-1)
                bridge.pb({c,i});          // For articulation point : point[c]=1; 
        }
        else
            low[c] = min(low[c], tin[i]);      
    }
                                           // For articulation point : if(p==-1 && child>1) point[c]=1;
}
