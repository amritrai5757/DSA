vi dis;
//IF(dis[i]==MAX) NO PATH
//vector<vector<pii>>g;
void topomain(int cnode ,vi vis, stack<int> &st){
    vis[cnode] = 1; 
    aa(it,g[cnode]){
        if(!vis[it->first]) {
            topomain(it->first, vis, st); 
        }
    }
    st.push(cnode);
}


void solve(int s){
        vi vis(n);
	stack<int> st; 
	forr(i,0,n) 
		if (!vis[i]) 
			topomain(i, vis, st); 
	
	// Same code as dijksta.Only instead of queue we stack & since stack is already filled we will not push new element in stack unlike dijkstra
	dis.resize(n+1,INT_MAX);
	dis[s]=0;
	while(st.size()){  
		int c = st.top(); 
		st.pop(); 
		for(auto i:adj[c]){
		    if( dis[i.first] > dis[c] + i.second) 
		        dis[i.first] = dis[c] + i.second; 
			// You can find the path just like in dijkstra
	        }
	} 
} 
