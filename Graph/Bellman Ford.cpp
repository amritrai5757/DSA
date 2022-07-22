//edges.pb({a,b,w});
int s=0;
vi dis(n+3,inf);
vi par(n+3,-1);
vector<vi>path(n+3);
dis[s]=0;
forr(i,s,n-1)
    for(auto i:edges){
        if(dis[i[0]]!=inf && dis[i[1]] >dis[i[0]]+i[2]){
            dis[i[1]] = dis[i[0]]+i[2];
            par[i[1]] = i[0];
        }
    }

int cycle=0;
for(auto i:edges)
    if(dis[i[0]]!=inf && dis[i[1]] >dis[i[0]]+i[2]){
        cycle=1;break;
    }

if(cycle)cout<<"Neg cycle found.No path from s to any node";
else{
    forr(i,0,n-1){
        int j=i;
        while(j!=-1){
            path[i].pb(j);
            j=par[j];
        }
        reverse(path[i].begin(),path[i].end());
    }
}
