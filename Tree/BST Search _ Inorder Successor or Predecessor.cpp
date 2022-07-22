Q; Given a bst .Find succesor of given element according to its inorder traversal.
//Searching : tc:o(h)  sc: o(1) 
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = NULL;
        while (root) {
            if (p->val >= root->val)
                root = root->right;
            else {
                successor = root;
                root = root->left;
            }
        }
        return successor;
}
