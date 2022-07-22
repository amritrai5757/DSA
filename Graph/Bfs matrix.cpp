void bfs(int sf,int ss){
queue<pii>q;
q.push({sf,ss});
g[sf][ss] = true;
while (q.size()) {
    pii c = q.front();
    q.pop();

    for(auto i:path){
        int a = c.first + i[0];
        int b = c.second + i[1];
        if(vis(a,b)==0) {
            q.push({a,b});
            g[a][b] = true;
        }
    }
}
}
