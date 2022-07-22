void bfs(int s){
queue<int> q; 
q.push(s);
vis[s] = 1; // In bfs queue intialized first unlike dfs TESTED✔️
while(!q.empty()) {
    int c = q.front();
    q.pop();
    for(auto i:g[c]){
        if(vis[i]==0){
            q.push(i); 
            vis[i] = 1; // In bfs vis[i] is marked here unlike dfs TESTED✔️
       }
    }
}    
}
