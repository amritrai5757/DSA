//Everything is same as level order traversal except:-
//    In levelorder we only go down level. So no chance of revisiting same node. But here we are traversing like graph. So make : map<Node*,bool>vis; if(c->left && !vis[c->left]
//    Map nodes with their parent by using map<Node*,Node*>par  & add another condition inside loop if(par[c] && vis[par[c]])q.push(par[c])

//Use unordered_map to reduce insertion cost to o(1) worst(o(n) & serching cost to o(1) worsto(n) since it uses hashing unlike red black tree in map
//Burning tree :  


Node* search(Node*root,int &target){
        if(!root)return NULL;
        if(root->data==target){
            return root;
        }
        Node* left=search(root->left,target);
        Node* right=search(root->right,target);
        if(left)return left;
        if(right)return right;
        return NULL;
}
    
void dfs(Node*root,map<Node*,Node*>&par){
        if(!root)return;
        if(root->left)par[root->left]=root;
        if(root->right)par[root->right]=root;
        dfs(root->left,par);
        dfs(root->right,par);
}
    
int minTime(Node* root, int target) {
        
        map<Node*,Node*>par;
        dfs(root,par);    // For linking all nodes with its parent nodes
        Node* newroot=search(root,target); // For searching the target and returning it in form of Node*. Note: if target is already given as Node* in question no need to search.
        root=newroot;
        
        map<Node*,bool>vis;
        vis[root]=1;
        queue<Node*>q;
        q.push(root);
        int ans=0;
        while(q.size()){
            int size=q.size();
                                            // For returning all nodes at distance k : if(ans==K) break;
            ans++;                     
            for(int i=0;i<size;i++){
                Node*front=q.front();
                vis[front]=1;
                q.pop();
                if(front->left && !vis[front->left]){
                    q.push(front->left);
                    vis[front->left]=1;
                }
                if(front->right && !vis[front->right]){
                    q.push(front->right);
                    vis[front->right]=1;
                }
                if(par[front] && !vis[par[front]]){   
                    q.push(par[front]);
                    vis[par[front]]=1;
                }
            }
        }
        return --ans;
        
       // For all nodes at distance at k :-
//         vector<int>res;
//         while(q.size()){
//                 res.push_back(q.front()->val);
//                 q.pop();
//         }
        
        
}
