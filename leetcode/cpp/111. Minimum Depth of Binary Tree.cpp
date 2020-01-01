/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/
//level-order traversal and record current level depth, when meet a node which both child is null then return, no need to go farther


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
    int minDepth(TreeNode *root) 
    {
        int depth = 0;
        if (root == NULL) return depth;
        
        TreeNode * pCur;
        queue <TreeNode *> cur, next;
        cur.push(root);
        ++depth;
        while (!cur.empty())
        {
            pCur = cur.front();
            cur.pop();
            if (pCur->left ==NULL && pCur->right == NULL )
                break;
            if (pCur->left != NULL)
                next.push(pCur->left);
            if (pCur->right != NULL)
                next.push(pCur->right);
            
            if (cur.empty())
            {
                ++depth;
                swap(cur, next);
            }
                
        }
        
        return depth;
        
    }
};

// DFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL || root->right == NULL)
            return max(minDepth(root->left) + 1, minDepth(root->right) + 1);
        
        return min(minDepth(root->left) + 1, minDepth(root->right) + 1);
    }
};


// BFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 1, depth = 0;
        
        while(!q.empty()) {
            TreeNode* temp = q.front();
            --cnt;
            q.pop();
            
            if (temp->right == NULL && temp->left == NULL)
                break;
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
