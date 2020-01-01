/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/
//中序遍历的非递归写法




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
    vector<int> inorderTraversal(TreeNode *root) 
    {
        vector <int> result;
        TreeNode *pCurrent = root;
        stack <TreeNode*> s;
        
        while (!s.empty() || pCurrent)
        {
            if (pCurrent)
            {
                s.push(pCurrent);
                pCurrent = pCurrent->left;
            }
            else
            {
                pCurrent = s.top();
                s.pop();
                result.push_back(pCurrent->val);
                pCurrent = pCurrent->right;
            }
        }
        
        return result;
        
    }
};
