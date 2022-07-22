vector<vi>dis;
vector<vi>par;
vector<vector<vi>>path;

void floyd(){
    dis.resize(n,vi(n));
    par.resize(n,vi(n));
    path.resize(n,vector<vi>(n));
    forr(i,0,n-1){
        forr(j,0,n-1){
            dis[i][j] = g[i][j];
            if (i==j)par[i][j] = 0;
            else if (dis[i][j] != INT_MAX) par[i][j] = i;
            else par[i][j] = -1;
        }
    }

    forr(i,0,n-1)
        forr(j,0,n-1)
            forr(k,0,n-1)
                if (dis[j][k] > dis[j][i] + dis[i][k] ){
                    dis[j][k] = dis[j][i] + dis[i][k];
                    par[j][k] = par[i][k];
                }
            
    forr(i,0,n-1)if(dis[i][i]<0)cout<<"Neg cycle from i";

    forr(i,0,n-1)
        forr(j,0,n-1){   
            int k=j;
            while(k!=i){
                path[i][j].pb(k);
                k= par[i][k];    
            }
            path[i][j].pb(i);
            reverse(path[i][j].begin(),path[i][j].end());
        }
}
