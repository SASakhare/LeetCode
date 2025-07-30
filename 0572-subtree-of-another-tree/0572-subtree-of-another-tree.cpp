/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool isSameTree(TreeNode * root,TreeNode * subRoot)
    {
        // base case :
        if(!root || !subRoot)
        {
            return root==subRoot;
        }

        // recursive case :
        if(root->val!=subRoot->val)
        {
            return false;
        }

        if(!isSameTree(root->left,subRoot->left))
        {
            return false;
        }

        return isSameTree(root->right,subRoot->right);
    }

    bool findRoot(TreeNode * root,TreeNode * subRoot)
    {
        if(!root )
        {
            return false;
        }

        // recursive case :
        if(root->val==subRoot->val && isSameTree(root , subRoot))
        {
            return true;
        }

        if(findRoot(root->left,subRoot))
        {
            return true;
        }
        
        return findRoot(root->right,subRoot);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(root==subRoot)
        {
            return true;
        }

        return findRoot(root,subRoot);
    }
};