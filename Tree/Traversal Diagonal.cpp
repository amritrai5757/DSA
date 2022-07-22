// Diagonal clockwise(upperLeft to LowerRight) and anticlock(upperRight to LowerLeft)wise Order Traversal BFS
// Iterative: // NOTE : ONLY BFS SOLUTION likE dijkstra since dfs will take onlogn.No required to read it.
Clockwise:
void diagonal(Node* root){
    vector<vector<int>> result;
    if(!root)return;
    queue<Node*> q;
    q.push(root);
    while(q.size()){
        int size = q.size();
        vector<int> answer;
        while(size--){
            Node* temp = q.front();
            q.pop();
            while(temp){
                answer.push_back(temp->data);
                if(temp->left)q.push(temp->left);  //if(temp->right)q.push(temp->right);  For anticlockwise
                temp = temp->right;                //temp=temp->left;                     For anticlockwise
            }
        }
        result.push_back(answer);
    }
}
