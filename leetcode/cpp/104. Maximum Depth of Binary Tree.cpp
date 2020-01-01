// 44ms
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) 
    {
        if (root == NULL) return 0;
        return 1 + max (maxDepth(root -> right), maxDepth(root -> left));
    }
};

//第二次做 20ms
//改动把1放在括号中
class Solution {
public:
    int maxDepth(TreeNode *root) 
    {
        int height = 0;
        if (root == NULL) return 0; 
        return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
    }
};

// BFS
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        // if (root->left == NULL && root->right == NULL) return 1;
        queue<TreeNode *> q;
        int depth = 0;
        int cnt = 1; // 记录队列里面每一层上的元素
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            --cnt;
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
            
            if (cnt == 0) {
                ++depth;
                cnt = q.size();
            }
        }
        
        return depth;
    }
};
