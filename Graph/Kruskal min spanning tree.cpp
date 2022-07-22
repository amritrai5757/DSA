//Tc=o(eloge)   [note: tc=O(eloge)+O(e*4*alpha), Since o(e*4*alpha) is too small it is considered constant. Hence tc=o(eloge)
// We can also use kruskal for cycle detection in graph.

vi par;
vi rankk;

bool compare(vi x,vi y){
    return x[2]<y[2];
}

// if {1,2,3,4} is a disjoint set par[1]=par[2]=par[3]=par[4]=1 or any one element from this set
// makeset is used for making new set which contains single node i,e itself.
void makeSet(int i){//tc:o(1) 
    par[i]=i;
    rankk[i]=1;
}

// findset is used to check whether 2 element belongs to same set or not, we check whether there parent of set are same or not since no 2 or more disjoint set have anything in common
int findSet(int i){ //tc:o(e*4*alpha)=constant mathematically proved
    if(i==par[i]){
        return i;
    }
    return par[i]=findSet(par[i]);
}

// Union of a and b means union of whole set in which a resides with set in which b resides. 
void unionSet(int a,int b){  o(1)=constant mathematically proved  
    a=findSet(a);
    b=findSet(b);
    if(a!=b){
        if(rankk[a]<rankk[b])
            swap(a,b);
        par[b]=a;
        rankk[a]+=rankk[b];
    }
} 

void kruskal(int s){
    par.resize(n+3);
    rankk.resize(n+3);
    
    forr(i,0,n-1)makeSet(i); //intialize all vertices as set containing itself only
    
    sort(e.begin(),e.end(),compare); // tc=o(eloge)
    
    int cnt=0,totalweight=0;
    for(auto i:e){
        if(findSet(i[0]) != findSet(i[1])){  // if including this edge doesnt form cycle
            cout<<i[0]<<"connectedTo"<<i[1]<<"havingWeight"<<i[2]<<endl;
            totalweight+=i[2];
            cnt++;
            unionSet(i[0],i[1]); // join set containing i[0] with set containing i[1]
        }
        // else cycle found by including this edge. So, we will not include this edge. 
    }
    if(cnt!=n-1-s){cout<<"No MST";}
}
