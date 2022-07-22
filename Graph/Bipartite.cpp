bool bipartite;
void dfs(int c,int p){
    vis[c]=vis[p]%2+1;
    for(auto i:g[c]){
        if(vis[i]==0){
            dfs(i,c); if(bipartite==false)return;  // we dont write this two lines in bfs since bfs is not recursion.
        }
        else if(vis[i] == vis[c]){
            bipartite=false;
            return;
        }
    }
    return; 
}


Dont required to read just convert dfs into bfs according to rules
// BFS :  

// bool bipartite;
// void bfs(int s){
// queue<int> q; 
// q.push(s);
// vis[s] = 1; 
// while(q.size()){
//     int c = q.front();
//     q.pop(); 
//     for(int i:g[c]){
//         if(vis[i]==0){
//            q.push(i); 
//            vis[i] = vis[c]%2+1; 
//         }
//         else if(vis[i]==vis[c]){
//            bipartite=false;return;
//         }
//     }
// }     
// }
