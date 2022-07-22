// MST is only possible in undirected graph .SInce tree is only undirected ascylic graph
// tc = o((e+v)logv) because it is dijkstra algo with backtracking
vi par;
vi dis;

void prim(int s){
    par.resize(n+3,-1);
    dis.resize(n+3,inf);
    priority_queue<pii,vector<pii>,greater<pii>> pq;  //Minheap : Sorting in Ascending order
    vi inMST(n+3,0);
    
    pq.push({0,s});
    dis[s]=0;

    while(pq.size()){
        int c = pq.top().second;
        pq.pop();
        if(inMST[c] == 1)continue;
        inMST[c] = 1;
        for(auto i:g[c]){
            if (inMST[i.first] == 0 && dis[i.first] > i.second){  //Since its a tree we dont check dis[i.first]>i.second+ c because then it may find shortest path but with cycle.
                dis[i.first] = i.second;                          
                pq.push({dis[i.first], i.first});
                par[i.first]=c;
            }
        }
    }
    int totalweight=0;
    forr(i,1,n-1){
        if(dis[i]==inf){cout<<"No MST because Graph is disconnected";return;}
        totalweight+=dis[i];
        cout<<i<<"connectedTo"<<par[i];
    }
}
