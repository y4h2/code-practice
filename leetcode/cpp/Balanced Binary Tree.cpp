/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/

//记住，一个函数只完成一个功能
//84ms
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
    bool isBalanced(TreeNode *root) 
    {
        if (root == NULL) return true;
        int l = deepCount(root->left), r = deepCount(root->right);
        
        
        return abs(l - r) <= 1 && isBalanced(root->left) && isBalanced(root->right);
        
    }
    int deepCount(TreeNode *root)
    {
        if (root == NULL) return 0;
        return max(deepCount(root->left), deepCount(root->right)) + 1;
    }
};

//把1放入max内部， 60ms

class Solution {
public:
    bool isBalanced(TreeNode *root) 
    {
        if (root == NULL) return true;
        return abs(maxHeight(root->left) - maxHeight(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
    
    int maxHeight(TreeNode *root)
    {
        if (root == NULL) return 0;
        return max(maxHeight(root->left) + 1, maxHeight(root->right) + 1);
    }
};
