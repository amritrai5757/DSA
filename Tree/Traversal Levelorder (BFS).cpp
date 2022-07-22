// (BFS)Level Order traversal(right,left view):o(n) using BFS :Normal level order,Reverse level order,zig zag/spiral,max width of tree,height of tree(iterative)==totalLevels.  


vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans; 
        if(!root) return ans; 
        queue<Node*> q; 
        q.push(root); 
        while(q.size()) {
            int size=q.size();  //Since q.size() will keep on changing in for loop
	    //leftview.push_back(q.front());  rigthview.push_back(q.back());  For right or left View using Bfs
            vector<int>level;
            for(int i = 0;i<size;i++) {  // If u dont want separation of each level just wanted nodes in levelorder traversal u can ignore this line
                Node *c = q.front();                     
                q.pop();                                    
                level.push_back(c->val);                
                if(c->left) 
			q.push(c->left);         
                if(c->right) 
			q.push(c->right);                
            }
            //if(ans.size()%2==1)reverse(level.begin(),level.end()); For zig zag/spiral level order
            ans.push_back(level); 
        }
        //reverse(ans.begin(),ans.end()); For Reverse level order
        return ans; 
}


                               // Use case of Level order algorithm:-Max width of binary tree:o(n) 
                               int width(Node* root){
                                    if(!root)return 0;
    	                            queue<pair<Node*, int>> q;
    	                            q.push({root, 0});
    	                            int ans = 1;
    	                            while(q.size()){
		                        ans = max(ans, q.back().second-q.front().second+1);
    		                        int size = q.size();
    		                        for(int i = 0; i<size; i++){
    			                     Node* c = q.front().first;                  
    			                     int n = q.front().second;                      
    			                     q.pop();                                     
    			                     if(c->left)q.push({c->left, n*2});       
    			                     if(c->right)q.push({c->right, n*2+1});    
    		                         }
    	                            }	
    	                            return ans;   
                                }

