vector<vi>greversed;
stack<int>st;

void transpose(){  
    forr(i,0,n-1){
        for(int j:g[i])
            greversed[j].pb(i);
    }
}


void dfs1(int i){ 
    vis[i]=1;
    for(int j:g[i])
        if(vis[j]==0)
            dfs1(j);
    st.push(i);
}


void dfs2(int i){
    cout<<i<<" ";
    vis[i]=1;
    for(int j: greversed[i])
        if(vis[j]==0)
            dfs2(j);
}


void kosaraju(){   
    greversed.resize(n+3);
    transpose();

    forr(i,0,n-1)
        if(vis[i]==0)
            dfs1(i);

    vis.assign(n,0);//To reuse vis in dfs2
    
    int cnt=0;
    while(st.size()){
        int curr = st.top();
        st.pop();
        if(vis[curr]==0){
            cout<<"SCC: ";
            dfs2(curr);
            cout<<endl;
            cnt++;
        }
    }
    if(cnt==1){
        cout<<"There is only 1 scc, so graph is strongly connected Graph";
    }
}
