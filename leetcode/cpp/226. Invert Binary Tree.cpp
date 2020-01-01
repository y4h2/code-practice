//DFS

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;
        swap(root->right, root->left);
        invertTree(root->right);
        invertTree(root->left);
        
        return root;
    }
};

//BFS
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;
        
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            
            swap(temp->right, temp->left);
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
            
        }
        
        return root;
    }
};
